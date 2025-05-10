#ifndef BACKGROUND_SPRITE_H
#define BACKGROUND_SPRITE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

class BackgroundSprite {
    protected:
        const std::string img_path = BG_IMAGE;   
    public:
        BackgroundSprite();       
        sf::Image img;
        sf::Texture texture;
        sf::Sprite sprite;
        void init();
        sf::Sprite getSprite();
};

#endif /* BACKGROUND_SPRITE_H */

// END OF FILE
