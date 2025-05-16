#include <iostream>
#include <random>
#include "darts/Coconut.h"

// Constructor
Coconut::Coconut(std::string image_path) {
    img_path = image_path;
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
    // If you use a TextureRect bigger than the image it renders weird
    sprite.setTextureRect(sf::IntRect({0, 0}, {imgWidth, imgHeight}));

    sf::Vector2f position;
    position.x = getRandomX();
    position.y = 0.f;
    sprite.setPosition(position);

    // TODO tmp for testing
    // sprite.setPosition({600, 70});    
    // sprite.setPosition({600, static_cast<float>(-imgHeight)});
}  // End of the 'init' funciton

void Coconut::setMaxHeight(int maxHeight) {
    this->maxHeight = maxHeight;
}  // End of the 'setMaxHeight' function

void Coconut::setMaxWidth(int maxWidth) {
    this->maxWidth = maxWidth;
}  // End of the 'setMaxWidth' function

float Coconut::getRandomX() {
    std::random_device rd;
    std::mt19937 gen(rd());
    float max = static_cast<float>(maxWidth - imgWidth);
    float min = static_cast<float>(imgWidth * 2);
    std::uniform_real_distribution<float> dis(min, max);    
    return dis(gen);
}  // End of the 'getRandomX' function

void Coconut::move(float ammount) {    
    float ammountToMove = ammount < maxHeight ? ammount : 0;
    // std::cout << ammountToMove << std::endl;
    sprite.move({0.f, ammountToMove});
    sf::Vector2f position = sprite.getPosition();
    if (position.y > (maxHeight + imgHeight)) {
        position.y = 0;
        position.x = getRandomX();
        sprite.setPosition(position);
    }
}  // End of the 'move' function

bool Coconut::scoredPoint() {
    sf::Vector2f position = sprite.getPosition();    
    // The window size is 647, but the sprite moves in multiples 
    // of 5.  Have to padd it so that they match up
    // int padd = 4;
    int padd = 2;
    if ((position.y + padd) == maxHeight) {
        return !collision;
    } else {
        // If it hasn't reach the bottom yet then there's 
        // no way the play can score
        return false;
    }
}  // End of the 'scoredPoint' function

// END OF FILE
