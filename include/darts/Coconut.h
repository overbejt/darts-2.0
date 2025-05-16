#ifndef COCONUT_H
#define COCONUT_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"
#include "EzSprite.h"

class Coconut : public EzSprite {
    protected:
        const int imgHeight = 82;
        const int imgWidth = 82;
        int maxHeight;
        int maxWidth;        
        void init() override;
    public:
        Coconut(std::string image_path);
        bool collision = false;
        void setMaxHeight(int maxHeight);
        void setMaxWidth(int maxWidth);
        float getRandomX();
        void move(float ammount) override;
        bool scoredPoint();
};  // End of the 'Coconut' class

#endif /* COCONUT_H */

// END OF FILE
