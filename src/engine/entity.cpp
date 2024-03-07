#include "engine/entity.hpp"

Entity::Entity(SDL_Renderer* renderer, int x, int y, int w, int h, const char* path) {
    rect = {x, y, w, h};
    this->path = path;
    this->renderer = renderer;
    hasTexture = true;
    setColor(255, 255, 255, 255);
    setTexture();
}

Entity::Entity(SDL_Renderer* renderer, int x, int y, int w, int h) {
    rect = {x, y, w, h};
    hasTexture = false;
    this->renderer = renderer;
    setColor(255, 255, 255, 255);
}

void Entity::setColor(int r, int g, int b, int a) {
    color = {r, g, b, a};
}

void Entity::setTexture() {
    this->texture = IMG_LoadTexture(this->renderer, this->path);
    if(!texture) {
        std::cerr << "Impossible load texture: " << path << std::endl;
        std::exit(eTexture);
    }
}

void Entity::draw() {
    if(!hasTexture) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(renderer, &rect);        
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_SetTextureColorMod(texture, (Uint8)color.r, (Uint8)color.g, (Uint8)color.b);
    }
}

Entity::~Entity() {
    SDL_DestroyTexture(texture);
}