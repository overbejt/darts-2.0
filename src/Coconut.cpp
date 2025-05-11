#include <iostream>
#include <random>
#include "darts/Coconut.h"

// Constructor
Coconut::Coconut() : img(), texture(), sprite(texture) {
    this->init();
}  // End of the 'constructor'

void Coconut::init() {
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
    // sprite.setPosition({0.f, (647-125)});
    // sprite.setPosition({20.f, (647-125)});
    // x, y or y,x
    // sprite.setPosition({(647-125), 20.f});
    // sprite.setPosition({(647-125), 70.f});
    // sprite.setPosition({(647-125-100), 70.f});
    // sprite.setPosition({300, 70});  // last known good
    // sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

    // tmp for testing
    sprite.setPosition({600, 70});
}  // End of the 'init' funciton

void Coconut::setMaxHeight(int maxHeight) {
    this->maxHeight = maxHeight;
}  // End of the 'setMaxHeight' function

void Coconut::setMaxWidth(int maxWidth) {
    this->maxWidth = maxWidth;
}  // End of the 'setMaxWidth' function

sf::Sprite Coconut::getSprite() {
    return sprite;
}  // End of the 'getSprite' function

int Coconut::getRandomX() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0, maxWidth);
    return dis(gen);
}  // End of the 'getRandomX' function

void Coconut::move(float ammount) {    
    float ammountToMove = ammount < maxHeight ? ammount : 0;
    // std::cout << ammountToMove << std::endl;
    sprite.move({0.f, ammountToMove});
    sf::Vector2f position = sprite.getPosition();
    if (position.y > maxHeight) {
        // int randomX = getRandomX();
        // position.x = randomX;
        position.y = 0;
        sprite.setPosition(position);
    }
    std::cout << "x: " << position.x << " y: " << position.y << std::endl;
}  // End of the 'move' function

// END OF FILE
