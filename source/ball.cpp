#include "ball.hpp"
#include "globals.hpp"

#include <iostream>
#include <stdlib.h>

Ball::Ball(){
  speed = WINDOW_Y * 0.2;
  prevPos = sf::Vector2f(0, 0);

  direction.x = (rand() % 100) - 50;
  direction.y = (rand() % 100) - 50;
  direction = normalizeVec(direction);
  //std::cout << "\n " << direction.x << "\t" << direction.y << std::endl;

  ball.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
  float ballScale = WINDOW_Y * 0.035f;
  ball.setRadius(ballScale);
  ball.setPosition((rand() % (int)((WINDOW_X - ballScale * 4)) + ballScale * 1.5),
                   (rand() % (int)((WINDOW_Y - ballScale * 4)) + ballScale * 1.5));
}

sf::Vector2f Ball::normalizeVec(sf::Vector2f vec){
  float magnitude = sqrt(pow(vec.x,2) + pow(vec.y,2));

  return sf::Vector2f(vec.x/magnitude, vec.y/magnitude);
}

// creates vector with using formala: //I - 2.0 * dot(N, I) * N.
sf::Vector2f Ball::reflectionVec(sf::Vector2f incident, sf::Vector2f normal){
   return incident - 2.0f * (incident.x * normal.x + incident.y * normal.y) * normal;
}

void Ball::draw(sf::RenderWindow& window){
  window.draw(ball);
}

void Ball::update(float deltaTime){

  boundsCollider();

  float velX = direction.x * speed * deltaTime;
  float velY = direction.y * speed * deltaTime;

  prevPos = ball.getPosition();
  ball.move(velX, velY);
}

bool Ball::intersects(sf::FloatRect target){
  return target.intersects(ball.getGlobalBounds());
}

sf::Vector2f Ball::getDirection(){
  return direction;
}

sf::FloatRect Ball::getGlobalBounds(){
  return ball.getGlobalBounds();
}

void Ball::ballCollision(sf::Vector2f incidentDir){
//  ball.setPosition(prevPos);
  direction = normalizeVec(reflectionVec(direction, incidentDir));
}

// Private functions

void Ball::boundsCollider(){
  sf::Vector2f ballPos = ball.getPosition();
  float ballScale = ball.getRadius() * 2;

  if(ballPos.x > WINDOW_X - ballScale){
    sf::Vector2f normal = normalizeVec(sf::Vector2f(-1, 0));
    direction = reflectionVec(direction, normal);
  }
  else if(ballPos.x < 0){
    sf::Vector2f normal = normalizeVec(sf::Vector2f(1, 0));
    direction = reflectionVec(direction, normal);
  }


  if(ballPos.y > WINDOW_Y - ballScale){
    sf::Vector2f normal = normalizeVec(sf::Vector2f(0, -1));
    direction = reflectionVec(direction, normal);
  }
  else if(ballPos.y < 0){
    sf::Vector2f normal = normalizeVec(sf::Vector2f(0, 1));
    direction = reflectionVec(direction, normal);
  }

}
