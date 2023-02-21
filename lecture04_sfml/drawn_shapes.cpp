#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  // create a window of size 400 by 400
  // top left is 0,0 and bottom right is (w,h)
  const int wWidth = 400;
  const int wHeight = 400;
  sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
}