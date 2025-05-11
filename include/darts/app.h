#ifndef APP_H
#define APP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "utils.h"
#include "Background.h"
#include "Koala.h"
#include "Coconut.h"

class App {
    private:
        sf::RenderWindow window;
        Background background;
        Koala koala;
        Coconut coconut;
        void init();
        void drawSprites();
        void checkForCollisions();
    public:        
        App();  // Constructor
        void run();
};

#endif /* APP_H */

// END OF FILE
