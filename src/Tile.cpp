#include "Tile.hpp"

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

void Tile::setTexture(sf::Texture* t) { texture_ = t; }

// sockets
void Tile::setSockets(vector<string> socks) { sockets_ = socks; }
string Tile::getCurDir(int i) const { return sockets_[i]; }

vector<string> Tile::getSockets() const { return sockets_; }

void Tile::printSockets() const
{
    for(int i = 0; i < sockets_.size(); i++)  //
        cout << sockets_[i] << " ";
}

sf::Texture* Tile::getTexture() const { return texture_; }

void Tile::rotate(int i)
{
    vector<string> temp = {"", "", "", ""};

    for(int j = 0; j < sockets_.size(); j++)  //
        temp[(j + i) % 4] = sockets_[j];

    sockets_ = temp;
    setRotation(i);
}

void Tile::setRotation(int i) { rotation_ = i; }

int Tile::getRotation() const { return rotation_; }
