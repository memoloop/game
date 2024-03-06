#include "includes.hpp"
#include "errors.hpp"

#include "window.hpp"
#include "entity.hpp"

int main() {
    Window* window = new Window();
    Entity* entity = new Entity(window->getRenderer(), 0, 0, 100, 100, "res/images/player/player_idle.png");

    bool run = true;
    SDL_Event event;

    while(run) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                run = false;
            }
        }

        SDL_RenderClear(window->getRenderer());
        

        entity->draw();
        SDL_SetRenderDrawColor(window->getRenderer(), 120, 200, 255, 255);
        SDL_RenderPresent(window->getRenderer());
    }

    delete window;
    delete entity;

    return no;
}