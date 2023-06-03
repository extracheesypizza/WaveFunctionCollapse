#include "Application.hpp"

Application::Application()
{
    tc_ = new TileCollection;
    grid_ = new Grid(15, 15, *tc_);
    window_ = new sf::RenderWindow(sf::VideoMode(784, 784), "Griddy");

    window_->setView(sf::View(sf::FloatRect({0, 0}, {float(window_->getSize().x), float(window_->getSize().y)})));
    window_->clear(sf::Color::White);
}

void Application::execute()
{
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
                if(event.key.code == sf::Keyboard::Backspace)
                {
                    needToExecute = true;
                    grid_->startOver();
                }
        }

        if(needToExecute)
            grid_->execute(needToExecute);

        grid_->drawGrid(window_);
    }
}
