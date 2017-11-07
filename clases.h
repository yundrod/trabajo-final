#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

using namespace std;
using namespace sf;
#define PI 3.14159265

//variables
const float suelo = 500.0;
const float gravity =9.8;

class Point{
 public:
  float x,y;
};
class Player
{
  Point position_player;
  CircleShape body_torax;
  RectangleShape body_head;
 public:
  Player();
	~Player();
	
};

class proyectil{
 public:
  float angle,range;
  float max_height;
  float v_0;
  float time;
  Point V;
  Point C;
  float p;
  Time t1;
  CircleShape proy;
  proyectil(float a, float b,float angle,float v_0){
    proy.setRadius(5);
    C.x=a;
    C.y=b;
    proy.setPosition(C.x,C.y);
    range = (pow(v_0,2) * sin((2 * angle) * PI/180)) / 9.8;
    max_height = (pow(v_0,2) * pow(sin(angle * PI/180),2)) / (2*9.8);
    time=(2*pow(v_0,2) * sin((2 * angle) )) / gravity;
    t1 = milliseconds(time/(range/0.01));
    V.x = range / 2;
    V.y = 500 - max_height;
    p = pow(V.x, 2) / (4 *(490 - V.y));
    cout << "V( " << V.x << " , " << V.y << " )" << endl;
  }
  void movimiento(){
    C.x+=0.1;
    C.y=(pow(C.x -V.x, 2) + (4 * V.y * p)) / (4*p);
    proy.setPosition(C.x,C.y);
    cout << C.x << " " << C.y << endl;
  }
  
};


