#include "window.hpp"

Window::Window() {
    title = "Game";
    width = 1600;
    height = 900;
    init();
    create();
}

void Window::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Impossible initialize SDL" << std::endl;
        std::exit(sdlInit);
    }
    if(!IMG_Init(IMG_INIT_PNG) ) {
        std::cerr << "Impossible initialize SDL_Image" << std::endl;
        std::exit(imgInit);
    }   
    if(!TTF_Init() < 0) {
        std::cerr << "Impossible initialize SDL_TTF" << std::endl;
        std::exit(ttfInit);
    }
}

void Window::create() {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);
    if(!window) {
        std::cerr << "Impossible create a window" << std::endl;
        std::exit(eWindow);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        std::cerr << "Impossible create a renderer" << std::endl;
        std::exit(eRenderer);
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

const char* Window::getTitle() {
    return title;
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

SDL_Window* Window::getWindow() {
    return window;
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}