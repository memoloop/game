#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "includes.hpp"

class Window {
    private:
    const char* title;
    int width;
    int height;

    SDL_Window* window;
    SDL_Renderer* renderer;

    void init();
    void create();

    public:
    Window();
    ~Window();
    const char* getTitle();
    int getWidth();
    int getHeight();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
};

#endif