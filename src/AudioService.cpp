#include <iostream>
#include "darts/AudioService.h"

AudioService::AudioService() : collisionAudio(collisionBuffer) {
    this->init();
}  // End of the 'constructor' 

void AudioService::init() {
    if (!collisionBuffer.loadFromFile(darts::audio::BONK)) {
        std::cerr << "Failed to load collision sound!" << std::endl;
    }
    if (!themeSong.openFromFile(darts::audio::THEME_SONG)) {
        std::cerr << "Failed to load them song!" << std::endl;
    }
    themeSong.setLooping(true);
}  // End of the 'init' function

void AudioService::stopThemeSong() {
    themeSong.stop();
}  // End of the 'stopThemeSong' function

void AudioService::pauseThemeSong() {
    themeSong.pause();
}  // End of the 'pauseThemeSong' function

void AudioService::playCollision() {
    collisionAudio.play();
}  // End of the 'playCollision' function

void AudioService::playThemeSong() {
    themeSong.play();
}  // End of the 'playThemeSong' function

// END OF FILE
