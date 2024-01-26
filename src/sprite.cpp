#include "sprite.h"
#include <SDL2/SDL_image.h>

BasicGameObject::BasicGameObject(int x, int y, LAYER_E layer)
    : _x(x), _y(y), _layer(layer){
}

Sprite::Sprite(int x, int y, std::string image_name, LAYER_E layer) 
    : BasicGameObject(x, y, layer), _image_name(image_name)
{

}
