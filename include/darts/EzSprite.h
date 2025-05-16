#ifndef EZ_SPRITE_H
#define EZ_SPRITE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

class EzSprite {
    protected:
        std::string img_path;
        sf::Image img;
        sf::Texture texture;
        sf::Sprite sprite;
        virtual void init() = 0;
    public:
        EzSprite() : img(), texture(), sprite(texture) {};
        ~EzSprite() {};
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
        };
        virtual sf::FloatRect getGlobalBounds() {
            return sprite.getGlobalBounds();
        }
        virtual void move(float ammount) = 0;
};  // End of the 'EzSprite' class

#endif /* EZ_SPRITE_H */

// END OF FILE
