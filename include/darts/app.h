#ifndef APP_H
#define APP_H
#include <SFML/Window.hpp>
#include "utils.h"
#include "Background.h"
#include "Koala.h"
#include "Coconut.h"
#include "AudioService.h"
#include "TextService.h"
#include "NewGameButton.h"
#include "ExitGameButton.h"

class App {
    private:
        bool isPaused = false;
        bool isGameOver = true;
        int lives = darts::MAX_LIVES;
        int score = 0;
        sf::RenderWindow window;
        Background background = Background(darts::img::BACKGROUND);
        Koala koala = Koala(darts::img::KOALA);
        Coconut coconut = Coconut(darts::img::COCONUT);
        AudioService audio;
        TextService text;
        // TODO refactor the buttons out to a service
        NewGameButton playBtn = NewGameButton("New Game");
        ExitGameButton exitBtn = ExitGameButton("Exit Game");
        void init();
        void checkForCollisions();
        void checkOnNewGameClicked();
        void checkOnExitGameClicked();
        void drawSprites();
        void gameOver();
        void pauseGame();
    public:        
        App();  // Constructor
        void run();
};

#endif /* APP_H */

// END OF FILE
