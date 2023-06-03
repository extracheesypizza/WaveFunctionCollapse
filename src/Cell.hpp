#ifndef CELL_HPP
#define CELL_HPP

#include "TileCollection.hpp"

class Cell
{
   private:
    Tile* tile_ = nullptr;
    vector<Tile*> possibleTiles_;
    int x_;
    int y_;
    bool cellSet_ = 0;

   public:
    Cell(int x, int y, TileCollection* tc) : x_(x), y_(y)
    {
        vector<Tile>* c = tc->getAllPossibleTiles();
        for(int i = 0; i < c->size(); i++)  //
            possibleTiles_.push_back(&(c->at(i)));
    };

    ~Cell()
    {
        tile_ = nullptr;
        possibleTiles_.clear();
    };

    // position
    int getX() const;
    int getY() const;

    // tile
    void setTile(Tile* t);
    int getEntropy() const;
    string getDir(int i) const;

    Tile* getTile() const;
    void setRandomTile();

    vector<Tile*>* getPossibleTiles();
    void setPossibleTiles(vector<Tile*> vot);

    bool isSet() const;
    void setSetStatus(bool b);
};

#endif  // CELL_H
