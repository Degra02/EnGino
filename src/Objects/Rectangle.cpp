#include "../../include/Rectangle.h"

namespace phy_eng {


    Rectangle::Rectangle() : Object(){
        for (int i = 0; i < 4; ++i) {
            this->corners[i] = vector2();
        }
    }

    Rectangle::Rectangle(float l, float h) {
        this->setLenght(l);
        this->setHeight(h);
    }

    void Rectangle::setLenght(float l) {
        this->lenght = l;
    }

    void Rectangle::setHeight(float h) {
        this->height = h;
    }

    float Rectangle::getLenght() const {
        return this->lenght;
    }

    float Rectangle::getHeight() const {
        return this->height;
    }
} // phy_eng