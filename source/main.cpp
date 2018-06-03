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

    window.setFramerateLimit(60);
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
        for(auto&& ball : balls){
          ball.update(deltaTime);
          ball.draw(window);
        }
        window.display();
    }

    return 0;
}
