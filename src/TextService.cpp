#include <iostream>
#include <sstream>
#include "darts/TextService.h"

TextService::TextService() {
    this->init();
}  // End of the constructor

void TextService::init() {
    if (!regFont.openFromFile(darts::font::FONT_REGULAR)) {
        std::cerr << "Failed to load regular font!" << std::endl;
    }
    if (!boldFont.openFromFile(darts::font::FONT_BOLD)) {
        std::cerr << "Failed to load bold font!" << std::endl;
    }
}  // End of the 'init' function

void TextService::drawGameOver(sf::RenderWindow& window) {
    sf::Text text(regFont);
    text.setString("Game Over");
    text.setCharacterSize(darts::TEXT_LG);
    setDefaultColor(text);
    
    // Move it to the center of the screen
    const sf::Vector2u windowSize = window.getSize();
    float newX = static_cast<float>(windowSize.x / 2.0);
    float newY = static_cast<float>(windowSize.y / 2.0);
    newX -= 280;
    newY -= 200;
    text.setPosition({newX, newY});

    window.draw(text);
}  // End of the 'showGameOver' function

void TextService::drawLives(sf::RenderWindow& window, int livesVal) {
    sf::Text lives(boldFont);
    lives.setStyle(sf::Text::Bold);
    
    std::stringstream ss;
    // padd start of string with spaces so it 'floats right' the text
    if (livesVal < darts::MAX_LIVES) {
        for (int j = 0; j <= (darts::MAX_LIVES - livesVal); j++) {
            ss << " ";
        }
    }
    for (int i = 0; i < livesVal; i++) {
        ss << "X";
    }

    lives.setString(ss.str());
    lives.setCharacterSize(darts::TEXT_SM);
    setDefaultColor(lives);

    // put it top right
    const sf::Vector2u windowSize = window.getSize();
    float newX = static_cast<float>(windowSize.x / 2.0);
    float newY = static_cast<float>(windowSize.y / 2.0);
    newX += 480;
    newY -= 320;
    lives.setPosition({newX, newY});

    window.draw(lives);
}  // End of the 'updateLives' function

void TextService::drawScore(sf::RenderWindow& window, int scoreVal) {
    sf::Text score(boldFont);
    score.setStyle(sf::Text::Bold);

    std::stringstream ss;
    ss << "Score: " << scoreVal;
    score.setString(ss.str());
    score.setCharacterSize(darts::TEXT_SM);
    setDefaultColor(score);
   
    // put it top left
    const sf::Vector2u windowSize = window.getSize();
    float newX = static_cast<float>(windowSize.x / 2.0);
    float newY = static_cast<float>(windowSize.y / 2.0);
    newX -= 585;
    newY -= 320;
    score.setPosition({newX, newY});

    window.draw(score);
}  // End of the 'updateScore' function

void TextService::drawPaused(sf::RenderWindow& window) {
    sf::Text paused(regFont);
    paused.setString("Paused...");
    paused.setCharacterSize(darts::TEXT_LG);
    setDefaultColor(paused);

    // Move it to the center of the screen
    const sf::Vector2u windowSize = window.getSize();
    float newX = static_cast<float>(windowSize.x / 2.0);
    float newY = static_cast<float>(windowSize.y / 2.0);
    newX -= 200; 
    newY -= 200;
    paused.setPosition({newX, newY});
    
    window.draw(paused);
}  // End of the 'drawPaused' function

void TextService::setDefaultColor(sf::Text& textObj) {
    textObj.setFillColor(sf::Color::Black);
}  // End of the 'setDefaultColor' function

// END OF FILE
