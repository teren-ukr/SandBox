#pragma once

#include <vector>
#include "Tile.h"



class Grid {
public:

    Grid();
    Grid(std::vector<std::vector<Tile>> grid);

    void update();

    Tile* find_tile(uint16_t x, uint16_t y);

    std::vector<Tile>& operator[](size_t index);
    const std::vector<Tile>& operator[](size_t index) const;

    std::vector<std::vector<Tile>>::iterator begin();
    std::vector<std::vector<Tile>>::iterator end();
    std::vector<std::vector<Tile>>::const_iterator begin() const;
    std::vector<std::vector<Tile>>::const_iterator end() const;

    std::vector<std::vector<Tile>> &get_Grid() {
        return grid;
    }

    int row_size() {
        return grid.size();
    }

    int col_size() {
        return grid[0].size();
    }

    
private:
    std::vector<std::vector<Tile>> grid;
};
