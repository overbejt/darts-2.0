#include <iostream>
#include "darts/Koala.h"

// Constructor
Koala::Koala() : img(), texture(), sprite(texture) {
    this->init();
}  // End of the 'constructor'

void Koala::init() {
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
    // TODO avoid magic numbers    
    sprite.setTextureRect(sf::IntRect({0, 0}, {125, 125}));
    // Perfect.  Just a little right of center
    sprite.setPosition({600.f, (647-125)});
}  // End of the 'init' funciton

sf::Sprite Koala::getSprite() {
    return sprite;
}  // End of the 'getSprite' function

void Koala::move(float ammount) {
    sprite.move({ammount, 0.f});
}  // End of the 'move' function

// END OF FILE
