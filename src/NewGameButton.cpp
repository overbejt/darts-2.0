#include <iostream>
#include "darts/NewGameButton.h"

NewGameButton::NewGameButton() : rect(rSize) {
    this->init();
}  // End of the 'NewGameButton' function

void NewGameButton::init() {
    if (!regFont.openFromFile(FONT_REGULAR)) {
        std::cerr << "Failed to load regular font!" << std::endl;
    }
    
    rect.setSize({200.f, 100.f});
    rect.setFillColor(sf::Color::Black);
}  // End of the 'init' function

void NewGameButton::drawRect(sf::RenderWindow& window) {

    const sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());
    sf::Vector2f rectPos;
    rectPos.x = windowSize.x / 2.0;
    rectPos.y = windowSize.y / 2.0;
    rectPos.x -= 240.f;
    rectPos.y += 25.f;
    rect.setPosition(rectPos);
    window.draw(rect);

    // Handle Text position
    sf::Vector2f textPos;    
    textPos.x = windowSize.x / 2.0;
    textPos.y = windowSize.y / 2.0;
    textPos.x += -210.f;
    textPos.y += 40.f;

    sf::Text text(regFont);
    text.setFont(regFont);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(TEXT_MD);
    text.setString(msg);
    text.setPosition(textPos);
    window.draw(text);
}  // End of the 'drawRect' function

sf::FloatRect NewGameButton::getGlobalBounds() {
    return rect.getGlobalBounds();
}  // End of the 'getGlobalBounds' function

// END OF FILE
