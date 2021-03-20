#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Se define la clase arco que es usada para representar una linea curva
class arco{
public:
    double x;
    double y;
    int ancho;
    int alto;
    double inicio;
    double final;

    arco(double pX, double pY, int pAncho, int pAlto, double pInicio, double pFinal){
        x = pX;
        y = pY;
        ancho = pAncho;
        alto = pAlto;
        inicio = pInicio;
        final = pFinal;
    }
};

int crearImagen(int pAltura, int pAnchura, vector<arco> &pVector);



int main(){

    //Se define un vector para almacenar todos los arcos y se llama a la funcion
    vector<arco> vectorFigura;
    int size = crearImagen(230, 230, vectorFigura);

    //
    ofstream settings ("settings.txt");
    if (settings.is_open())
    {
        settings <<  size;
        settings.close();
    }
    else cout << "Unable to open file";

    //Se crea un archivo con todos los arcos que se crearon
    //para poder abrir el archivo en processing 
    ofstream myfile ("caso4.txt");
    if (myfile.is_open())
    {
        for(auto pun : vectorFigura){
            myfile <<  pun.x << ";" << pun.y << ";" << pun.ancho << ";" << pun.alto << ";"
            << pun.inicio << ";" << pun.final << "\n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    return 0;
}



int crearImagen(int pAltura, int pAnchura, vector<arco> &pVector){
    double pi = 3.1415927;

    //Se define el tamaño de la imagen (se hace cuadrada)
    int size;
    if (pAltura < pAnchura){
        size = pAltura;
    } else{
        size = pAnchura;
    }


    //Se definen los puntos para crear las lineas
    double pntx=-57.5;
    double pnty=00;
    double cont = -57.5;
    int contLineas = 0;

    int currentYHorizontal=-57.5;
    
    int largo = ((size - 57.5)/115) + 2;

    //Se averigua el total de cuadrados por pintar
    int cantTotal = largo*largo + (largo)*(largo);
    
    for(int i = 0; i < cantTotal; i++){
        //Cada vez que se termina una fila, se hacen los ajustes para comenzar la siguiente
        if (cont >= size){
            contLineas++;
            if (contLineas%2 == 1){
                cont = 0;
                pntx = 0;
            } else{
                cont = -57.5;
                pntx = -57.5;
            }
            pnty += 57.5;
            currentYHorizontal += 57.5;
        }

        //Se definen mas variables para crear las lineas
        int yHorizontal=currentYHorizontal;

        int offsetX = 4;

        int anchoX=1;
        int alturaX=8;
        int anchoY=1;
        int alturaY=17;
        

        //Se crean las lineas verticales de la izquierda del cuadrado
        for(int x = 1; x < 30; x+=2){
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,pi/2, 3*pi/2));
            pntx+=offsetX;
            anchoX++;
            alturaX+=8;
        }
        
        alturaX-=8;
        pntx-=offsetX;
        pVector.push_back(arco(pntx,pnty,0,alturaX,pi/2, 3*pi/2));
        
        
        
        //Se crean las lineas horizontales de arriba del cuadrado
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,-pi,0));
            yHorizontal+=4;
            anchoY+=8;
            alturaY++;
        
        
        }
        
        yHorizontal-=4;
        anchoY-=8;
        pVector.push_back(arco(pntx,yHorizontal,anchoY,0,-pi,0));
        
        
        //Se crean las lineas horizontales de abajo del cuadrado
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,0,pi));
            yHorizontal+=4;
            anchoY-=8;
            alturaY--;
        }
        
        //Se crean las lineas verticales de la derecha del cuadrado
        for(int x = 1; x < 30; x+=2){
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,-(pi/2), +(pi/2)));
            pntx+=offsetX;
            anchoX--;
            alturaX-=8;
        }


        cont += 115;
    }
    return size;
}

