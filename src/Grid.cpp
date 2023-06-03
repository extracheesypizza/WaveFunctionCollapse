#include "Grid.hpp"

Grid::Grid(int x, int y, TileCollection& tc)
{
    tc_ = &tc;

    for(int i = 0; i < y; i++)
    {
        vector<Cell*> empty;
        grid_.push_back(empty);
        for(int j = 0; j < x; j++)  //
            grid_[i].push_back(new Cell(j, i, tc_));
    }
}

void Grid::drawGrid(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);

    int ySize = getYSize();
    int xSize = getXSize();

    float width = window->getSize().x / float(xSize);

    sf::Vector2f vec;
    vec.x = width;
    vec.y = width;

    Cell* cur = toDraw_;

    if(cur->isSet() == 1)
    {
        sf::RectangleShape* r = new sf::RectangleShape(vec);

        r->setOrigin(r->getSize().x / 2, r->getSize().y / 2);
        r->setPosition(sf::Vector2f(width * cur->getX() + width / 2, width * cur->getY() + width / 2));

        sf::Texture* temp = cur->getTile()->getTexture();
        r->setTexture(temp);
        r->rotate(cur->getTile()->getRotation() * 90);

        buffer_.push_back(r);
    }

    for(int i = 0; i < buffer_.size(); i++)  //
        window->draw(*buffer_[i]);

    window->display();
}

void Grid::execute(bool& needToExecute)
{
    Cell* cur = getLeastEntropy(needToExecute);

    if(cur == nullptr)
        needToExecute = false;

    else if(cur->getEntropy() == 0 && needToExecute == true)
        startOver();

    else
    {
        cur->setRandomTile();
        updateEntropyCell(cur);
    }
}

void Grid::fillEmpty(int x, int y)
{
    for(int i = 0; i < y; i++)
    {
        vector<Cell*> empty;
        grid_.push_back(empty);
        for(int j = 0; j < x; j++)  //
            grid_[i].push_back(new Cell(j, i, tc_));
    }
}

void Grid::startOver()
{
    int x = grid_[0].size();
    int y = grid_.size();

    // deallocate frame buffer memory
    for(auto el : buffer_)  //
        delete el;
    buffer_.clear();

    // deallocate grid cell memory
    for(int i = 0; i < y; i++)      //
        for(int j = 0; j < x; j++)  //
            delete grid_[i][j];

    for(int i = 0; i < y; i++)  //
        grid_[i].clear();
    grid_.clear();

    fillEmpty(x, y);
    pickFirstCellRandomly();
}

Cell* Grid::getLeastEntropy(bool& needToExecute)
{
    // find the least entropy
    int leastEntropy = INT_MAX;
    int tempSize;

    vector<Cell*> pool;
    needToExecute = false;

    for(int i = 0; i < grid_.size(); i++)
        for(int j = 0; j < grid_[i].size(); j++)
            if(grid_[i][j]->isSet() == 0)
            {
                needToExecute = true;
                tempSize = grid_[i][j]->getEntropy();

                if(tempSize < leastEntropy)
                {
                    pool.clear();
                    leastEntropy = tempSize;
                }

                if(tempSize == leastEntropy)
                    pool.push_back(grid_[i][j]);
            }

    int poolSize = pool.size();
    if(poolSize > 0)
    {
        int r = rand() % (poolSize);
        toDraw_ = pool[r];
        return toDraw_;
    }
    else
        return nullptr;
}

bool inBounds(int x, int y, int sX, int sY) { return x >= 0 && y >= 0 && x < sX && y < sY; }
bool isNotCurrent(int x, int y) { return x != 0 && y != 0; }

void Grid::updateEntropyCell(Cell* cur)
{
    int width = grid_[0].size();
    int height = grid_.size();

    int x = cur->getX();
    int y = cur->getY();

    Cell* curNeighbour;
    string temp;

    // CHECK TOP
    if(y - 1 >= 0)
    {
        curNeighbour = grid_[y - 1][x];

        if(curNeighbour->isSet() == 0)
        {
            temp = cur->getDir(0);
            reverse(temp.begin(), temp.end());

            vector<Tile*>* neiSides = curNeighbour->getPossibleTiles();

            for(auto it = neiSides->begin(); it != neiSides->end(); it++)
                if((*it)->getCurDir(2) != temp)
                    neiSides->erase(it--);
        }
    }

    // CHECK BOTTOM
    if(y + 1 < height)
    {
        curNeighbour = grid_[y + 1][x];
        if(curNeighbour->isSet() == 0)
        {
            temp = cur->getDir(2);
            reverse(temp.begin(), temp.end());

            vector<Tile*>* neiSides = curNeighbour->getPossibleTiles();

            for(auto it = neiSides->begin(); it != neiSides->end(); it++)
                if((*it)->getCurDir(0) != temp)
                    neiSides->erase(it--);
        }
    }

    // CHECK RIGHT
    if(x + 1 < width)
    {
        curNeighbour = grid_[y][x + 1];
        if(curNeighbour->isSet() == 0)
        {
            temp = cur->getDir(1);
            reverse(temp.begin(), temp.end());

            vector<Tile*>* neiSides = curNeighbour->getPossibleTiles();

            for(auto it = neiSides->begin(); it != neiSides->end(); it++)
                if((*it)->getCurDir(3) != temp)
                    neiSides->erase(it--);
        }
    }

    // CHECK LEFT
    if(x - 1 >= 0)
    {
        curNeighbour = grid_[y][x - 1];
        if(curNeighbour->isSet() == 0)
        {
            temp = cur->getDir(3);
            reverse(temp.begin(), temp.end());

            vector<Tile*>* neiSides = curNeighbour->getPossibleTiles();

            for(auto it = neiSides->begin(); it != neiSides->end(); it++)
                if((*it)->getCurDir(1) != temp)
                    neiSides->erase(it--);
        }
    }
}

int Grid::getXSize() const { return grid_[0].size(); }

int Grid::getYSize() const { return grid_.size(); }

Cell* Grid::getCell(int x, int y) { return grid_[y][x]; }

void Grid::pickFirstCell(int x, int y)
{
    Cell* cur = grid_[y][x];

    Tile* starting = (*cur->getPossibleTiles())[0];

    cur->getPossibleTiles()->size();
    cur->setTile(starting);
    cur->setSetStatus(true);
}

void Grid::pickFirstCellRandomly()
{
    int x = rand() % (grid_[0].size());
    int y = rand() % (grid_.size());

    Cell* cur = grid_[y][x];

    int pos = rand() % (*cur->getPossibleTiles()).size();

    Tile* starting = (*cur->getPossibleTiles())[pos];

    cur->getPossibleTiles()->size();
    cur->setTile(starting);
    cur->setSetStatus(true);

    toDraw_ = cur;

    updateEntropyCell(cur);
}
