#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <string>

enum LAYER_E {BACKGROUND, FOREGROUND, PARTICLE};

class BasicGameObject {
public:
    ~BasicGameObject();
    virtual void draw() = 0;
private:
protected:
    BasicGameObject(int x, int y, LAYER_E layer = BACKGROUND);
    int _x;
    int _y;
    LAYER_E _layer;
};

class Shape : BasicGameObject {
};

class Rect : Shape {
};

class Circle : Shape {
};

class Sprite : BasicGameObject {
public:
    Sprite(int x, int y, std::string image, LAYER_E layer = FOREGROUND);
    ~Sprite();
    SDL_Texture* _texture = nullptr;

private:
protected:
    std::string _image_name;


};


#endif // !SPRITE
