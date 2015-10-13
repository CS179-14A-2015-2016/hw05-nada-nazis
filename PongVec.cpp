
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
using namespace std;

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int ball1x = -1;
int ball1y = 1;
int ball2x = 1;
int ball2y = -1;
int iangle1 = atan2(ball1y,ball1x);

int	magnitude(int i, int j)
{
	return sqrt((i*i) + (j*j));
}
int	normalize(int i, int j)
{
	return i / magnitude(i,j);
}
int	dot(int i, int j, int k, int l)
{
	return i*k + j*l;
}

void colissionCheck(sf::FloatRect ball1,sf::FloatRect ball2, sf::FloatRect paddle1 ,sf::FloatRect paddle2)
{
	if(ball1.getPosition() <= 0 || ball1.getPosition() >= 800)
	{
		int t1 = normalize(ball1.getPosition().x, ball1.getPosition().y);
		int t2 = normalize(ball1.getPosition().y, ball1.getPosition().x);

		int d1 = dot(ball1x, ball1y, t1, t2);
		int d2 = dot(t1, t2, t1, t2);

		int d = d1/d2;

		int t3 = d * t1;
		int t4 = d * t2;

		ball1x = ball1x - t3;
	}

    if(ball1.intersects(paddle1))
    {
        //ball1x = -ball1x;
        //ball1y = -ball1y;
        //do something
		int t1 = normalize(ball1.getPosition().x, ball1.getPosition().y);
		int t2 = normalize(ball1.getPosition().y, ball1.getPosition().x);

		int d1 = dot(ball1x, ball1y, t1, t2);
		int d2 = dot(t1, t2, t1, t2);

		int d = d1/d2;

		int t3 = d * t1;
		int t4 = d * t2;

		ball1x = ball1x - t3;
		ball1y = ball1y - t4;

    }
    else if(ball1.intersects(paddle2))
    {
        //ball1x = -ball1x;
        //ball1y = -ball1y;
        //do something
    	int t1 = normalize(ball1.getPosition().x, ball1.getPosition().y);
    	int t2 = normalize(ball1.getPosition().y, ball1.getPosition().x);

    	int d1 = dot(ball1x, ball1y, t1, t2);
    	int d2 = dot(t1, t2, t1, t2);

    	int d = d1/d2;

    	int t3 = d * t1;
    	int t4 = d * t2;

    	ball1x = ball1x - t3;
    	ball1y = ball1y - t4;
    }
    else if(ball1.intersects(ball2))
    {
        //ball1x = -ball1x;
        //ball1y = -ball1y;
        //do something
    	int t1 = normalize(ball1.getPosition().x, ball1.getPosition().y);
    	int t2 = normalize(ball1.getPosition().y, ball1.getPosition().x);

    	int d1 = dot(ball1x, ball1y, t1, t2);
    	int d2 = dot(t1, t2, t1, t2);

    	int d = d1/d2;

    	int t3 = d * t1;
    	int t4 = d * t2;

    	ball1x = ball1x - t3;
    	ball1y = ball1y - t4;
    }

    if(ball2.intersects(paddle1))
    {
        //ball2x = -ball2x;
        //ball2y = -ball2y;
        //do something
    	int t1 = normalize(ball2.getPosition().x, ball2.getPosition().y);
    	int t2 = normalize(ball2.getPosition().y, ball2.getPosition().x);

    	int d1 = dot(ball2x, ball2y, t1, t2);
    	int d2 = dot(t1, t2, t1, t2);

    	int d = d1/d2;

    	int t3 = d * t1;
    	int t4 = d * t2;

    	ball2x = ball2x - t3;
    	ball2y = ball2y - t4;
    }
    else if(ball2.intersects(paddle2))
    {
        //ball2x = -ball2x;
        //ball2y = -ball2y;
        //do something
    	int t1 = normalize(ball2.getPosition().x, ball2.getPosition().y);
    	int t2 = normalize(ball2.getPosition().y, ball2.getPosition().x);

    	int d1 = dot(ball2x, ball2y, t1, t2);
    	int d2 = dot(t1, t2, t1, t2);

    	int d = d1/d2;

    	int t3 = d * t1;
    	int t4 = d * t2;

    	ball2x = ball2x - t3;
    	ball2y = ball2y - t4;
    }
    else if(ball2.intersects(ball1))
    {
        //ball2x = -ball2x;
        //ball2y = -ball2y;
        //do something
    	int t1 = normalize(ball2.getPosition().x, ball2.getPosition().y);
    	int t2 = normalize(ball2.getPosition().y, ball2.getPosition().x);

    	int d1 = dot(ball2x, ball2y, t1, t2);
    	int d2 = dot(t1, t2, t1, t2);

    	int d = d1/d2;

    	int t3 = d * t1;
    	int t4 = d * t2;

    	ball2x = ball2x - t3;
    	ball2y = ball2y - t4;

    }


}
int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Reloaded");


    // Create Paddles
    sf::RectangleShape paddle1(sf::Vector2f(20, 80));
    paddle1.setFillColor(sf::Color(255, 255, 255));
    paddle1.setPosition(20, 250);

    sf::RectangleShape paddle2(sf::Vector2f(20, 80));
    paddle2.setFillColor(sf::Color(255, 255, 255));
    paddle2.setPosition(760, 250);

    // Create Balls
    sf::CircleShape ball1(10);
    ball1.setPosition(300, 250);

    sf::CircleShape ball2(10);
    ball2.setPosition(500, 350);



    // Collision Boxes
    sf::FloatRect p1box = paddle1.getGlobalBounds();
    sf::FloatRect p2box = paddle2.getGlobalBounds();
    sf::FloatRect b1box = ball1.getGlobalBounds();
    sf::FloatRect b2box = ball2.getGlobalBounds();



    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            colissionCheck(b1box, b2box, p1box, p2box);
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {

            paddle1.move(0, -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

            paddle1.move(0, 1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {

            paddle2.move(0, -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

            paddle2.move(0, 1);
        }
        ball1.move(ball1x,ball1y);
        ball2.move(ball2x,ball2y);


        // Clear screen
        window.clear();



        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball1);
        window.draw(ball2);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
