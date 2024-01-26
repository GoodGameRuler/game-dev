#include "events.h"
#include "manager.h"
#include <SDL2/SDL.h>
#include <cstring>

int main(int argc, char** argv) {

    GameManager game_manager("GameTitle: Slogan");
    GameManager* manager = &game_manager;

    if(argc > 1) {
        if(strncmp(argv[1], "-g", 2) == 0) {
            manager->set_debug_mode();
        }
    }

    manager->init();

    while(!manager->get_game_over()) {
        game_manager.prepare_scene();
        listen_event_SE(manager);
        game_manager.present_scene();
    } 

    manager->quit();

    return 0;
}
