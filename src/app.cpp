#include <iostream>
#include <optional>
#include "darts/utils.h"
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
        std::cout << "COLLISION" << std::endl;
    }
}  // End of the 'checkForCollisions' function

void App::run() {
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                // left key is pressed: move our character
                koala.move(-15.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                // right key is pressed: move our character
                koala.move(15.f);
            }
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Goodbye" << std::endl;
                window.close();  // breaks the loop
            }
        }
        
        drawSprites();
        checkForCollisions();
    }
} // End of the 'run' function

// END OF FILE
