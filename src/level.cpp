#include "level.hpp"

Level::Level(SDL_Renderer* renderer, int map[5][5], Player* player) {
    for(int row = 0; row <= 4; ++row) {
        for(int col = 0; col <= 4; ++col) {
            this->map[row][col] = map[row][col];
        }
    }
    this->renderer = renderer;
    this->player = player;
    loadMap();
}

void Level::loadMap() {
    for(int row = 0; row <= 5; ++row) {
        for(int col = 0; col <= 5; ++col) {
            if(map[row][col] == 1) {
                Entity* tile = new Entity(renderer, row*100, col*100, 100, 100);
                tileList.push_back(tile);
            }
        }
    }
}

void Level::draw() {
    for(Entity* tile:tileList) {
        tile->draw();
        player->collide(tile);
    }
}

Level::~Level() {
    for(Entity* tile:tileList) {
        delete tile;
    }
    tileList.clear();
}