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
        void init();
    public:
        Koala();
        sf::Sprite getSprite();
        void move(float ammount);
};  // End of the 'Koala' class

#endif /* KOALA_H */

// END OF FILE
