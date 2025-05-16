#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"
#include "EzSprite.h"

class Background : public EzSprite {
    protected:
        void init() override;
    public:
        Background(std::string img_path);
        void move(float ammount) override;
};  // End of the 'Background' class

#endif /* BACKGROUND_H */

// END OF FILE
