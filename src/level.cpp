#include "level.hpp"

Level::Level(SDL_Renderer* renderer, int map[100][100], Player* player) {
    for(int row = 0; row <= 99; ++row) {
        for(int col = 0; col <= 99; ++col) {
            this->map[col][row] = map[row][col];
        }
    }
    this->renderer = renderer;
    this->player = player;
    this->player->rect.x = 100;
    this->player->rect.y = 0;
    loadMap();
}

void Level::loadMap() {
    for(int row = 0; row <= 100; ++row) {
        for(int col = 0; col <= 100; ++col) {
            if(map[row][col] == 1) {
                Entity* tile = new Entity(renderer, row*100, col*100, 100, 100, "res/images/environment/platform.png");
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