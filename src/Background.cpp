#include <iostream>
#include "darts/Background.h"

// Constructor
Background::Background(std::string img_path) {
    this->img_path = img_path;
    this->init();
}  // End of the 'constructor'

void Background::init() {
    // 1. Load the image
    if (!img.loadFromFile(img_path)) {
        std::cerr << "Error loading image!" << std::endl;
        return;
    }
    
    // 2. Create a texture
    if (!texture.loadFromImage(img)) {
        std::cerr << "Error loading texture!" << std::endl;
        return;
    }
    
    // 3. Setup the sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {1200, 647}));
}  // End of the 'init' funciton

void Background::move(float ammount) {
    return;  // Do nothing 
}  // End of the 'move' function

// END OF FILE
