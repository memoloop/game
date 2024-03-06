#include "includes.hpp"

class Entity {
    private:
    const char* path;
    SDL_Texture* texture;
    SDL_Renderer* renderer;

    void setTexture();

    public:
    SDL_Rect rect;

    Entity(SDL_Renderer* renderer, int x, int y, int w, int h, const char* path);
    ~Entity();
    void draw();
};
    