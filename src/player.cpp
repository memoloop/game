#include "player.hpp"

int x = 100;
int y = 100;
int w = 80;
int h = 80;
std::string mainPath = "res/images/player/";
Uint64 deltaTime = SDL_GetTicks64();

Player::Player(SDL_Renderer* renderer):Entity(renderer, x, y, w, h, mainPath.append("player_idle.png").c_str()) {
    speed = 6;
    gravityStrenght = 2;
    jumpStrenght = -5;
    direction.y = 1;

    idle = "player_idle.png";
    walk = "player_walk.png";
}

bool Player::checkCollision(SDL_Rect* a, SDL_Rect* b) {
    // return (a->x + a->w >= b->x && b->x + b->w >= a->x &&
    //         a->y + a->h >= b->y && b->y + b->h >= a->y);
    return SDL_HasIntersection(a, b);
}

Player::~Player() {}
bool Player::collide(Entity* other) {
    if(checkCollision(&rect, &other->rect)) {
        rect.x -= (direction.x*speed);
    }

    if(checkCollision(&rect, &other->rect)) {
        if(rect.y >= other->rect.y) {
            rect.y -= (direction.y*gravityStrenght)-1;
        }
        if(rect.y < other->rect.y) {
            rect.y -= (direction.y*gravityStrenght)+1;
        }
    }
    
    return true;
}

void Player::input(const Uint8* keys) {

    if(keys[SDL_SCANCODE_D]) {
        direction.x = 1;
        animate();
    }
    else if(keys[SDL_SCANCODE_A]) {
        direction.x = -1;
        animate();
    }
    else {
        direction.x = 0;
    }

    if(keys[SDL_SCANCODE_SPACE]) {
        direction.y = jumpStrenght;
    } else {
        while(direction.y != 1) {
            direction.y++;
        }
    }
    
}

void Player::update() {
    Entity::update();
    rect.x += direction.x*speed;
    setGravity();
    //std::cout << mainPath << std::endl;
}

void Player::setGravity() {
    rect.y += direction.y*gravityStrenght;
}

void Player::setTexture(std::string path) {
    Entity::setTexture(path);
}

void Player::animate() {
    Uint64 updateTime = SDL_GetTicks64();
    Uint64 desiredTime = 200;
    Uint64 elapsedTime = updateTime - deltaTime;
    
    if(mainPath == "res/images/player/player_idle.png") {
        mainPath = "res/images/player/"+walk;
        if(elapsedTime >= 200) {
            setTexture(mainPath);
            deltaTime = updateTime;
        }
        
    } else if(mainPath == "res/images/player/player_walk.png") {
        mainPath = "res/images/player/"+idle;
        if(elapsedTime >= 200) {
            setTexture(mainPath);
            deltaTime = updateTime;
        }
    }
}

void Player::draw() {
    if(direction.x < 0) {
        SDL_RenderCopyEx(renderer, texture, nullptr, &rect, 0, nullptr, SDL_FLIP_HORIZONTAL);
    } else {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
}

void Player::setColor(int r, int g, int b, int a) {Entity::setColor(r, g, b, a);};