#ifndef APP_H
#define APP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include "utils.h"

using SpritePtr = std::optional<sf::Sprite>;

class App {
    private:
        sf::RenderWindow window;
        SpritePtr background;
        void init();
        void load_background(SpritePtr& sprite, const std::string& file_path);
    public:        
        App();  // Constructor
        void run();

};

#endif /* APP_H */

// END OF FILE
