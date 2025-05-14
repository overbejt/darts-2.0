#ifndef NEW_GAME_BUTTON_H
#define NEW_GAME_BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>
#include "TextService.h"

class NewGameButton {
    protected:        
        sf::Font regFont;
        const std::string msg = "New Game";
        sf::Vector2f rSize = {120.f, 40.f};
        sf::RectangleShape rect;
        void init();
    public:
        NewGameButton();
        void drawRect(sf::RenderWindow& window);
        sf::FloatRect getGlobalBounds();
};

#endif /* NEW_GAME_BUTTON_H */

// END OF FILE
