#include "events.h"

int listen_event_SE(GameManager* manager) {

    SDL_Event* event = &manager->event;

    SDL_WaitEvent(event);

    switch (event->type) {
        case SDL_QUIT:
            manager->set_game_over();
            break;
        }

    return 0;
}
