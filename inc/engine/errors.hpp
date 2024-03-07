#ifndef ERRORS_HPP
#define ERRORS_HPP

enum Error {
    no, sdlInit, imgInit, ttfInit,
    eWindow, eRenderer,
    eTexture
};

#endif