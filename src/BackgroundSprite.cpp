#include <iostream>
#include "darts/BackgroundSprite.h"

// Constructor
BackgroundSprite::BackgroundSprite() : img(), texture(), sprite(texture) {
    this->init();
}  // End of the 'constructor'

void BackgroundSprite::init() {
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

sf::Sprite BackgroundSprite::getSprite() {
    return sprite;
}  // End of the 'getSprite' function

// END OF FILE
