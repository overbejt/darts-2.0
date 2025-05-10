#include <iostream>
#include <SFML/Window.hpp>

int main(int argc, char** argv) {

    std::cout << "Howdy" << std::endl;

    sf::Window window(sf::VideoMode({800, 600}), "Darts");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }

    return 0;
}  // End of the 'main' function

// END OF FILE 
