#include <iostream>
#include "darts/utils.h"
#include "darts/app.h"

// Constructor
App::App() {
    init();
}  // End of the 'constructor'

void App::init() {
    window = sf::RenderWindow(sf::VideoMode({1200, 647}), "Darts");
    
    // call it once after creating the window
    window.setVerticalSyncEnabled(true); 
    window.setFramerateLimit(60);

    // load_background(background, "assets/images/jungle-palm-trees.png");
    load_background(background, BG_IMAGE);
}  // End of the 'init' function

void App::load_background(SpritePtr& sprite, const std::string& file_path) {
    // 1. Load the image
    sf::Image img;
    if (!img.loadFromFile(file_path)) {
        std::cerr << "Error loading image!" << std::endl;
        return;
    }

    // 2. Create a texture
    sf::Texture texture;
    if (!texture.loadFromImage(img)) {
        std::cerr << "Error loading texture!" << std::endl;
        return;
    }

    sprite->setTexture(texture, false);
}  // End of the 'load_background' function

void App::run() {
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Aufweidersehen" << std::endl;
                window.close();
            }
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // Draw the background
        window.draw(background);

        // end the current frame
        window.display();
    }
} // End of the 'run' function

// END OF FILE
