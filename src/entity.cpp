#include "entity.hpp"

Entity::Entity(SDL_Renderer* renderer, int x, int y, int w, int h, const char* path) {
    rect = {x, y, w, h};
    this->path = path;
    this->renderer = renderer;
    setTexture();
}

void Entity::setTexture() {
    this->texture = IMG_LoadTexture(this->renderer, this->path);
    if(!texture) {
        std::cerr << "Impossible load texture: " << path << std::endl;
        std::exit(eTexture);
    }
}

void Entity::draw() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

Entity::~Entity() {
    SDL_DestroyTexture(texture);
}