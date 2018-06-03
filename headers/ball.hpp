#pragma once

#include <SFML/Graphics.hpp>

class Ball {
  public:
    Ball();
    sf::Vector2f normalizeVec(sf::Vector2f vec);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
  private:
    float speed;
    sf::Vector2f direction;
    sf::CircleShape ball;
};
