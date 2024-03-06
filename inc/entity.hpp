#include "includes.hpp"

class Entity {
    private:
    const char* path;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    Color color;
    bool hasTexture;

    void setTexture();

    public:
    SDL_Rect rect;

    Entity(SDL_Renderer* renderer, int x, int y, int w, int h, const char* path);
    Entity(SDL_Renderer* renderer, int x, int y, int w, int h);
    ~Entity();
    void setColor(int r, int g, int b, int a);
    void draw();
};
    