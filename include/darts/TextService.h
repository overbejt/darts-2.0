#ifndef TEXT_SERVICE_H
#define TEXT_SERVICE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "utils.h"

class TextService {
    private:
        sf::Font regFont;
        sf::Font boldFont;
        void init();
    public:
        TextService();
        void drawGameOver(sf::RenderWindow& window);
        void drawLives(sf::RenderWindow& window, int lives);
        void drawScore(sf::RenderWindow& window, int score);
        void drawPaused(sf::RenderWindow& window);
        void setDefaultColor(sf::Text& textObj);
};

#endif /* TEXT_SERVICE_H */

// END OF FILE
