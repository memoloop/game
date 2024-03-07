#include "engine/includes.hpp"
#include "engine/errors.hpp"

#include "engine/window.hpp"
#include "engine/entity.hpp"
#include "player.hpp"

int main() {
    Window* window = new Window();
    Player* player = new Player(window->getRenderer());
    player->setColor(255, 255, 0, 255);

    const Uint8* keys = SDL_GetKeyboardState(nullptr);

    bool run = true;
    SDL_Event event;

    while(run) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            run = false;
        }
        
        player->input(keys);
        player->update();

        SDL_RenderClear(window->getRenderer());

        player->draw();

        SDL_SetRenderDrawColor(window->getRenderer(), 120, 200, 255, 255);
        SDL_RenderPresent(window->getRenderer());
        SDL_Delay(10);
    }

    delete window;
    delete player;
    delete keys;

    return no;
}