#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "includes.hpp"

class Audio {
    public:
    Audio(std::string path);
    ~Audio();
    static void init();
    void reproduce();
    void loop();
    Mix_Music* getAudio();

    private:
    std::string path;
    Mix_Music* audio;
    void load();
    int repeat;
};

#endif