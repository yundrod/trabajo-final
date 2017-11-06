#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

using namespace std;
using namespace sf;
class Point{
 public:
  float x,y;
  Point(float p_x, float p_y){
    x = p_x;
    y = p_y;
  }
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


