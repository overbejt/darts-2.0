#include <iostream>
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
}  // End of the 'init' function

void App::run() {
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Goodbye" << std::endl;
                window.close();  // breaks the loop
            }
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // Draw the background
        window.draw(background.getSprite());

        // end the current frame
        window.display();
    }
} // End of the 'run' function

// END OF FILE
