#include "engine/audio.hpp"

Audio::Audio(std::string path) {
    this->path = path;
    repeat = 0;
    load();
}

void Audio::reproduce() {
    if(Mix_PlayMusic(audio, -1) == -1) {
        std::cerr << "Impossible play audio" << std::endl;
        std::exit(ePlayAudio);
    }
}

void Audio::init() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)) {
        std::cerr << "Impossible initialize SDL_MixAudio";
        std::exit(mixInit);
    }
}

void Audio::load() {
    audio = Mix_LoadMUS(path.c_str());
    if(!audio) {
        std::cerr << "Impossible load audio: " << path << std::endl;
        std::exit(eLoadAudio);
    }
}

void Audio::loop() {
    if(repeat == 0) {
        reproduce();
        ++repeat;
    }
    if((int)Mix_GetMusicPosition(audio) == Mix_MusicDuration(audio)) {
        Mix_SetMusicPosition(0);
    } 
}

Mix_Music* Audio::getAudio() {
    return audio;
}

Audio::~Audio() {
    Mix_CloseAudio();
}