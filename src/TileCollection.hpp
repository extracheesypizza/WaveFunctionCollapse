#ifndef TILECOLLECTION_HPP
#define TILECOLLECTION_HPP

#include "Tile.hpp"

using namespace std;

class TileCollection
{
   private:
    vector<Tile> possibleTiles_;

   public:
    TileCollection();
    void setDefinedTiles();
    void generateAllPossibleTiles();
    void outputAllPossibleTiles();
    vector<Tile>* getAllPossibleTiles();
};

#endif  // TILECOLLECTION_HPP
