#ifndef EXIT_GAME_BUTTON_H
#define EXIT_GAME_BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>
#include "TextService.h"

class ExitGameButton {
    protected:        
        sf::Font regFont;
        const std::string msg = "Exit Game";
        sf::Vector2f rSize = {120.f, 40.f};
        sf::RectangleShape rect;
        void init();
    public:
        ExitGameButton();
        void drawRect(sf::RenderWindow& window);
        sf::FloatRect getGlobalBounds();
};

#endif /* EXIT_GAME_BUTTON_H */

// END OF FILE
