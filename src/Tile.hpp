#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//  Tile
//  Has 4 sockets
//
//      0
//   3 [] 1
//     2
//
// has a position in a grid
// has an image associated with it
// has 4 sockets in form of ["North", "East", "South", "West"]
// entropy is defined by the size of the possibleNeighbours vector size

class Tile
{
   private:
    vector<string> sockets_ = {};
    sf::Texture* texture_ = nullptr;
    int rotation_ = 0;

   public:
    Tile(){};

    // position
    void setPosition(int x, int y);

    // sockets
    void setSockets(vector<string> socks);
    vector<string> getSockets() const;
    string getCurDir(int i) const;
    void printSockets() const;

    // texture
    void setTexture(sf::Texture* t);
    sf::Texture* getTexture() const;

    // rotation
    void rotate(int i);
    void setRotation(int i);
    int getRotation() const;
};

#endif  // TILE_HPP
