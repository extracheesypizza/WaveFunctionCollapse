#ifndef GRID_H
#define GRID_H

#include <vector>

#include "Cell.hpp"
#include "TileCollection.hpp"

class Grid
{
   private:
    vector<vector<Cell*>> grid_;
    TileCollection* tc_;

   public:
    Grid(int x, int y, TileCollection& tc);

    int getXSize() const;
    int getYSize() const;

    Cell* getCell(int x, int y);

    Cell* getLeastEntropy(bool& needToExecute);
    void setCell(Cell* c);

    void pickFirstCell(int x, int y);
    void pickFirstCellRandomly();

    void updateEntropyCell(Cell* cur);

    void fillEmpty(int x, int y);
    void startOver();

    void execute(bool& needToExecute);
};

#endif  // GRID_H
