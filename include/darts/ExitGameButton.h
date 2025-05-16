#ifndef EXIT_GAME_BUTTON_H
#define EXIT_GAME_BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>
#include "EzButton.h"

class ExitGameButton : public EzButton {
    protected:
        void init() override;
    public:
        ExitGameButton(std::string msg);
        void drawRect(sf::RenderWindow& window) override;
        sf::FloatRect getGlobalBounds() override;
};

#endif /* EXIT_GAME_BUTTON_H */

// END OF FILE
