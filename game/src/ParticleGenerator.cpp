#include "../include/ParticleGenerator.h"

void ParticleGenerator::moveParticles() {

}

void ParticleGenerator::generateParticles(int x, int y) {
    if(particles.size() > 0) {
        return;
    }
    isActive = true;
    srand (time(NULL));

    for(int i=0; i < numParticles; i++){
        particles.push_back(Particle(r,g,b,a, x, y));
    }
}