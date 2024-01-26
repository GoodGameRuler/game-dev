#include "events.h"
#include "manager.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <cstring>
#include "array_list.h"

int main(int argc, char** argv) {

    GameManager game_manager("GameTitle: Slogan");
    GameManager* manager = &game_manager;

    if(argc > 1) {
        if(strncmp(argv[1], "-g", 2) == 0) {
            manager->set_debug_mode();
        }
    }

    manager->init();

    Sprite* trial_sprite = new Sprite(0, 0, "./static/Free/Background/Brown.png");
    // Sprite trial_sprite{10, 10, "/home/udit/Projects/game-dev/static/Free/Background/Brown.png"};
    game_manager.add_game_object(trial_sprite);

    while(!manager->get_game_over()) {
        game_manager.prepare_scene();
        listen_event_SE(manager);
        // game_manager.blit(trial_sprite->get_texture(), trial_sprite->get_x_pos(), trial_sprite->get_y_pos());
        game_manager.blit_all();
        game_manager.present_scene();
    } 


    manager->quit();

    return 0;
}
