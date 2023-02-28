#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  // create a window of size 800 by 800
  // top left is 0,0 and bottom right is (w,h)
  const int wWidth = 800;
  const int wHeight = 800;
  sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
  window.setFramerateLimit(60);

  // create a shape
  int r = 0;
  int g = 255;
  int b = 255;

  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(r, g, b));
  shape.setPosition(500.0f, 500.0f);
  float shapeMoveSpeed = 0.1f;

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
    }

    // basic moving animation
    shape.setPosition(shape.getPosition().x - shapeMoveSpeed, shape.getPosition().y - shapeMoveSpeed);

    // basic render calls
    window.clear();     // get rid of what was there
    window.draw(shape); // draw to the screen something new
    window.display();   // call window display function. This also swaps between buffers
  }

  return 0;
};