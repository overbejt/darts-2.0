#ifndef EZ_BUTTON_H
#define EZ_BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
#include "TextService.h"

/**
    As the game grows, this abstract class will help with 
    putting buttons into a std::vector for easier management.
*/
class EzButton {
    protected:
        sf::Font regFont;
        std::string msg;
        sf::Vector2f rSize = darts::buttonRectangle;
        sf::RectangleShape rect;
        virtual void init() = 0;
    public:
        ~EzButton() {};
        virtual void drawRect(sf::RenderWindow& window) = 0;
        virtual sf::FloatRect getGlobalBounds() = 0;
};  // End of the 'EzButton' class

#endif /* EZ_BUTTON_H */

// END OF FILE
