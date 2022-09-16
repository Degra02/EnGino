//
// Created by degra on 9/9/22.
//

#include "../../include/Rectangle.h"

namespace pheng {
    Rectangle::Rectangle() {
        b = 0, h = 0;
        rectangleShape = sf::RectangleShape();
    }

    Rectangle::Rectangle(float b, float h) {
        this->b = b, this->h = h;
        initDrawable();
    }

    void Rectangle::initDrawable() {
        rectangleShape = sf::RectangleShape({b, h});
        rectangleShape.setOrigin({b / 2, h / 2});
        rectangleShape.setOutlineColor(sf::Color::White);
        rectangleShape.setOutlineThickness(4);
        rectangleShape.setFillColor(sf::Color::Black);
    }

    sf::Drawable& Rectangle::getDrawable() {
        return rectangleShape;
    }

    vector2 Rectangle::getCenter() {
        return {Position.getX(), Position.getY()};
    }

    void Rectangle::applyChange() {
        rectangleShape.setPosition(Position.getX(), Position.getY());
    }


} // pheng