#include "engine/includes.hpp"
#include "engine/errors.hpp"

#include "engine/window.hpp"
#include "engine/audio.hpp"

#include "player.hpp"

#include "level.hpp"

int main() {
    Window* window = new Window();
    Audio::init();
    Player* player = new Player(window->getRenderer());
    player->setColor(255, 255, 0, 255);

    // Audio* audio = new Audio("res/musics/Inst.ogg");

    const Uint8* keys = SDL_GetKeyboardState(nullptr);

    int map[5][5] = {
        {1, 0, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
    };

    Level* level = new Level(window->getRenderer(), map, player);

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

        SDL_RenderClear(window->getRenderer());

        level->draw();
        player->draw();

        SDL_SetRenderDrawColor(window->getRenderer(), 120, 200, 255, 255);
        SDL_RenderPresent(window->getRenderer());
        SDL_Delay(10);
    }

    delete window;
    delete player;
    delete level;

    // delete audio;

    return no;
}