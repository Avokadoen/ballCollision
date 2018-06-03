#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "globals.hpp"

#include <stdlib.h>
#include <time.h>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "ball collision demo");
    /* initialize random seed: */
    srand(time(NULL));

    std::vector<Ball> balls;
    for(int i = 0; i < (rand() % (MAX_BALLS - MIN_BALLS) + MIN_BALLS); i++ ){
      Ball newBall;
      balls.push_back(newBall);
    }

    //window.setFramerateLimit(60);
    sf::Clock clock;
    clock.restart();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        window.clear();
        for(auto i = balls.begin(); i != balls.end(); i++){
          for(auto j = i + 1; j !=  balls.end(); j++){
              if(i->intersects(j->getGlobalBounds())){
                sf::Vector2f prevIDir = i->getDirection();
                i->ballCollision(j->getDirection());
                j->ballCollision(prevIDir);

                //j->update(deltaTime);
              }
          }
          i->update(deltaTime);
        }

        for(auto&& ball : balls){

          ball.draw(window);
        }
        window.display();
    }

    return 0;
}
