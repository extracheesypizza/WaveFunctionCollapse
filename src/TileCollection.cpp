#include "TileCollection.hpp"

using namespace std;

// G = Grass
// R = Road
// C = City
//

TileCollection::TileCollection()
{
    setDefinedTiles();
    // outputAllPossibleTiles();
}

void TileCollection::generateAllPossibleTiles()
{
    int lastDefined = possibleTiles_.size() - 1;

    // we need to perform 3 rotations
    for(int i = 1; i < 4; i++)
    {
        // create a copy of that tile
        Tile current = possibleTiles_[lastDefined];
        current.rotate(i);
        possibleTiles_.push_back(current);
    }
}

void TileCollection::setDefinedTiles()
{
    // D = Dark Green
    // L = Light Green
    // G = Light Gray
    // I = inside microchip
    // B = Microchip Bevel
    // T = TIN

    //    string startPath = "/carcassone/";
    //    string endPath = "_img.png";
    sf::Texture curTexture;
    Tile current;

    // tile 1 [church]
    curTexture.loadFromFile("circuit/1_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DTD", "DLD", "DTD"});
    possibleTiles_.push_back(current);
    // generateAllPossibleTiles();

    // tile 2 [3/4 city]
    curTexture.loadFromFile("circuit/2_img.png");
    current.setTexture(curTexture);
    current.setSockets({"BIB", "BIB", "BIB", "BIB"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 3 [3/4 city w/ road]
    curTexture.loadFromFile("circuit/3_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DDB", "BIB", "BDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 4 [1/2 city]
    curTexture.loadFromFile("circuit/4_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DDD", "DDD", "DDB", "BDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 5 [1/2 city w/ road]
    curTexture.loadFromFile("circuit/5_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DLD", "DLD", "DLD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 6 [city neck]
    curTexture.loadFromFile("circuit/6_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DLD", "DDD", "DDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 7 [2 * 1/4 city]
    curTexture.loadFromFile("circuit/7_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DDD", "DDD", "DDD", "DDD"});
    possibleTiles_.push_back(current);
    // generateAllPossibleTiles();

    // tile 8 [2 * 1/4 city v2]
    curTexture.loadFromFile("circuit/8_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DDD", "DLD", "DLD", "DLD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 9 [1/4 city w/ roads]
    curTexture.loadFromFile("circuit/9_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DDD", "DLD", "DDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 10 [2 roads]
    curTexture.loadFromFile("circuit/10_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DTD", "DDD", "DLD", "DDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 11 [1 road]
    curTexture.loadFromFile("circuit/11_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DLD", "DDD", "DDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 12 [1 road]
    curTexture.loadFromFile("circuit/12_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DDD", "DLD", "DDD", "DLD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 12 [1 road]
    curTexture.loadFromFile("circuit/13_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DLD", "DDD", "DDD", "DDD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();

    // tile 12 [1 road]
    curTexture.loadFromFile("circuit/14_img.png");
    current.setTexture(curTexture);
    current.setSockets({"DDD", "DTD", "DDD", "DTD"});
    possibleTiles_.push_back(current);
    generateAllPossibleTiles();
}

void TileCollection::outputAllPossibleTiles()
{
    for(int i = 0; i < possibleTiles_.size(); i++)
    {
        if(i % 4 == 0)
            cout << endl;
        cout << "Tile " << i << ": ";
        possibleTiles_[i].printSockets();
        cout << " TR: " << possibleTiles_[i].getRotation() << endl;
    }
}

vector<Tile>* TileCollection::getAllPossibleTiles()
{
    // cout << "GOT ME" << endl << endl;
    return &possibleTiles_;
}
