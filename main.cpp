#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

    vector<arco> vectorFigura;
    int size = crearImagen(500, 500, vectorFigura);

    ofstream settings ("settings.txt");
    if (settings.is_open())
    {
        settings << size;
        settings.close();
    }

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

    int size;
    if (pAltura < pAnchura){
        size = pAltura;
    } else{
        size = pAnchura;
    }


    double pntx=-57.5;
    double pnty=00;
    double cont = -57.5;
    int contLineas = 0;

    int currentYHorizontal=-57.5;
    

    int cantTotal = (size/115+2)* ((size/115+1)*2-1);
    
    for(int i = 0; i < cantTotal; i++){

        if (cont > size){
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

        int yHorizontal=currentYHorizontal;

        int offsetX = 4;

        int anchoX=1;
        int alturaX=8;
        int anchoY=1;
        int alturaY=17;
        

        //verticales izq
        for(int x = 1; x < 30; x+=2){
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,pi/2, 3*pi/2));
            pntx+=offsetX;
            anchoX++;
            alturaX+=8;
        }
        
        alturaX-=8;
        pntx-=offsetX;
        pVector.push_back(arco(pntx,pnty,0,alturaX,pi/2, 3*pi/2));
        
        
        
        //horizontales arriba
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,-pi,0));
            yHorizontal+=4;
            anchoY+=8;
            alturaY++;
        
        
        }
        
        yHorizontal-=4;
        anchoY-=8;
        pVector.push_back(arco(pntx,yHorizontal,anchoY,0,-pi,0));
        
        
        //horizontales abajo
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,0,pi));
            yHorizontal+=4;
            anchoY-=8;
            alturaY--;
        }
        
        //verticales der
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

