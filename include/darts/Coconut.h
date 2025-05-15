#ifndef COCONUT_H
#define COCONUT_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

class Coconut {
    protected:
        const std::string img_path = COCONUT;
        sf::Image img;
        sf::Texture texture;
        sf::Sprite sprite;
        const int imgHeight = 82;
        const int imgWidth = 82;
        int maxHeight;
        int maxWidth;        
        void init();
    public:
        Coconut();
        bool collision = false;
        void setMaxHeight(int maxHeight);
        void setMaxWidth(int maxWidth);
        sf::Sprite getSprite();
        float getRandomX();
        void move(float ammount);
        bool scoredPoint();
};  // End of the 'Coconut' class

#endif /* COCONUT_H */

// END OF FILE
