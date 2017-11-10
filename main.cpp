#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#define PI 3.14159265

using namespace std;
using namespace sf;

int main(){
    RectangleShape canon;
    canon.setOrigin(Vector2f(3,0));
    canon.setSize(Vector2f(6,-20));
    canon.setPosition(Vector2f(400,300));

    CircleShape player(10);
    player.setPosition(390,290);

    RenderWindow window(VideoMode(800, 600), "My render");

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event))
        {
	// "close requested" event: we close the window
        if (event.type == Event::Closed)
            window.close();
        if(Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();
        if(Keyboard::isKeyPressed(Keyboard::Up)){

            canon.rotate(-1);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){

            canon.rotate(1);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){

            canon.move(-1,0);
            player.move(-1,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){

            canon.move(1,0);
            player.move(1,0);
        }
        // clear the window with black color
        window.clear(Color(0,0,0));
        // draw everything here...
        //window.draw(player);
        window.draw(canon);
        window.draw(player);
        // end the current frame
        window.display();
        }
  }

  return 0;
}
