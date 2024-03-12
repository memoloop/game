#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "engine/entity.hpp"

class Player:Entity {
    public:
    Player(SDL_Renderer* renderer);
    ~Player();
    void input(const Uint8* keys);
    void draw();
    void update();

    void setColor(int r, int g, int b, int a);
    bool collide(Entity* other);

    private:
    float speed;
    float strenght;
    void setGravity();
};

#endif