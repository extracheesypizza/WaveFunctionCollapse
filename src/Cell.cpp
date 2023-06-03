#include "Cell.hpp"

// position
int Cell::getX() const { return x_; }
int Cell::getY() const { return y_; }

// tile
void Cell::setTile(Tile* t) { tile_ = t; }
Tile* Cell::getTile() const { return tile_; }

void Cell::setRandomTile()
{
    setSetStatus(true);
    vector<Tile*> choose = possibleTiles_;
    int chooseSize = choose.size();
    int r = rand() % (chooseSize);
    tile_ = choose[r];
}

int Cell::getEntropy() const { return possibleTiles_.size(); }
string Cell::getDir(int i) const { return tile_->getCurDir(i); }

vector<Tile*>* Cell::getPossibleTiles() { return &possibleTiles_; }
void Cell::setPossibleTiles(vector<Tile*> vot) { possibleTiles_ = vot; }

bool Cell::isSet() const { return cellSet_; }
void Cell::setSetStatus(bool b) { cellSet_ = b; }
