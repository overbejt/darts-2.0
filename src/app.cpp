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

    // Make the coconut fall
    coconut.move(5);

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
            audio.playCollision();
        }
    } else {
        // If the collistion flag was toggled, reset it now that there's no longer a colision
        if (coconut.collision) {
            coconut.collision = false;
        }
    }
}  // End of the 'checkForCollisions' function

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
    audio.playThemeSong();
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
                pauseGame();
            }

            // Prevent cheating by pausing and moving then resuming
            if (!isPaused) {
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
        
        // escape early if paused
        if (isPaused) {
            continue;
        }

        drawSprites();
        checkForCollisions();
    }
} // End of the 'run' function

// END OF FILE
