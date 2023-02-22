#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  // create a window of size 400 by 400
  // top left is 0,0 and bottom right is (w,h)
  const int wWidth = 400;
  const int wHeight = 400;
  sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
  window.setFramerateLimit(60);

  // create a shape
  int r = 0;
  int g = 255;
  int b = 255;

  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(r, g, b));
  shape.setPosition(200.0f, 200.0f);
  float shapeMoveSpeed = 0.01f;

  // While windows is open. Draw shape.
  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      window.clear();
      window.draw(shape);
      window.display();
    }
  }

  return 0;
}