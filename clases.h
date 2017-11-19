#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <string>

using namespace std;
using namespace sf;
#define PI 3.14159265

//variables
const float suelo = 500.0;
const float gravity =9.8;
class player{
public:
    RectangleShape canon;
    CircleShape body;
    RectangleShape healbar;
    Text angleview;
    Text id;
    float angle=90.0;
    float power=0.0;

    player(int x,int y,string name){
        body.setRadius(10);
        body.setPosition(x,y);
        canon.setOrigin(Vector2f(3,0));
        canon.setSize(Vector2f(6,-20));
        canon.setPosition(Vector2f(x+10,y+10));
        healbar.setSize(Vector2f(60,6));
        healbar.setPosition(Vector2f(x-20,y+40));
        //id.setFont(fuente);
        id.setString("olaaaaaaaaa");
        id.setCharacterSize(64);
        angleview.setPosition(Vector2f(10,10));
        //angle.setFont(fuente);
        angleview.setString("chauuuuuuuuuuuuu");
        angleview.setCharacterSize(64);
    }
    void movimiento(){
        if(Keyboard::isKeyPressed(Keyboard::Up)){

            canon.rotate(-0.1);
            angle+=0.1;

        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){

            canon.rotate(0.1);
            angle-=0.1;

        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){

            canon.move(-0.1,0);
            body.move(-0.1,0);
            healbar.move(-0.1,0);
            id.move(-0.1,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){

            canon.move(0.1,0);
            body.move(0.1,0);
            healbar.move(0.1,0);
            id.move(0.1,0);
        }

    }

};
class Point{
 public:
  float x,y;
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
  proyectil(float a, float b,float an,float v_0){
    proy.setRadius(5);
    angle=an;
    C.x=a;
    C.y=b;
    proy.setPosition(C.x,C.y);
    range = (pow(v_0,2) * sin((2 * an) * PI/180)) / gravity;
    max_height = (pow(v_0,2) * pow(sin(an * PI/180),2)) / (2*gravity);
    time=(2*v_0* sin(an) ) / gravity;
    t1 = milliseconds(time/(range/0.01));
    V.x = (range / 2)+C.x;
    V.y = (500 - max_height);
    p = pow(C.x-V.x, 2) / (4 *(C.y-V.y));
    cout << "V( " << V.x << " , " << V.y << " )" << endl;
  }
  void movimiento(){
      if (angle>90){
            C.x-=0.1;
      }
      else{
          C.x+=0.1;
      }
      C.y=(pow(C.x -V.x, 2)/ (4*p))+V.y;
      proy.setPosition(C.x,C.y);
  }

};


