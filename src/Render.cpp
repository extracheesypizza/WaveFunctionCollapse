#include "Render.hpp"

void drawGrid(Grid* g, sf::RenderWindow* window)
{
    window->clear(sf::Color::White);

    int ySize = g->getYSize();
    int xSize = g->getXSize();

    float width = window->getSize().x / float(xSize);

    sf::Vector2f vec;
    vec.x = width;
    vec.y = width;

    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            Cell* cur = g->getCell(j, i);

            if(cur->isSet() == 1)
            {
                sf::RectangleShape r(vec);

                r.setOrigin(r.getSize().x / 2, r.getSize().y / 2);
                r.setPosition(sf::Vector2f(width * j + width / 2, width * i + width / 2));

                sf::Texture temp = cur->getTile()->getTexture();
                sf::Texture* tp = &temp;
                r.setTexture(tp);
                r.rotate(cur->getTile()->getRotation() * 90);

                window->draw(r);
            }
        }
    }

    window->display();
}
