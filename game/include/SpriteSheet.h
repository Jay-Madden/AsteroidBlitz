#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     SpriteSheet data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    struct SpriteSourceSizeClass {
        int64_t x;
        int64_t y;
        int64_t w;
        int64_t h;
    };

    struct Size {
        int64_t w;
        int64_t h;
    };

    struct FrameElement {
        std::string filename;
        SpriteSourceSizeClass frame;
        bool rotated;
        bool trimmed;
        SpriteSourceSizeClass sprite_source_size;
        Size source_size;
    };

    struct Meta {
        std::string app;
        std::string version;
        std::string image;
        std::string format;
        Size size;
        std::string scale;
        std::string smartupdate;
    };

    struct SpriteSheet {
        std::vector<FrameElement> frames;
        Meta meta;
    };

namespace nlohmann {
    void from_json(const json & j, SpriteSourceSizeClass & x);
    void to_json(json & j, const SpriteSourceSizeClass & x);

    void from_json(const json & j, Size & x);
    void to_json(json & j, const Size & x);

    void from_json(const json & j, FrameElement & x);
    void to_json(json & j, const FrameElement & x);

    void from_json(const json & j, Meta & x);
    void to_json(json & j, const Meta & x);

    void from_json(const json & j, SpriteSheet & x);
    void to_json(json & j, const SpriteSheet & x);

    inline void from_json(const json & j, SpriteSourceSizeClass& x) {
        x.x = j.at("x").get<int64_t>();
        x.y = j.at("y").get<int64_t>();
        x.w = j.at("w").get<int64_t>();
        x.h = j.at("h").get<int64_t>();
    }

    inline void to_json(json & j, const SpriteSourceSizeClass & x) {
        j = json::object();
        j["x"] = x.x;
        j["y"] = x.y;
        j["w"] = x.w;
        j["h"] = x.h;
    }

    inline void from_json(const json & j, Size& x) {
        x.w = j.at("w").get<int64_t>();
        x.h = j.at("h").get<int64_t>();
    }

    inline void to_json(json & j, const Size & x) {
        j = json::object();
        j["w"] = x.w;
        j["h"] = x.h;
    }

    inline void from_json(const json & j, FrameElement& x) {
        x.filename = j.at("filename").get<std::string>();
        x.frame = j.at("frame").get<SpriteSourceSizeClass>();
        x.rotated = j.at("rotated").get<bool>();
        x.trimmed = j.at("trimmed").get<bool>();
        x.sprite_source_size = j.at("spriteSourceSize").get<SpriteSourceSizeClass>();
        x.source_size = j.at("sourceSize").get<Size>();
    }

    inline void to_json(json & j, const FrameElement & x) {
        j = json::object();
        j["filename"] = x.filename;
        j["frame"] = x.frame;
        j["rotated"] = x.rotated;
        j["trimmed"] = x.trimmed;
        j["spriteSourceSize"] = x.sprite_source_size;
        j["sourceSize"] = x.source_size;
    }

    inline void from_json(const json & j, Meta& x) {
        x.app = j.at("app").get<std::string>();
        x.version = j.at("version").get<std::string>();
        x.image = j.at("image").get<std::string>();
        x.format = j.at("format").get<std::string>();
        x.size = j.at("size").get<Size>();
        x.scale = j.at("scale").get<std::string>();
        x.smartupdate = j.at("smartupdate").get<std::string>();
    }

    inline void to_json(json & j, const Meta & x) {
        j = json::object();
        j["app"] = x.app;
        j["version"] = x.version;
        j["image"] = x.image;
        j["format"] = x.format;
        j["size"] = x.size;
        j["scale"] = x.scale;
        j["smartupdate"] = x.smartupdate;
    }

    inline void from_json(const json & j, SpriteSheet& x) {
        x.frames = j.at("frames").get<std::vector<FrameElement>>();
        x.meta = j.at("meta").get<Meta>();
    }

    inline void to_json(json & j, const SpriteSheet & x) {
        j = json::object();
        j["frames"] = x.frames;
        j["meta"] = x.meta;
    }
}


#endif