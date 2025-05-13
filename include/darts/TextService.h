#ifndef TEXT_SERVICE_H
#define TEXT_SERVICE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "utils.h"

class TextService {
    private:
        // int TEXT_LG = 38;
        // int TEXT_LG = 125;
        int TEXT_LG = 200;
        int TEXT_MD = 50;
        int TEXT_SM = 12;
        sf::Font regFont;
        sf::Font boldFont;
        void init();
    public:
        // TODO Might need to create some buttons if they don't come stock
        TextService();
        void drawGameOver(sf::RenderWindow& window);
        void drawLives(sf::RenderWindow& window, int lives);
        void drawScore(sf::RenderWindow& window, int score);
        void drawPaused(sf::RenderWindow& window);
        void setDefaultColor(sf::Text& textObj);
};

#endif /* TEXT_SERVICE_H */

// END OF FILE
