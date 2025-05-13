#ifndef APP_H
#define APP_H
#include <SFML/Window.hpp>
#include "utils.h"
#include "Background.h"
#include "Koala.h"
#include "Coconut.h"
#include "AudioService.h"
#include "TextService.h"

class App {
    private:
        bool isPaused = false;
        bool isGameOver = false;
        int lives = MAX_LIVES;
        sf::RenderWindow window;
        Background background;
        Koala koala;
        Coconut coconut;
        AudioService audio;
        TextService text;
        void init();
        void checkForCollisions();
        void drawSprites();
        void gameOver();
        void pauseGame();
    public:        
        App();  // Constructor
        void run();
};

#endif /* APP_H */

// END OF FILE
