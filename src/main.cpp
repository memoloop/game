#include "includes.hpp"
#include "errors.hpp"

#include "window.hpp"

int main() {
    Window* window = new Window();

    bool run = true;
    SDL_Event event;

    while(run) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                run = false;
            }
        }

        SDL_RenderClear(window->getRenderer());

        SDL_SetRenderDrawColor(window->getRenderer(), 120, 200, 255, 255);
        SDL_RenderPresent(window->getRenderer());
    }

    delete window;

    return no;
}