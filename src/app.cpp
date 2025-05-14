#include <iostream>
#include <optional>
#include "darts/app.h"

// Constructor
App::App() {
    this->init();
}  // End of the 'constructor'

void App::init() {
    window = sf::RenderWindow(sf::VideoMode({1200, 647}), "Darts");
    
    // call it once after creating the window
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    coconut.setMaxHeight(647);
    coconut.setMaxWidth(1200);
}  // End of the 'init' function

void App::drawSprites() {
    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    // Draw the background
    window.draw(background.getSprite());
    window.draw(koala.getSprite());
    // Want the cocont to render on top of the kola when there's a collision
    window.draw(coconut.getSprite());
    text.drawLives(window, lives);
    
    // TODO Don't like it.  Make it match the pattern used by the sprites
    // Unsure if I prefer to have the text service draw or not.  Doesn't reduce lines in here any
    if (isPaused) {
        text.drawPaused(window);
    }

    if (!isPaused && !isGameOver) {
        // Make the coconut fall
        coconut.move(5);
    }

    if (isGameOver) {
        text.drawGameOver(window);
        playBtn.drawRect(window);
        exitBtn.drawRect(window);
    }


    // end the current frame
    window.display();
}  // End of the 'drawSprites' function

void App::checkForCollisions() {
    // Check for collision
    sf::FloatRect koalaBox = koala.getSprite().getGlobalBounds();
    sf::FloatRect coconutBox = coconut.getSprite().getGlobalBounds();
    if (std::optional intersection = koalaBox.findIntersection(coconutBox)) {
        if (!coconut.collision) {
            coconut.collision = true;
            lives--;
            audio.playCollision();
        }
    } else {
        // If the collistion flag was toggled, reset it now that there's no longer a colision
        if (coconut.collision) {
            coconut.collision = false;
        }
    }
}  // End of the 'checkForCollisions' function

void App::checkOnNewGameClicked() {
    // sf::Vector2f globalPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
    sf::Vector2f localPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    // std::cout << "mx: " << localPosition.x << " my: " << localPosition.y << std::endl;
    sf::FloatRect newGameBtnBox = playBtn.getGlobalBounds();
    // std::cout << "bx0: " << newGameBtnBox.position.x << " bx1: " << newGameBtnBox.position.x + newGameBtnBox.size.x;
    // std::cout << " by0: " << newGameBtnBox.position.y << " by1: " << newGameBtnBox.position.y + newGameBtnBox.size.y;
    // std::cout << std::endl;
    if (newGameBtnBox.contains(localPosition)) {
        // TODO handle new game
        std::cout << "New game btn clicked" << std::endl;
        isGameOver = false;
        lives = MAX_LIVES;
        audio.playThemeSong();
    } 
}  // End of the 'checkOnNewGameClicked' function

void App::checkOnExitGameClicked() {
    sf::Vector2f localPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    sf::FloatRect exitGameBtnBox = exitBtn.getGlobalBounds();
    if (exitGameBtnBox.contains(localPosition)) {
        window.close();
    } 
}  // End of the 'checkOnExitGameClicked' function

void App::gameOver() {
    isGameOver = true;
    audio.stopThemeSong();
}  // End of the 'gameOver' function

void App::pauseGame() {
    if (isPaused) {
        // resume game
        audio.playThemeSong();
        isPaused = false;
    } else {
        // pause game
        audio.pauseThemeSong();
        isPaused = true;
    }
}  // End of the 'pauseGame' function

void App::run() {
    if (!isGameOver) {
        audio.playThemeSong();
    }
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional<sf::Event> event = window.pollEvent()) {            
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Goodbye" << std::endl;
                window.close();  // breaks the loop
            }

            if (event->is<sf::Event::KeyPressed>() 
                && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space) {
                if (!isGameOver) {
                    pauseGame();
                }
            }

            // Todo handle mouse clicks and check if buttons clicked
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                // left mouse button is pressed
                checkOnNewGameClicked();
                checkOnExitGameClicked();
            }

            // Prevent cheating by pausing and moving then resuming
            if (!isPaused && !isGameOver) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                    // left key is pressed: move our character
                    koala.move(-15.f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                    // right key is pressed: move our character
                    koala.move(15.f);
                }
            }
        }

        if (lives == 0) {
            gameOver();
        }

        drawSprites();
        checkForCollisions();
    }
} // End of the 'run' function

// END OF FILE
