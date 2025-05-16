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
    background.draw(window);
    koala.draw(window);
    // Want the cocont to render on top of the kola when there's a collision
    coconut.draw(window);
    text.drawLives(window, lives);
    text.drawScore(window, score);
    
    if (isPaused) {
        text.drawPaused(window);
    }

    if (!isPaused && !isGameOver) {
        // Make the coconut fall
        coconut.move(darts::COCONUT_SPEED);
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
    sf::FloatRect koalaBox = koala.getGlobalBounds();
    sf::FloatRect coconutBox = coconut.getGlobalBounds();
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
    sf::Vector2f localPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    sf::FloatRect newGameBtnBox = playBtn.getGlobalBounds();
    if (newGameBtnBox.contains(localPosition)) {
        // Set things up for a new game
        isGameOver = false;
        lives = darts::MAX_LIVES;
        score = 0;
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
    // game loop
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

            // handle mouse clicks and check if buttons clicked
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                // left mouse button is pressed
                checkOnNewGameClicked();
                checkOnExitGameClicked();
            }

            // Prevent cheating by pausing and moving then resuming
            if (!isPaused && !isGameOver) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                    // left key is pressed: move our character
                    koala.move(-darts::KOALA_SPEED);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                    // right key is pressed: move our character
                    koala.move(darts::KOALA_SPEED);
                }
            }
        }

        // Handle game over 
        if (lives == 0) {
            gameOver();
        }

        // Update the score if needed
        if (coconut.scoredPoint()) {
            score += darts::SCORE_INCREMENT;
        }

        drawSprites();
        checkForCollisions();
    }  // End of the game loop
} // End of the 'run' function

// END OF FILE
