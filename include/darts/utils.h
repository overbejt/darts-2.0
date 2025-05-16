/**
    This file contains the constants for the depdencies.  
    Updates to the file paths can be done here.
*/
#ifndef UTILS_H
#define UTILS_H
#include <string>

namespace darts {
    // Paths for images
    namespace img {
        const std::string COCONUT = "assets/images/coconut.png";
        const std::string BACKGROUND = "assets/images/jungle-palm-trees.png";
        const std::string KOALA = "assets/images/Killer-koala.png";
    }    

    // Paths for sounds
    namespace audio {
        const std::string BONK = "assets/audio/collision.wav";
        const std::string THEME_SONG = "assets/audio/SwayThisWay.wav";
    }

    // Paths for fonts
    namespace font {        
        const std::string FONT_BOLD = "assets/fonts/AmaticSC-Bold.ttf";
        const std::string FONT_REGULAR = "assets/fonts/AmaticSC-Regular.ttf";    
    }

    // Shared constants
    const sf::Vector2f buttonRectangle = {120.f, 40.f};
    const sf::Vector2f buttonRectangleSize = {200.f, 100.f};
    const int COCONUT_SPEED = 5;
    const float KOALA_SPEED = 15.f;
    const int MAX_LIVES = 6;
    const int SCORE_INCREMENT = 5;
    const int TEXT_LG = 200;
    const int TEXT_MD = 100;
    const int TEXT_SM = 50;
}  // End of the 'darts' namespace

#endif /* UTILS_H */

// END OF FILE
