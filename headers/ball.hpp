#pragma once

#include <SFML/Graphics.hpp>

/*
  sources:
  reflectionVec(): https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/reflect.xhtml
*/

class Ball {
  public:
    Ball();
    sf::Vector2f normalizeVec(sf::Vector2f vec);
    sf::Vector2f reflectionVec(sf::Vector2f incident, sf::Vector2f normal);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    bool intersects(sf::FloatRect target);
    sf::Vector2f getDirection();
    sf::FloatRect getGlobalBounds();
    void ballCollision(sf::Vector2f incidentDir);
  private:
    float speed;
    sf::Vector2f prevPos;
    sf::Vector2f direction;
    sf::CircleShape ball;

    void boundsCollider();
};
