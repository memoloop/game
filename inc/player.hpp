#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "engine/entity.hpp"

class Player:Entity {
    public:
    SDL_Rect rect;
    Player(SDL_Renderer* renderer);
    ~Player();
    void input(const Uint8* keys);
    void draw();
    void update();

    void setColor(int r, int g, int b, int a);
    bool collide(Entity* other);

    private:
    float speed;
    float gravityStrenght;
    float jumpStrenght;
    std::string idle;
    std::string walk;

    void setGravity();
    bool checkCollision(SDL_Rect* a, SDL_Rect* b);
    void animate();
    void setTexture(std::string path);
};

#endif