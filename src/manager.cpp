#include "manager.h"
#include "sprite.h"
#include <iostream>
#include <SDL2/SDL_image.h>

GameManager::GameManager(int width, int height, std::string title)
    : _width{width}, _height{height}, _title{title}
{}
    
void GameManager::init() {

    if(SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Game Runtime Error: failed to initialise SDL Video\n";
        std::cout << SDL_GetError();
        exit(1);
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
        std::cout << "Game Runtime Error: failed to initialise SDL Images\n";
        std::cout << SDL_GetError();
        exit(1);
    }

    screen = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
            _width, _height, WINDOW_FLAGS);
    
    if(!screen) {
        std::cout << "Game Runtime Error: failed to create SDL Window\n";
        std::cout << SDL_GetError();
        exit(1);
    }

    // TODO find out what this does
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(screen, DRIVER_INDEX, RENDERER_FLAGS);

    if(!renderer) {
        std::cout << "Game Runtime Error: failed to create SDL Renderer\n";
        std::cout << SDL_GetError();
        exit(1);
    }
}

void GameManager::quit() {
    IMG_Quit();
    SDL_Quit();
}

void GameManager::prepare_scene() {
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255); 
    SDL_RenderClear(renderer);
}

void GameManager::present_scene() {
    SDL_RenderPresent(renderer);
}

void GameManager::blit(SDL_Texture* texture, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void GameManager::blit_all() {
    for(int i = 0; i < renderables.size(); i++) {
        blit(renderables[i]->get_texture(), renderables[i]->get_x_pos(), renderables[i]->get_y_pos());
    }
}

void GameManager::add_game_object(Sprite* sp) {
    sp->init_texture(renderer);
    renderables.push(sp);
}

void GameManager::remove_game_object(Sprite* sp) {
    renderables.pop(sp);
}


GameManager::~GameManager() {}
