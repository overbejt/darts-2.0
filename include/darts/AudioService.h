#ifndef AUDIO_SERVICE_H
#define AUDIO_SERVICE_H
#include <SFML/Audio.hpp>
#include "darts/utils.h"

class AudioService {
    public:
        AudioService();
        void pauseThemeSong();
        void playCollision();
        void playThemeSong();

    protected:
        sf::SoundBuffer collisionBuffer;
        sf::Sound collisionAudio;
        sf::Music themeSong;
        void init();
};

#endif /* AUDIO_SERVICE_H */

// END OF FILE
