#include "engine/includes.hpp"
#include "engine/errors.hpp"

#include "engine/window.hpp"
#include "engine/audio.hpp"

#include "player.hpp"

int main() {
    Window* window = new Window();
    Audio::init();
    Player* player = new Player(window->getRenderer());
    player->setColor(255, 255, 0, 255);

    Entity* e = new Entity(window->getRenderer(), 300, 500, 100, 100);
    Entity* e1 = new Entity(window->getRenderer(), 400, 500, 100, 100);
    // Audio* audio = new Audio("res/musics/Inst.ogg");

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

        // audio->loop();

        player->collide(e);
        player->collide(e1);

        SDL_RenderClear(window->getRenderer());

        player->draw();
        e->draw();
        e1->draw();

        SDL_SetRenderDrawColor(window->getRenderer(), 120, 200, 255, 255);
        SDL_RenderPresent(window->getRenderer());
        SDL_Delay(10);
    }

    delete window;
    delete player;
    delete keys;
    delete e, e1;
    // delete audio;

    return no;
}