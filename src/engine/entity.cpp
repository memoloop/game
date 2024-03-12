#include "engine/entity.hpp"

Entity::Entity(SDL_Renderer* renderer, int x, int y, int w, int h, const char* path) {
    rect = {x, y, w, h};
    this->path = path;
    this->renderer = renderer;
    hasTexture = true;
    direction = {0, 0};
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

bool Entity::collide(Entity* other) {
    if(verticalCollision(other)) return true;
    if(horizontalCollision(other)) return true;
    return false;
}

bool Entity::horizontalCollision(Entity* other) {
    SDL_Rect result;

    if(SDL_IntersectRect(&this->rect, &other->rect, &result)) {
        if(direction.x < 0) {       // go left
            rect.x = other->rect.x+other->rect.w;
            return true;
        }
        if(direction.x > 0) {       // go right
            rect.x = other->rect.x-rect.w;
            return true;
        }

        return false;
    }
}

bool Entity::verticalCollision(Entity* other) {
    SDL_Rect result;

    if(SDL_IntersectRect(&this->rect, &other->rect, &result)) {
        if(direction.y > 0) {       // go down
            rect.y = other->rect.y-rect.h;
            direction.y = 0;
        }
        if(direction.y < 0) {       // go up
            rect.y = other->rect.y+other->rect.h;
        }
    }
}

Entity::~Entity() {
    SDL_DestroyTexture(texture);
}