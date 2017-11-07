#include "modelo/clases.h"


using namespace std;
using namespace sf;


int main(){


  //Point coord(x , y);
  RectangleShape line(Vector2f(800, 5)); //linea base
  line.setPosition(0,suelo);
  CircleShape player1(10);
  player1.setPosition(0.0, suelo-20);
  float aux1, angle, v_0;
  cout << "Inserta el angulo: ";
  cin >> angle;
  cout << "Inserta la velocidad inicial: ";
  cin >> v_0;
	
  if (angle==90){
  	aux1=0;
  }
  else
  {
  	aux1=angle;
  }
  
  proyectil bomba(0.0,suelo-5,aux1,v_0);

  RenderWindow window(VideoMode(800, 600), "My render");
  Time p = seconds(5.0);
  while(window.isOpen()){
    Event event;
    while (window.pollEvent(event))
      {
	// "close requested" event: we close the window
	if (event.type == Event::Closed)
	  window.close();
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
	  window.close();
	}
      }
    // clear the window with black color
    window.clear(Color(0,0,0));
    // draw everything here...
    window.draw(player1);
    window.draw(bomba.proy);
    window.draw(line);
    // end the current frame
    window.display();
    bomba.movimiento();
    sleep(bomba.t1);
    if(bomba.C.y+5 > suelo){
      sleep(p);
      break;
    }



  }
  cout<<"end of program";

  return 0;
}
