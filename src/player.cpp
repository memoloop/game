#include "player.hpp"

int x = 100;
int y = 100;
int w = 100;
int h = 100;
const char* pathImage = "res/images/player/player_idle.png";

Player::Player(SDL_Renderer* renderer):Entity(renderer, x, y, w, h, pathImage) {
    speed = 3;
    direction = {0, 0};
}

Player::~Player() {}

void Player::input(const Uint8* keys) {
    if(keys[SDL_SCANCODE_D]) {
        direction.x = 1;
    }
    else if(keys[SDL_SCANCODE_A]) {
        direction.x = -1;
    } else direction.x = 0;
}

void Player::update() {
    rect.x += direction.x*speed;
    rect.y += direction.y*speed;
}

void Player::draw() {Entity::draw();}

void Player::setColor(int r, int g, int b, int a) {Entity::setColor(r, g, b, a);};