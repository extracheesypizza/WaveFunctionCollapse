#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Grid.hpp"

class Application
{
   private:
    sf::RenderWindow* window_;
    Grid* grid_;
    TileCollection* tc_;

   public:
    Application();
    void execute();
};

#endif  // APPLICATION_H
