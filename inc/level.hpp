#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "engine/includes.hpp"
#include "engine/entity.hpp"
#include "player.hpp"

class Level {
    private:
    SDL_Renderer* renderer;
    std::vector<Entity*> tileList;
    Player* player;
    int map[100][100];
    
    void loadMap();

    public:
    Level(SDL_Renderer* renderer, int map[100][100], Player* player);
    ~Level();

    void draw();
};

#endif