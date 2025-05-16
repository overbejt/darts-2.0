#ifndef KOALA_H
#define KOALA_H
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"
#include "EzSprite.h"

class Koala : public EzSprite {
    protected:
        void init() override;
    public:
        Koala(std::string image_path);
        void move(float ammount) override;
};  // End of the 'Koala' class

#endif /* KOALA_H */

// END OF FILE
