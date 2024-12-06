#pragma once
#include <SFML/Graphics.hpp>



enum ETYPE {
    None,
    Colision,
    Sand,
    Water
};


class Tile : public sf::Drawable {
public:
    sf::RectangleShape rect;

    ETYPE type = ETYPE::None;
 
    uint16_t grid_x;
    uint16_t grid_y;

    bool right_move = true;

    float count = 0;

    Tile();
    Tile(float x, float y, float scale);
    Tile(float x, float y, float scale, uint16_t grid_x, uint16_t grid_y);


    void setPosition(float x, float y);
    void setColor(const sf::Color& color);
    void set_type(ETYPE type);


private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
