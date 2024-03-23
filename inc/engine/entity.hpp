#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "includes.hpp"

class Entity {
    protected:
    std::string path;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    Color color;
    bool hasTexture;

    void setTexture(std::string path);
    bool horizontalCollision(Entity* other);
    bool verticalCollision(Entity* other);

    public:
    SDL_Rect rect;
    Vector2 direction;

    Entity(SDL_Renderer* renderer, int x, int y, int w, int h, std::string path);
    Entity(SDL_Renderer* renderer, int x, int y, int w, int h);
    ~Entity();
    void setColor(int r, int g, int b, int a);
    void draw();
    void update();
};

#endif