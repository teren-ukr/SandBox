#include "Tile.h"

Tile::Tile()
    : rect(), grid_x(0), grid_y(0) {
    // Default constructor logic (if any)
}

Tile::Tile(float x, float y, float scale)
    : rect(), grid_x(0), grid_y(0) {
    rect.setSize(sf::Vector2f(scale, scale));
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::White);
    rect.scale(sf::Vector2f(0.9f, 0.9f));
}

Tile::Tile(float x, float y, float scale, uint16_t grid_x, uint16_t grid_y)
    : rect(), grid_x(grid_x), grid_y(grid_y) {
    rect.setSize(sf::Vector2f(scale, scale));
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::White);
    rect.scale(sf::Vector2f(0.95f, 0.95f));
}




void Tile::setPosition(float x, float y) {
    rect.setPosition(x, y);
}

void Tile::setColor(const sf::Color& color) {
    rect.setFillColor(color);
}

void Tile::set_type(ETYPE type) {
    this->type = type;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}
