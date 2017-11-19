#include "clases.h"
#include <string>


using namespace std;
using namespace sf;


int main(){
    string name;
    RectangleShape line(Vector2f(800, 5)); //linea del suelo
    line.setPosition(0,suelo);//posicion del suelo
    cout<<"ingrese nombre del jugador";
    cin>>name;

    player player1(0.0,suelo-20,name);//

    float aux1,angle, v_0;
    RenderWindow window(VideoMode(800, 600), "My render");
    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == Event::Closed){
                window.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }
        }
        // clear the window with black color
        window.clear(Color(0,0,0));
        window.draw(player1.body);
        window.draw(player1.canon);
        window.draw(line);
        window.draw(player1.id);
        window.draw(player1.healbar);
        window.draw(player1.angleview);
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            cout << "Inserta el angulo: ";
            cin >> angle;
            cout << "Inserta la velocidad inicial: ";
            cin >> v_0;
            if (angle==90){
                aux1=0;
            }
            else{
                aux1=angle;
            }
            proyectil bomba(player1.body.getPosition().x,player1.body.getPosition().y,aux1,v_0);
            while (bomba.C.y+5 <= suelo){
                window.display();
                window.draw(bomba.proy);
                window.clear(Color(0,0,0));
                window.draw(player1.body);
                window.draw(player1.canon);
                window.draw(bomba.proy);
                window.draw(line);
                bomba.movimiento();
                sleep(bomba.t1);
            }
        }


        window.display();
        player1.movimiento();
    }
    cout<<"end of program";
    return 0;
}
