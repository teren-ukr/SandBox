#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Grid.h"
#include "Settings.h"
#include <iostream>

#include <cstdlib>
#include <ctime>

//---------------------------------------------------------------------------------------------------------------
uint16_t mouse_x;
uint16_t mouse_y;

ETYPE Current_Spawn_Type;

//---------------------------------------------------------------------------------------------------------------
void update_mouse_pos(sf::RenderWindow& window) {
    mouse_x = sf::Mouse::getPosition(window).x;
    mouse_y = sf::Mouse::getPosition(window).y;
}

//---------------------------------------------------------------------------------------------------------------
// Перевірка, чи індекс знаходиться в межах допустимих значень
bool is_Valid_Index(int x, int y, Grid& grid) {
    return (x >= 0 && y >= 0 && x < grid.row_size() && y < grid.col_size());
}

//---------------------------------------------------------------------------------------------------------------
class Label :public sf::Drawable
{
public:

    sf::Font font;
    sf::Text text;


    Label(std::string string, uint16_t x, uint16_t y, sf::Color color, uint8_t CharacterSize) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Could not load font\n";
        }
        text.setFont(font);
        text.setString(string);
        text.setCharacterSize(CharacterSize);
        text.setFillColor(color);
        text.setPosition(x, y);
    }

    void set_text(std::string text) {
        this->text.setString(text);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(text, states);
    }

    
private:

};


class ElementButton
{
public:

    sf::Font font;
    sf::Text text;

    ElementButton() {};
    


};

//---------------------------------------------------------------------------------------------------------------
int8_t generateRandom(uint8_t chance) {
	// Генеруємо випадкове число від 0 до 99
	int randValue = rand() % 100;

    if (chance > 99)
        chance = 99;

	if (randValue < chance) {
		return 0; // 70% ймовірність
	}
	else {
		// Генеруємо ще одне випадкове число для визначення між 1 і -1
		return (rand() % 2 == 0) ? 1 : -1; // 30% ймовірність
	}
}

//---------------------------------------------------------------------------------------------------------------



void update(Grid& grid, Grid& bufGrid) {
     //Копіюємо поточну сітку в буферну
    
    bufGrid = grid;

    for (size_t x = 0; x < grid.row_size(); ++x) {
        for (size_t y = 0; y < grid.col_size(); ++y) {

            Tile& tile = grid[x][y];
            // Перевірка типу тайлу
            if (tile.type == ETYPE::Sand) {
                

                
                // Падіння вниз короче значення тепер зберігається, далі треба зробити оцюю затримку 
                if (is_Valid_Index(x, y + 1, grid) &&
                    grid[x][y + 1].type == ETYPE::None) {

                    bufGrid[x][y + 1].set_type(ETYPE::Sand);
                    bufGrid[x][y].set_type(ETYPE::None);

                }

                //зсипання вправо
                else if (is_Valid_Index(x + 1, y + 1, grid) &&
                    grid[x + 1][y + 1].type == ETYPE::None &&
                    is_Valid_Index(x + 1, y, grid) &&
                    grid[x + 1][y].type == ETYPE::None) {

                    bufGrid[x + 1][y + 1].set_type(ETYPE::Sand);
                    bufGrid[x][y].set_type(ETYPE::None);
                }

                //зсипання вліво
                else if (is_Valid_Index(x - 1, y + 1, grid) &&
                    grid[x - 1][y + 1].type == ETYPE::None &&
                    is_Valid_Index(x - 1, y, grid) &&
                    grid[x - 1][y].type == ETYPE::None) {

                    bufGrid[x - 1][y + 1].set_type(ETYPE::Sand);
                    bufGrid[x][y].set_type(ETYPE::None);
                }


                

            }

            if (tile.type == ETYPE::Water) {

                if (tile.right_move) {

                    if(is_Valid_Index(x, y + 1, grid) &&
                        grid[x][y + 1].type != ETYPE::None){

                        if (is_Valid_Index(x + 1, y, grid) &&
                            grid[x + 1][y].type == ETYPE::None) {

                            bufGrid[x + 1][y].set_type(ETYPE::Water);
                            bufGrid[x][y].set_type(ETYPE::None);
                        }
                    }
                    else {
                        if (is_Valid_Index(x, y + 1, grid) &&
                            grid[x][y + 1].type == ETYPE::None) {

                            bufGrid[x][y + 1].set_type(ETYPE::Water);
                            bufGrid[x][y].set_type(ETYPE::None);
                        }
                    }
                }

                //int rndNum = generateRandom(50);
                //std::cout << rndNum << "\n";

             
                int rndNum = generateRandom(70);
                std::cout << "rndNum for (" << x << "," << y << "): " << rndNum << "\n";

                



				/*if (is_Valid_Index(x, y + 1, grid) &&
					grid[x][y + 1].type == ETYPE::None) {

					bufGrid[x][y + 1].set_type(ETYPE::Water);
					bufGrid[x][y].set_type(ETYPE::None);
				}

				else if (is_Valid_Index(x, y - 1, grid) &&
					grid[x][y - 1].type == ETYPE::None) {

					    if (is_Valid_Index(x + rndNum, y, grid) &&
						    grid[x + rndNum][y].type == ETYPE::None) {

						    bufGrid[x + rndNum][y].set_type(ETYPE::Water);
						    bufGrid[x][y].set_type(ETYPE::None);
					    }

				}*/





                //ЗЖИРАЄ КЛІТИНКИ І ТРОХИ ЛАГАЄ

                /*if (is_Valid_Index(x, y + 1, grid) &&
                    grid[x][y + 1].type == ETYPE::None) {

                    bufGrid[x][y + 1].set_type(ETYPE::Water);
                    bufGrid[x][y].set_type(ETYPE::None);

                }*/


                ////зсипання вправо
                //else if (is_Valid_Index(x + 1, y + 1, grid) &&
                //    grid[x + 1][y + 1].type == ETYPE::None &&
                //    is_Valid_Index(x + 1, y, grid) &&
                //    grid[x + 1][y].type == ETYPE::None) {

                //    bufGrid[x + 1][y + 1].set_type(ETYPE::Water);
                //    bufGrid[x][y].set_type(ETYPE::None);
                //}

                ////зсипання вліво
                //else if (is_Valid_Index(x - 1, y + 1, grid) &&
                //    grid[x - 1][y + 1].type == ETYPE::None &&
                //    is_Valid_Index(x - 1, y, grid) &&
                //    grid[x - 1][y].type == ETYPE::None) {

                //    bufGrid[x - 1][y + 1].set_type(ETYPE::Water);
                //    bufGrid[x][y].set_type(ETYPE::None);
                //}


                //short int move_rand = (std::rand() % 2) * 2 - 1;
               /* if (is_Valid_Index(x + move_rand, y, grid) &&
                    grid[x + move_rand][y].type == ETYPE::None &&

                    is_Valid_Index(x - move_rand, y, grid) &&
                    grid[x - move_rand][y].type == ETYPE::None &&

                    is_Valid_Index(x + move_rand, y + 1, grid) &&
                    grid[x + move_rand][y + 1].type != ETYPE::None  ) {


                    bufGrid[x + move_rand][y].set_type(ETYPE::Water);
                    bufGrid[x][y].set_type(ETYPE::None);
                }*/





            }

            
        }
    }

    // Оновлюємо основну сітку з буферної
    grid = bufGrid;
}



int main() {
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Grid Example");
    window.setFramerateLimit(Max_FPS);
    //----------------------------------------------------------------------------------

    Grid grid;
    Grid bufGrid;
    //----------------------------------------------------------------------------------

    bool is_paint = false;
    int radius = 0;
    //----------------------------------------------------------------------------------

    sf::Clock FPStimer;
    uint16_t FPS = 0;
    Label fps_label("", 5, 5, sf::Color::Red, 15);
    //----------------------------------------------------------------------------------

    Current_Spawn_Type = ETYPE::Sand;
    //----------------------------------------------------------------------------------Ініціалізуємо генератор випадкових чисел

    std::srand(std::time(nullptr));
    //----------------------------------------------------------------------------------

    while (window.isOpen()) {

        sf::Event event;
        update_mouse_pos(window);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            //    Tile* tile = grid.find_tile(mouse_x, mouse_y);

            //    // Використання перевірки перед доступом до елементів вектора
            //    if (tile && is_Valid_Index(tile->grid_x, tile->grid_y, grid)) {
            //        tile->set_type(Current_Spawn_Type);
            //    }

            //}

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !is_paint)
			{
                is_paint = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && is_paint)
			{
				std::cout << "released" << "\n";
                is_paint = false;
			}

			if (is_paint) {

    //            Tile* tile = grid.find_tile(mouse_x, mouse_y);
				//// Використання перевірки перед доступом до елементів вектора
				//if (tile && is_Valid_Index(tile->grid_x, tile->grid_y, grid) && (tile->type == ETYPE::None || Current_Spawn_Type == ETYPE::None )) {
				//	tile->set_type(Current_Spawn_Type);
				//}

                int X = static_cast<int>(mouse_x / Global_Scale);
                int Y = static_cast<int>(mouse_y / Global_Scale);
                if (is_Valid_Index(X, Y, grid)) {

                                   
                    for (int y = -radius; y <= radius; y++) {
                        for (int x = -radius; x <= radius; x++) {
                            if (x * x + y * y <= radius * radius) {
                                int drawX = X + x;
                                int drawY = Y + y;
                                if (is_Valid_Index(drawX, drawY, grid)) {
                                    grid[drawX][drawY].type = Current_Spawn_Type;
                                   
                                }
                            }
                        }
                    }


                    //grid[X][Y].type = Current_Spawn_Type;
                }

			}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                Current_Spawn_Type = ETYPE::None;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                Current_Spawn_Type = ETYPE::Colision;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                Current_Spawn_Type = ETYPE::Sand;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                Current_Spawn_Type = ETYPE::Water;
            }

               



        }

        window.clear(sf::Color::Black);

        update(grid, bufGrid);
        grid.update();

        for (const auto& row : grid) {
            for (const auto& tile : row) {
                if(tile.type != ETYPE::None)
                    window.draw(tile);
            }
        }
        window.draw(fps_label);
        

        window.display();


        FPS++;
        if (FPStimer.getElapsedTime().asMilliseconds() >= 1000) {
            std::cout << "FPS: " << FPS << std::endl;
            fps_label.set_text("fps:" + std::to_string(FPS));

            FPS = 0;
            FPStimer.restart();
        }

    }

    return 0;
}
