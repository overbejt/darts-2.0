#ifndef APP_H
#define APP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "utils.h"
#include "BackgroundSprite.h"

class App {
    private:
        sf::RenderWindow window;
        BackgroundSprite background;
        void init();
    public:        
        App();  // Constructor
        void run();
};

#endif /* APP_H */

// END OF FILE
