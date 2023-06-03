#include "Application.hpp"

Application::Application()
{
    tc_ = new TileCollection;
    grid_ = new Grid(15, 15, *tc_);
}

void Application::execute()
{
    sf::RenderWindow window(sf::VideoMode(784, 784), "Griddy");
    window_ = &window;
    sf::Vector2f pos(0, 0);
    sf::Vector2f size(window_->getSize().x, window_->getSize().y);
    window_->setView(sf::View(sf::FloatRect(pos, size)));

    grid_->pickFirstCellRandomly();

    bool needToExecute = true;

    while(window_->isOpen())
    {
        sf::Event event;
        while(window_->pollEvent(event))  //
        {
            if(event.type == sf::Event::Closed)
                window_->close();

            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Backspace)
                {
                    needToExecute = true;
                    grid_->startOver();
                }
            }
        }

        if(needToExecute)
            grid_->execute(needToExecute);

        drawGrid(grid_, window_);
    }
}
