#include "sprite.h"
#include <iostream>
#include <SDL2/SDL_image.h>

BasicGameObject::BasicGameObject(int x, int y, LAYER_E layer)
    : _x(x), _y(y), _layer(layer){
}

Sprite::Sprite(int x, int y, std::string image_name, LAYER_E layer) 
    : BasicGameObject(x, y, layer), _image_name(image_name)
{
}

void Sprite::init_texture(SDL_Renderer* renderer) {
    _texture = IMG_LoadTexture(renderer, _image_name.c_str());    

    if(_texture == nullptr) {
        std::cout << "Game Runtime Error: failed to load Sprite\n";
        std::cout << SDL_GetError() << "\n";
        std::cout << SDL_GetBasePath() << "\n";
        exit(1);
    }
}

Sprite::~Sprite() {}
