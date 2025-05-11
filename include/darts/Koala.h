#ifndef KOALA_H
#define KOALA_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

class Koala {
    protected:
        const std::string img_path = KOALA;
        sf::Image img;
        sf::Texture texture;
        sf::Sprite sprite;
        // TODO Add location so it can move
        void init();
    public:
        Koala();
        sf::Sprite getSprite();
        void move(float ammount);
        // TODO Add a function that can update its position L/R
};  // End of the 'Background' class

#endif /* KOALA_H */

// END OF FILE
