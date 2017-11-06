#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include "clases.h"

#define PI 3.14159265

using namespace std;
using namespace sf;

int main(){
  Time t1 = seconds(0.001f);
  //variables
  const float suelo = 500.0;
  const float gravity =9.8;

  float angle,range;
  float max_height;
  float v_0;
  float time_aux;

  cout << "Inserta el angulo: ";
  cin >> angle;
  cout << "Inserta la velocidad inicial: ";
  cin >> v_0;

  range = (pow(v_0,2) * sin((2 * angle) * PI/180)) / gravity;
  max_height = (pow(v_0,2) * pow(sin(angle * PI/180),2)) / (2*gravity);
  //la ecuacion de la general de la parábola será:
  //Ax^2 + Bx + Cy + D = 0
  int h,k;
  h = range / 2;
  k = suelo - max_height;
  cout << "V( " << h << " , " << k << " )" << endl;

  Point V(h,k);//el vertice de mi parabola
  //CircleShape player(10);
  //player.setPosition(0.0, suelo);
  CircleShape projectile(10);
  float x = 0.0;
  float p = pow(h, 2) / (4 *(suelo - k));
  float y = (pow(x - h, 2) + (4 * p * k)) / (4 * p);
  //Point coord(x , y);
  cout << x << " " << y << endl;
  Point coord(x,y);
  projectile.setPosition(coord.x, coord.y);

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
      }

    // clear the window with black color
    window.clear(Color(0,0,0));
    // draw everything here...
    //window.draw(player);
    window.draw(projectile);
    // end the current frame
    window.display();
    sleep(t1);

    coord.x+=0.1;
    coord.y = (pow(coord.x - h, 2) + (4 * k * p)) / (4*p);;
    projectile.setPosition(coord.x, coord.y);
  }

  return 0;
}
