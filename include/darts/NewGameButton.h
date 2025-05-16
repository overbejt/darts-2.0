#ifndef NEW_GAME_BUTTON_H
#define NEW_GAME_BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>
#include "EzButton.h"

class NewGameButton : public EzButton {
    protected:
        void init() override;
    public:
        NewGameButton(std::string msg);
        void drawRect(sf::RenderWindow& window) override;
        sf::FloatRect getGlobalBounds() override;
};

#endif /* NEW_GAME_BUTTON_H */

// END OF FILE
