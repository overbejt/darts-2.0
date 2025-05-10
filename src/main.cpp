#include <iostream>
#include "darts/app.h"

int main(int argc, char** argv) {

    std::cout << "Howdy" << std::endl;

    // sf::Window window(sf::VideoMode({1200, 647}), "Darts");  // How was thier instructions wrong?
    // sf::RenderWindow window(sf::VideoMode({1200, 647}), "Darts");

    // // call it once after creating the window
    // window.setVerticalSyncEnabled(true); 
    // window.setFramerateLimit(60);

    // // 1. Load the image
    // sf::Image bg_image;
    // if (!bg_image.loadFromFile("assets/images/jungle-palm-trees.png")) {
    //     std::cerr << "Error loading image!" << std::endl;
    //     return 1;
    // }

    // // 2. Create a texture
    // sf::Texture bg_texture;
    // if (!bg_texture.loadFromImage(bg_image)) {
    //     std::cerr << "Error loading texture!" << std::endl;
    //     return 1;
    // }

    // // 3. Create a sprite
    // sf::Sprite background(bg_texture);

    // // run the program as long as the window is open
    // while (window.isOpen()) {
    //     // check all the window's events that were triggered since the last iteration of the loop
    //     while (const std::optional event = window.pollEvent()) {
    //         // "close requested" event: we close the window
    //         if (event->is<sf::Event::Closed>()) {
    //             std::cout << "Aufweidersehen" << std::endl;
    //             window.close();
    //         }
    //     }
        
    //     // clear the window with black color
    //     window.clear(sf::Color::Black);

    //     // draw everything here...
    //     // Draw the background
    //     window.draw(background); 

    //     // end the current frame
    //     window.display();
    // }

    App app;
    app.run();

    return 0;
}  // End of the 'main' function

// END OF FILE 
