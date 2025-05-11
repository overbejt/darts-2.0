#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

class Background {
    protected:
        const std::string img_path = BG_IMAGE;
        sf::Image img;
        sf::Texture texture;
        sf::Sprite sprite;
        void init();
    public:
        Background();
        sf::Sprite getSprite();
};  // End of the 'Background' class

#endif /* BACKGROUND_H */

// END OF FILE
