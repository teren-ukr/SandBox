//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//
///// <summary>
///// 4:20 - back
///// </summary>
//
//using namespace sf;
//class Tile;
//
////--------------------------------------------------------------------------------------------------------------------
//bool check_play = false;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t Screen_Width = 800;
//uint16_t Screen_Height = 600;
//uint8_t  Pixel_Scale = 6;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t Grid_Size = (Screen_Width * Screen_Height) / Pixel_Scale;
//uint16_t Grid_Width = Screen_Width / Pixel_Scale;
//uint16_t Grid_Height = Screen_Height / Pixel_Scale;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t mouse_x;
//uint16_t mouse_y;
//
////--------------------------------------------------------------------------------------------------------------------
//std::vector<int> Grid    (Grid_Size);
//std::vector<int> GridC   (Grid_Size);
//
//std::vector<Tile> Tiles = {};
//
////--------------------------------------------------------------------------------------------------------------------
//class Tile : public sf::Drawable{
//public:
//    int ID = 0;
//    
//    sf::RectangleShape rect;
//
//    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
//    {
//        target.draw(rect, states);
//    }
//
//private:
//
//};
//
//
////--------------------------------------------------------------------------------------------------------------------
//void fill_screen() {//заповнює сітку плитками
//   
//    int Current_ID = 0;
//    for (size_t H = 0; H < Grid_Height; H++)
//    {
//        for (size_t W = 0; W < Grid_Width; W++)
//        {
//
//            Tile tile;
//
//            tile.ID = Current_ID;
//
//            tile.rect.setPosition((W * (Pixel_Scale + 1)), (H * (Pixel_Scale + 1)));
//            tile.rect.setSize(sf::Vector2f(Pixel_Scale, Pixel_Scale));
//
//            Tiles.push_back(tile);
//
//            Current_ID++;
//        }
//       
//    }
//
//}
//
////--------------------------------------------------------------------------------------------------------------------
//void update() {//оновлює сітку
//    int picked = 0;
//    for (size_t H = 0; H < Grid_Height; H++)
//    {
//        for (size_t W = 0; W < Grid_Width; W++)
//        {
//
//    //        if (Grid[picked] == 1 && GridC[picked] == 0) 
//    //        {
//
//    //            if (Grid[picked + Grid_Width] == 0)
//    //            {
//
//    //                Grid[picked] = 0;
//    //                GridC[picked] = 0;
//
//    //                Grid[picked + Grid_Width] = 1;
//    //                GridC[picked + Grid_Width] = 1;
//
//    //            }
//    //           
//    //        }
//    //        if (Grid[picked] == 1 && GridC[picked] == 0 && Grid[picked + Grid_Width] == 5)
//    //        {
//
//    //            /*GridC[picked + Grid_Width] = 0;
//    //            GridC[picked + Grid_Width] = 0;*/
//
//    //            Grid[picked + Grid_Width] = 1;
//    //            GridC[picked + Grid_Width] = 1;
//
//				//Grid[picked] = 1;
//				//GridC[picked] = 1;
//
//    //            
//
//    //            std::cout << "negr";
//    //        }
//
//            if (Grid[picked] == 1 && GridC[picked] == 0 && Grid[picked + Grid_Width ]!=3)
//            {
//                
//				
//
//                Grid[picked] = 0;
//                GridC[picked] = 0;
//
//                Grid[picked + Grid_Width] = 1;
//                GridC[picked + Grid_Width] = 1;
//
//            }
//
//
//
//            picked++;
//        }
//    }
//}
//
//
////--------------------------------------------------------------------------------------------------------------------
//void set_tiles() 
//{
//
//    int picked = 0;
//    for (int H = 0; H < Grid_Height; H++)
//    {
//        for (int W = 0; W < Grid_Width; W++)
//        {
//            /*for (Tile tile : Tiles)
//                if (tile.ID == picked)
//                {
//                    tile.Material = Grid[picked];
//                }*/
//
//            Tiles[picked].ID = Grid[picked];
//
//            picked++;
//        }
//
//    }
//}
//
////--------------------------------------------------------------------------------------------------------------------
//void clear_grid() 
//{
//    for (size_t i = 0; i < Grid_Size; i++)
//    {
//        GridC[i] = 0;
//    }
//}
//
////--------------------------------------------------------------------------------------------------------------------
//int main()
//{
//    RenderWindow window(VideoMode(Screen_Width, Screen_Height), L"SandBox", Style::Default);
//    window.setVerticalSyncEnabled(true);
//
//    window.setFramerateLimit(720);
//   
//
//
//
//
//	fill_screen();
//
//    Grid[0] = 1;
//    Grid[3] = 1;
//
//
//    //colision line
//    for (size_t i = 0; i < (Screen_Width / Pixel_Scale); i++)
//    {
//        Grid[i + ((Screen_Width / Pixel_Scale) * 10)] = 3;
//       
//    }
//
//    Grid[3 + ((Screen_Width / Pixel_Scale) * 10)] = 5;
//	
//
//    sf::View view = window.getDefaultView();
//
//    bool is_spawn = false;
//
//    while (window.isOpen())
//    {
//        Event event;
//        mouse_x = sf::Mouse::getPosition(window).x;
//        mouse_y = sf::Mouse::getPosition(window).y;
//
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//
//            //if (event.type == sf::Event::Resized) {
//            //    // resize my view
//            //    view.setSize({
//            //            static_cast<float>(event.size.width),
//            //            static_cast<float>(event.size.height)
//            //        });
//            //    window.setView(view);
//            //    // and align shape
//            //}
//
//            if (event.type == sf::Event::Resized)
//            {
//                // update the view to the new size of the window
//                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
//                window.setView(sf::View(visibleArea));
//            }
//
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && event.type == sf::Event::KeyPressed)
//            {
//                
//                if (check_play) {
//					check_play = false;
//                    std::cout << "game play"<<std::endl;
//                }
//                else {
//                    check_play = true;
//                    std::cout << "game pause" << std::endl;
//                }
//
//            }
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !is_spawn)
//            {
//                is_spawn = true;
//            }
//            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && is_spawn)
//            {
//                std::cout << "released" << "\n";
//                is_spawn = false;
//            }
//
//			if (is_spawn) {
//				int grid_x = (mouse_x - 25) / Pixel_Scale;
//				int grid_y = (mouse_y - 10) / Pixel_Scale;
//				int target = (grid_x)+(grid_y)*Grid_Width;
//
//				std::cout << "Mouse X: " << mouse_x << ", Mouse Y: " << mouse_y << std::endl;
//				std::cout << "Grid X: " << grid_x << ", Grid Y: " << grid_y << std::endl;
//				std::cout << "Target index: " << target << std::endl;
//
//				if (target >= 0 && target < Grid_Size)  // Ensure the target is within bounds
//				{
//					Grid[target] = 0;
//					GridC[target] = 0;
//
//					if (target + Grid_Width < Grid_Size) // Ensure the target below is within bounds
//					{
//						Grid[target] = 1;
//						GridC[target] = 1;
//					}
//				}
//			}
//
//
//        }
//
//        window.clear(Color::Black);
//
//		
//			clear_grid();
//
//            if (check_play) {
//                update();
//            }
//
//			set_tiles();
//
//			for (Tile& tile : Tiles)
//			{
//				if (tile.ID == 0)
//					tile.rect.setFillColor(sf::Color::White);
//				if (tile.ID == 1)
//					tile.rect.setFillColor(sf::Color::Green);
//				if (tile.ID == 3)
//					tile.rect.setFillColor(sf::Color::Red);
//
//				if (tile.ID == 4)
//					tile.rect.setFillColor(sf::Color::Magenta);
//				if (tile.ID == 5)
//					tile.rect.setFillColor(sf::Color::Blue);
//
//
//				window.draw(tile);
//			}
//		
//           
//
//        window.display();
//    }
//
//    return 0;
//}

















//
//
///// <summary>
///// 4:20 - back
///// </summary>
//
//using namespace sf;
//class Tile;
//
////--------------------------------------------------------------------------------------------------------------------
//bool check_play = false;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t Screen_Width = 800;
//uint16_t Screen_Height = 600;
//uint8_t  Pixel_Scale = 6;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t Grid_Size = (Screen_Width * Screen_Height) / Pixel_Scale;
//uint16_t Grid_Width = Screen_Width / Pixel_Scale;
//uint16_t Grid_Height = Screen_Height / Pixel_Scale;
//
////--------------------------------------------------------------------------------------------------------------------
//uint16_t mouse_x;
//uint16_t mouse_y;
//
////--------------------------------------------------------------------------------------------------------------------
//std::vector<int> Grid(Grid_Size);
//std::vector<int> GridC(Grid_Size);
//
//std::vector<Tile> Tiles = {};
//
////--------------------------------------------------------------------------------------------------------------------
//class Tile : public sf::Drawable {
//public:
//    int ID = 0;
//
//    sf::RectangleShape rect;
//
//    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
//    {
//        target.draw(rect, states);
//    }
//
//private:
//
//};
//
//
////--------------------------------------------------------------------------------------------------------------------
//void fill_screen() {//заповнює сітку плитками
//
//    int Current_ID = 0;
//    for (size_t H = 0; H < Grid_Height; H++)
//    {
//        for (size_t W = 0; W < Grid_Width; W++)
//        {
//
//            Tile tile;
//
//            tile.ID = Current_ID;
//
//            tile.rect.setPosition((W * (Pixel_Scale + 1)), (H * (Pixel_Scale + 1)));
//            tile.rect.setSize(sf::Vector2f(Pixel_Scale, Pixel_Scale));
//
//            Tiles.push_back(tile);
//
//            Current_ID++;
//        }
//
//    }
//
//}
//
////--------------------------------------------------------------------------------------------------------------------
//void update() {//оновлює сітку
//    int picked = 0;
//    for (size_t H = 0; H < Grid_Height; H++)
//    {
//        for (size_t W = 0; W < Grid_Width; W++)
//        {
//
//            //        if (Grid[picked] == 1 && GridC[picked] == 0) 
//            //        {
//
//            //            if (Grid[picked + Grid_Width] == 0)
//            //            {
//
//            //                Grid[picked] = 0;
//            //                GridC[picked] = 0;
//
//            //                Grid[picked + Grid_Width] = 1;
//            //                GridC[picked + Grid_Width] = 1;
//
//            //            }
//            //           
//            //        }
//            //        if (Grid[picked] == 1 && GridC[picked] == 0 && Grid[picked + Grid_Width] == 5)
//            //        {
//
//            //            /*GridC[picked + Grid_Width] = 0;
//            //            GridC[picked + Grid_Width] = 0;*/
//
//            //            Grid[picked + Grid_Width] = 1;
//            //            GridC[picked + Grid_Width] = 1;
//
//                        //Grid[picked] = 1;
//                        //GridC[picked] = 1;
//
//            //            
//
//            //            std::cout << "negr";
//            //        }
//
//            if (Grid[picked] == 1 && GridC[picked] == 0 && Grid[picked + Grid_Width] != 3)
//            {
//
//
//
//                Grid[picked] = 0;
//                GridC[picked] = 0;
//
//                Grid[picked + Grid_Width] = 1;
//                GridC[picked + Grid_Width] = 1;
//
//            }
//
//
//
//            picked++;
//        }
//    }
//}
//
//
////--------------------------------------------------------------------------------------------------------------------
//void set_tiles()
//{
//
//    int picked = 0;
//    for (int H = 0; H < Grid_Height; H++)
//    {
//        for (int W = 0; W < Grid_Width; W++)
//        {
//            /*for (Tile tile : Tiles)
//                if (tile.ID == picked)
//                {
//                    tile.Material = Grid[picked];
//                }*/
//
//            Tiles[picked].ID = Grid[picked];
//
//            picked++;
//        }
//
//    }
//}
//
////--------------------------------------------------------------------------------------------------------------------
//void clear_grid()
//{
//    for (size_t i = 0; i < Grid_Size; i++)
//    {
//        GridC[i] = 0;
//    }
//}
//
////--------------------------------------------------------------------------------------------------------------------
//int main()
//{
//    RenderWindow window(VideoMode(Screen_Width, Screen_Height), L"SandBox", Style::Default);
//    window.setVerticalSyncEnabled(true);
//
//    window.setFramerateLimit(720);
//
//
//
//
//
//    fill_screen();
//
//    Grid[0] = 1;
//    Grid[3] = 1;
//
//
//    //colision line
//    for (size_t i = 0; i < (Screen_Width / Pixel_Scale); i++)
//    {
//        Grid[i + ((Screen_Width / Pixel_Scale) * 10)] = 3;
//
//    }
//
//    Grid[3 + ((Screen_Width / Pixel_Scale) * 10)] = 5;
//
//
//    sf::View view = window.getDefaultView();
//
//    bool is_spawn = false;
//
//    while (window.isOpen())
//    {
//        Event event;
//        mouse_x = sf::Mouse::getPosition(window).x;
//        mouse_y = sf::Mouse::getPosition(window).y;
//
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//
//            //if (event.type == sf::Event::Resized) {
//            //    // resize my view
//            //    view.setSize({
//            //            static_cast<float>(event.size.width),
//            //            static_cast<float>(event.size.height)
//            //        });
//            //    window.setView(view);
//            //    // and align shape
//            //}
//
//            if (event.type == sf::Event::Resized)
//            {
//                // update the view to the new size of the window
//                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
//                window.setView(sf::View(visibleArea));
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && event.type == sf::Event::KeyPressed)
//            {
//
//                if (check_play) {
//                    check_play = false;
//                    std::cout << "game play" << std::endl;
//                }
//                else {
//                    check_play = true;
//                    std::cout << "game pause" << std::endl;
//                }
//
//            }
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !is_spawn)
//            {
//                is_spawn = true;
//            }
//            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && is_spawn)
//            {
//                std::cout << "released" << "\n";
//                is_spawn = false;
//            }
//
//            if (is_spawn) {
//                int grid_x = (mouse_x - 25) / Pixel_Scale;
//                int grid_y = (mouse_y - 10) / Pixel_Scale;
//                int target = (grid_x)+(grid_y)*Grid_Width;
//
//                std::cout << "Mouse X: " << mouse_x << ", Mouse Y: " << mouse_y << std::endl;
//                std::cout << "Grid X: " << grid_x << ", Grid Y: " << grid_y << std::endl;
//                std::cout << "Target index: " << target << std::endl;
//
//                if (target >= 0 && target < Grid_Size)  // Ensure the target is within bounds
//                {
//                    Grid[target] = 0;
//                    GridC[target] = 0;
//
//                    if (target + Grid_Width < Grid_Size) // Ensure the target below is within bounds
//                    {
//                        Grid[target] = 1;
//                        GridC[target] = 1;
//                    }
//                }
//            }
//
//
//        }
//
//        window.clear(Color::Black);
//
//
//        clear_grid();
//
//        if (check_play) {
//            update();
//        }
//
//        set_tiles();
//
//        for (Tile& tile : Tiles)
//        {
//            if (tile.ID == 0)
//                tile.rect.setFillColor(sf::Color::White);
//            if (tile.ID == 1)
//                tile.rect.setFillColor(sf::Color::Green);
//            if (tile.ID == 3)
//                tile.rect.setFillColor(sf::Color::Red);
//
//            if (tile.ID == 4)
//                tile.rect.setFillColor(sf::Color::Magenta);
//            if (tile.ID == 5)
//                tile.rect.setFillColor(sf::Color::Blue);
//
//
//            window.draw(tile);
//        }
//
//
//
//        window.display();
//    }
//
//    return 0;
//}














//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "Tile.h"
//
////---------------------------------------------------------------------------------------------------------Визначення розмірів екрану та плитки
//const uint16_t Screen_Width = 800;
//const uint16_t Screen_Height = 600;
//
//const uint8_t Tile_Width = 40;
//const uint8_t Tile_Height = 40;
//const uint8_t Global_Scale = 10;
//
//const uint16_t Grid_Width = Screen_Width / Global_Scale;
//const uint16_t Grid_Height = Screen_Height / Global_Scale;
//
//const float Tile_scale = 1.0;
//
//
//
////---------------------------------------------------------------------------------------------------------Змінні позицій миші
//uint16_t mouse_x;
//uint16_t mouse_y;
//
//
////---------------------------------------------------------------------------------------------------------Перечислення типів плиток
//enum ETYPE
//{
//    None,
//    Colision,
//    Sand
//};
//
////---------------------------------------------------------------------------------------------------------Клас плитки
////class Tile : public sf::Drawable {
////public:
////
////    sf::RectangleShape rect;
////    uint8_t type = ETYPE::None;
////
////    Tile(float x = 0, float y = 0, float scale = Global_Scale) {
////        rect.setSize(sf::Vector2f(scale, scale));
////        rect.setPosition(x, y);
////        rect.setFillColor(sf::Color::White); // Початковий колір плитки
////
////        rect.scale(sf::Vector2f(0.9f, 0.9f));
////    }
////
////    void setPosition(float x, float y) {
////        rect.setPosition(x, y);
////    }
////
////    void setColor(const sf::Color& color) {
////        rect.setFillColor(color);
////    }
////
////
////    void set_type(ETYPE type) {
////        this->type = type;
////    }
////
////private:
////
////    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
////        target.draw(rect, states);
////    }
////};
//
//
//
//void update(std::vector<std::vector<Tile>>& Grid) {
//
//
//
//
//}
//
//
//class Grid {
//public:
//
//
//    Grid() : grid(Grid_Height, std::vector<Tile>(Grid_Width))
//    {
//        for (size_t i = 0; i < Grid_Height; ++i)
//        {
//            for (size_t j = 0; j < Grid_Width; ++j)
//            {
//                float x = j * Global_Scale;
//                float y = i * Global_Scale;
//                grid[i][j] = Tile(x, y, Global_Scale);
//            }
//        }
//    }
//
//
//
//    void update() {
//
//        for (auto& row : grid) {
//            for (auto& tile : row) {
//
//                switch (tile.type)
//                {
//                case 0:
//                    tile.setColor(sf::Color::White);
//                    break;
//
//                case 1:
//                    tile.setColor(sf::Color::Green);
//                    break;
//
//                case 2:
//                    tile.rect.setFillColor(sf::Color::Red);
//                    break;
//
//                default:
//                    tile.setColor(sf::Color::Yellow);
//                }
//
//            }
//        }
//
//    }
//
//    Tile* find_tile(uint16_t x, uint16_t y) {
//
//        int row = static_cast<int>(y / Global_Scale);  // Індекс рядка
//        int col = static_cast<int>(x / Global_Scale);  // Індекс стовпця
//
//
//
//        std::cout << col << " " << row << "\n";
//
//        return &grid[row][col];
//    }
//
//
//
//    //підтримка функціоналу використання індексів
//    std::vector<Tile>& operator[](size_t index)
//    {
//        return grid[index];
//    }
//
//    const std::vector<Tile>& operator[](size_t index) const
//    {
//        return grid[index];
//    }
//
//    // Підтримка ітерації для for-each
//    auto begin() { return grid.begin(); }
//    auto end() { return grid.end(); }
//
//    auto begin() const { return grid.begin(); }
//    auto end() const { return grid.end(); }
//
//private:
//    std::vector<std::vector<Tile>> grid;
//};
//
//
//void update_mouse_pos(sf::RenderWindow& window) {
//    mouse_x = sf::Mouse::getPosition(window).x;
//    mouse_y = sf::Mouse::getPosition(window).y;
//}
//
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(Screen_Width, Screen_Height), "Grid Example");
//
//    // std::vector<std::vector<Tile>> Grid(Grid_Height, std::vector<Tile>(Grid_Width));
//
//
//
//
//    Grid grid;
//
//
//
//
//
//    grid[1][0].type = ETYPE::Sand;
//    /*std::cout << grid[1][0].rect.getGlobalBounds().getPosition().x << " ";
//    std::cout << grid[1][0].rect.getGlobalBounds().getPosition().y << "\n";*/
//
//
//
//    /* for ( auto& row : grid) {
//         for ( auto& tile : row) {
//             std::cout << tile.rect.getGlobalBounds().getPosition().x << " ";
//             std::cout << tile.rect.getGlobalBounds().getPosition().x << "\n";
//         }
//     }*/
//
//
//
//
//
//
//
//    while (window.isOpen()) {
//        sf::Event event;
//        update_mouse_pos(window);
//
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//            {
//                //grid.find_tile(mouse_x, mouse_y).set_type(ETYPE::Sand);
//
//                Tile* tile = grid.find_tile(mouse_x, mouse_y);
//                tile->set_type(ETYPE::Sand);
//            }
//            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
//            {
//
//            }
//
//
//
//        }
//
//
//
//
//
//
//
//
//        window.clear(sf::Color::Black);
//
//        grid.update();
//
//        // Відображення всіх плиток
//        for (const auto& row : grid) {
//            for (const auto& tile : row) {
//                window.draw(tile);
//            }
//        }
//
//
//
//        window.display();
//    }
//
//    return 0;
//}
//
//uint8_t type = ETYPE::None;
//
//Tile(float x = 0, float y = 0, float scale = Global_Scale) {
//    rect.setSize(sf::Vector2f(scale, scale));
//    rect.setPosition(x, y);
//    rect.setFillColor(sf::Color::White); // Початковий колір плитки
//
//    rect.scale(sf::Vector2f(0.9f, 0.9f));
//}
//
//void setPosition(float x, float y) {
//    rect.setPosition(x, y);
//}
//
//void setColor(const sf::Color& color) {
//    rect.setFillColor(color);
//}
//
//
//void set_type(ETYPE type) {
//    this->type = type;
//}
//
//private:
//
//    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
//        target.draw(rect, states);
//    }
//};













   //for (int x = 0; x < grid.row_size(); ++x) 
	//{
	//    for (int y = grid.col_size() - 1; y >= 0; --y) 
	//    {

	//        if (grid[x][y].type == ETYPE::Sand) 
	//        {
				// //Перевірка можливості падіння вниз
				//if (is_Valid_Index(x + 1, y, grid) && grid[x][y + 1].type == ETYPE::None)
				//{
				//	bufGrid[x + 1][y].set_type(ETYPE::Sand);
				//	bufGrid[x][y].set_type(ETYPE::None);
				//}
				//// Перевірка можливості падіння вниз-ліворуч
				//else if (is_Valid_Index(x - 1, y - 1, grid) && grid[x - 1][y + 1].type == ETYPE::None)
				//{
				//	bufGrid[x - 1][y - 1].set_type(ETYPE::Sand);
				//	bufGrid[x][y].set_type(ETYPE::None);
				//}
				//// Перевірка можливості падіння вниз-праворуч
				//else if (is_Valid_Index(x + 1, y + 1, grid) && grid[x + 1][y + 1].type == ETYPE::None)
				//{
				//	bufGrid[x + 1][y + 1].set_type(ETYPE::Sand);
				//	bufGrid[x][y].set_type(ETYPE::None);
				//}
	//        }
	//    }
	//}