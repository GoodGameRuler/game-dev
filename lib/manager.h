#ifndef MANAGER
#define MANAGER

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "sprite.h"

#define WINDOW_FLAGS (SDL_WINDOW_RESIZABLE)
#define RENDERER_FLAGS (SDL_RENDERER_ACCELERATED)
#define DRIVER_INDEX (-1) // -1 is first driver found supporting flags


class GameManager {
public:
    GameManager(std::string title) : GameManager(1280, 720, title) {};
    GameManager(int width, int height, std::string title);
    ~GameManager();
    inline void set_game_over() {_game_over = true;};
    inline bool get_game_over() {return _game_over;};
    inline void set_debug_mode(bool debug = true) {_debug = debug;};
    void init();
    void quit();
    void prepare_scene();
    void present_scene();
    SDL_Window* screen;
    SDL_Renderer* renderer;
    SDL_Event event;

private:
    bool _game_over = false;
    int _width;
    int _height;
    bool _debug = false;
    std::string _title;
    std::vector<BasicGameObject> renderables = std::vector<BasicGameObject>(20);
};


#endif // !MANAGER
