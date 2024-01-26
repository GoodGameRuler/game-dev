#ifndef SPRITE
#define SPRITE

// #include "manager.h"
#include <SDL2/SDL.h>
#include <string>

enum LAYER_E {BACKGROUND, FOREGROUND, PARTICLE};

class BasicGameObject {
public:
    virtual ~BasicGameObject() {};
    inline int get_x_pos() const {return _x;};
    inline int get_y_pos() const {return _y;};
private:
protected:
    BasicGameObject(int x, int y, LAYER_E layer = BACKGROUND);
    int _x;
    int _y;
    int _h = 0;
    int _w = 0;
    LAYER_E _layer;
    SDL_Renderer* _renderer; 
};

class Shape : public BasicGameObject {
};

class Rect : public Shape {
};

class Circle : public Shape {
};

class Sprite : public BasicGameObject {
public:
    Sprite(int x, int y, std::string image, LAYER_E layer = FOREGROUND);
    ~Sprite();
    inline SDL_Texture* get_texture() const {return _texture;};
    void init_texture(SDL_Renderer*);

private:
protected:
    SDL_Texture* _texture = nullptr;
    std::string _image_name;


};


#endif // !SPRITE
