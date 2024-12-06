#include "Grid.h"
#include <iostream>
#include "Settings.h"

//-----------------------------------------------------------------------------------------------------
Grid::Grid() : grid(Grid_Width, std::vector<Tile>(Grid_Height))
{
    for (size_t i = 0; i < Grid_Width; ++i)
    {
        for (size_t j = 0; j < Grid_Height; ++j)
        {
            float x = static_cast<float>(i * Global_Scale);
            float y = static_cast<float>(j * Global_Scale);
            grid[i][j] = Tile(x, y, Global_Scale, i, j);
        }
    }
}



Grid::Grid(std::vector<std::vector<Tile>> grid)
{
    this->grid = grid;
}


//-----------------------------------------------------------------------------------------------------
void Grid::update() 
{
    for (auto& row : grid)
    {
        for (auto& tile : row)
        {

            //switch (tile.type) 
            //{
            //case ETYPE::None:
            //    tile.phisics.str = "1488one";
            //    tile.setColor(sf::Color::Black);
            //    tile.phisics.weight = 1;
            //    

            //    tile.teststr = "its none";
            //    break;

            //case ETYPE::Colision:
            //    tile.phisics.str = "Colision";
            //    tile.setColor(sf::Color::Red);
            //    tile.phisics.weight = 1;
            //    

            //    tile.teststr = "its colision";
            //    break;

            //case ETYPE::Sand:
            //    tile.phisics.str = "Sand";
            //    tile.setColor(sf::Color::Yellow);
            //    tile.phisics.weight = 0.1;
            //    

            //    tile.teststr = "its sand";
            //    break;

            //default:
            //    tile.setColor(sf::Color::Green);
            //    break;
            //}


            if (tile.type == ETYPE::Sand) {
                tile.setColor(sf::Color::Yellow);
            }

            else if (tile.type == ETYPE::Colision)
            {
                tile.setColor(sf::Color::Red);
            }

            else if (tile.type == ETYPE::Water)
            {
                tile.setColor(sf::Color::Blue);
            }





        }
    }
}


//-----------------------------------------------------------------------------------------------------
 bool is_Valid_Index(int x, int y, std::vector<std::vector<Tile>> grid) {
        return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
    }

Tile* Grid::find_tile(uint16_t x, uint16_t y) {
    int X = static_cast<int>(x / Global_Scale);
    int Y = static_cast<int>(y / Global_Scale);

    //std::cout << X << " " << Y << "\n";////////////////////////////////////////////////////////////////////////////////////////////

    //перевірка на те, чи шукані координати належать сітці
    if(is_Valid_Index(X,Y,grid))
        return &grid[X][Y];

    return nullptr;
}

//-----------------------------------------------------------------------------------------------------
std::vector<Tile>& Grid::operator[](size_t index) {
    return grid[index];
}


const std::vector<Tile>& Grid::operator[](size_t index) const {
    return grid[index];
}


//-----------------------------------------------------------------------------------------------------
std::vector<std::vector<Tile>>::iterator Grid::begin() {
    return grid.begin();
}

std::vector<std::vector<Tile>>::iterator Grid::end() {
    return grid.end();
}

std::vector<std::vector<Tile>>::const_iterator Grid::begin() const {
    return grid.begin();
}

std::vector<std::vector<Tile>>::const_iterator Grid::end() const {
    return grid.end();
}
