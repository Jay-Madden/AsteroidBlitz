#include "../include/Engine.h"

void Engine::initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);

    window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window *)> >(SDL_CreateWindow(windowName.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                screenWidth,
                                screenHeight, 0),
                                SDL_DestroyWindow);
    //SDL_SetWindowFullscreen(window.get(), SDL_WINDOW_FULLSCREEN_DESKTOP);
                            
    
    renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >(
        SDL_CreateRenderer(window.get(), -1, 0),
        SDL_DestroyRenderer);
}

void Engine::startGameLoop(){
    SDL_Event event;
    is_running = true;
    while (is_running) {

        SDL_RenderClear(renderer.get());
        SDL_SetRenderDrawColor(renderer.get(),0,0,0,255);

        std::vector<std::tuple<SDL_Rect, int> > bullets;
        auto eventStatus = SDL_PollEvent(&event);

        activeSprites.erase(std::remove_if(activeSprites.begin(), activeSprites.end(), 
                [this](const auto &x) {
                    if(!x->isActive) {
                        return true;
                    }
                    int w, h;
                    SDL_GetWindowSize(window.get(), &w, &h);
                    return x->gameObjectBounds.x < 0 || 
                        x->gameObjectBounds.y < 0 || 
                        x->gameObjectBounds.x > w || 
                        x->gameObjectBounds.y > h;
                }),
                activeSprites.end());

        for(auto& e : activeSprites){
            if(!e->sprite->isCreated) {
                e->sprite->loadSpriteSheet(renderer.get());
                e->sprite->isCreated = true;
            }
            e->controller(eventStatus, event);
            handleEntities(e);
            drawEntity(e);


            if(e->particleGenerator != NULL && e->particleGenerator->status== true) {
                handleParticles(e);
                drawParticles(e);
            }

            if(e->isShooting){
                e->isShooting = false;
                bullets.push_back(std::make_tuple(e->gameObjectBounds, e->angle));
            } 
        }

        for(auto b: bullets) {
            const auto bulletSize = 10;
            auto deltaX = (bulletSize*2) * sin(deg2rad(std::get<1>(b)));
            auto deltaY = (bulletSize*2) * cos(deg2rad(std::get<1>(b)));
            registerEntity<Bullet>(
                (std::get<0>(b).x + std::get<0>(b).w / 2) + deltaX,
                (std::get<0>(b).y + std::get<0>(b).h / 2) - deltaY,
                bulletSize, 
                std::get<1>(b),
                "sprites/playerBullet");
        }
        if(eventStatus) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }

        SDL_RenderPresent(renderer.get());
        SDL_Delay(30);
    }
}

void Engine::handleParticles(std::unique_ptr<GameObject>& e) {

    for(auto& p : e->particleGenerator->particles) {
        auto new_vel = p.velocity + p.acceleration;

        if(new_vel > 20) {
            p.velocity = 20;
        }
        else if(new_vel < 0) {
            p.velocity = 0;
        }
        else {
            p.velocity = new_vel;
        }

        p.particleBounds.x += p.velocity * sin(deg2rad(p.angle));
        p.particleBounds.y -= p.velocity * cos(deg2rad(p.angle));
    }
}
void Engine::handleEntities(std::unique_ptr<GameObject>& e) {

    auto new_vel = e->velocity + e->acceleration;

    if(new_vel > 20) {
        e->velocity = 20;
    }
    else if(new_vel < 0) {
        e->velocity = 0;
    }
    else {
        e->velocity = new_vel;
    }
    SDL_Rect futureBounds = e->gameObjectBounds;

    auto x_dist = e->velocity * sin(deg2rad(e->angle));
    auto y_dist = e->velocity * cos(deg2rad(e->angle));

    futureBounds.x += x_dist;
    futureBounds.y -= y_dist;

    for(auto& collision_e : activeSprites) {
        if(collision_e->id == e->id){
            continue;
        }

        auto collide = checkCollision(futureBounds, collision_e->gameObjectBounds);
        if(collide) {
            if(e->particleGenerator != NULL && e->particleGenerator->status){
                auto p_x = e->gameObjectBounds.x + (e->gameObjectBounds.w / 2);
                auto p_y = e->gameObjectBounds.y + (e->gameObjectBounds.h / 2);
                e->particleGenerator->generateParticles(p_x, p_y);
            }
            collision_e->collision(e->entity);
        }
    }


    e->gameObjectBounds.x += x_dist;
    e->gameObjectBounds.y -= y_dist;
}

void Engine::drawEntity(std::unique_ptr<GameObject>& e) {

    SDL_RenderCopyEx(renderer.get(),
        e->sprite->spriteSheet.get(), 
        &(e->sprite->currentSpriteFrameBounds), 
        &(e->gameObjectBounds), 
        e->angle, 
        NULL, 
        SDL_FLIP_NONE);
}
void Engine::drawParticles(std::unique_ptr<GameObject>& e) {

    if(e->particleGenerator->currentDuration > e->particleGenerator->duration) {
        e->particleGenerator->currentDuration = 0;
        e->particleGenerator->particles.clear();
        e->particleGenerator->isActive = false;
        return;
    }

    e->particleGenerator->currentDuration++;

    for(auto& p: e->particleGenerator->particles) {
        SDL_SetRenderDrawColor(renderer.get(), p.r, p.g, p.b, p.a);
        SDL_RenderFillRect(renderer.get(), &p.particleBounds );
    }
    SDL_SetRenderDrawColor(renderer.get(), 0,0,0,0);
}

void Engine::stop() {
	SDL_RenderClear(renderer.get());
	is_running = false;
	
}

bool Engine::checkCollision(SDL_Rect rect1, SDL_Rect rect2){
    return !(rect1.x+rect1.w < rect2.x 
        || rect2.x+rect2.w<rect1.x
        || rect1.y+rect1.h<rect2.y
        || rect2.y+rect2.h<rect1.y);
}
