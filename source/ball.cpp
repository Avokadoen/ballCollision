#include "ball.hpp"
#include "globals.hpp"

#include <iostream>
#include <stdlib.h>

Ball::Ball(){
  speed = WINDOW_Y * 0.02;

  direction.x = (rand() % 100) - 50;
  direction.y = (rand() % 100) - 50;
  direction = normalizeVec(direction);
  //std::cout << "\n " << direction.x << "\t" << direction.y << std::endl;

  ball.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
  float ballScale = WINDOW_Y * 0.035f;
  ball.setRadius(ballScale);
  ball.setPosition((rand() % (int)((WINDOW_X - ballScale * 2))),
                   (rand() % (int)((WINDOW_Y - ballScale * 2))));
}

sf::Vector2f Ball::normalizeVec(sf::Vector2f vec){
  float magnitude = sqrt(pow(vec.x,2) + pow(vec.y,2));

  return sf::Vector2f(vec.x/magnitude, vec.y/magnitude);
}

void Ball::draw(sf::RenderWindow& window){
  window.draw(ball);
}

void Ball::update(float deltaTime){
  float velX = direction.x * speed * deltaTime;
  float velY = direction.y * speed * deltaTime;
  ball.move(velX, velY);
}
