#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class arco{
public:
    int x;
    int y;
    int ancho;
    int alto;
    double inicio;
    double final;

    arco(int pX, int pY, int pAncho, int pAlto, double pInicio, double pFinal){
        x = pX;
        y = pY;
        ancho = pAncho;
        alto = pAlto;
        inicio = pInicio;
        final = pFinal;
    }
};

void crearImagen(int pAltura, int pAnchura, vector<arco> &pVector);

int main(){

    vector<arco> vectorFigura;
    crearImagen(5, 5, vectorFigura);

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

    // for(auto pun : vectorFigura){
    //     cout <<  pun.x << ";" << pun.y << ";" << pun.ancho << ";" << pun.alto << ";"
    //     << pun.inicio << ";" << pun.final << endl;
    // }

    return 0;
}

void crearImagen(int pAltura, int pAnchura, vector<arco> &pVector){
    double pi = 3.1415927;

    int size;
    if (pAltura < pAnchura){
        size = pAltura;
    } else{
        size = pAnchura;
    }

    int pntx=10;
    int pnty=80;
    int anchoX=1;
    int alturaX=6;
    int anchoY=1;
    int alturaY=6;

    for(int i = 0; i < 3; i++){
        int yHorizontal=24;
    
        for(int x = 1; x < 30; x+=2){
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,pi/2, 3*pi/2));
            pntx+=4;
            anchoX++;
            alturaX+=8;
        }
        
        pVector.push_back(arco(pntx-4,pnty,0,alturaX-8,pi/2, 3*pi/2));
        alturaX-=8;
        pntx-=4;
        
        
        
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,-pi,0));
            yHorizontal+=4;
            anchoY+=8;
            alturaY++;
        
        
        }
        
        pVector.push_back(arco(pntx,yHorizontal-4,anchoY-8,0,-pi,0));
        yHorizontal-=4;
        anchoY-=8;
        
        for(int x =1; x < 30; x+=2){
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,0,pi));
            yHorizontal+=4;
            anchoY-=8;
            alturaY--;
        }
        
        for(int x = 1; x < 30; x+=2){
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,-(pi/2), +(pi/2)));
            pntx+=4; //+=6 pero se pierden algunas lineas
            anchoX--;
            alturaX-=8;
        }
    }

    // int pntx=10;
    // int pnty=80;
    // int ancho=1;
    // int altura=6;

    // for(int x = 1; x < 30; x+=2){
    //     pVector.push_back(arco(pntx,pnty,ancho,altura, pi/2, 3*pi/2));
    //     pntx+=6;
    //     ancho++;
    //     altura+=8;
        
    // }
    // pVector.push_back(arco(pntx-4,pnty,0,altura-8,pi/2, 3*pi/2));
    
    // altura-=8;
    // pVector.push_back(arco(pntx-2,pnty,ancho,altura,-(pi/2), + (pi/2)));
    // pVector.push_back(arco(pntx,pnty,ancho,altura,-(pi/2), +(pi/2)));
    
    // for(int x = 1; x < 30; x+=2){
    //     pVector.push_back(arco(pntx,pnty,ancho,altura,-(pi/2), +(pi/2)));
    //     pntx+=9; //+=6 pero se pierden algunas lineas
    //     ancho--;
    //     altura-=8;
        
    // }
}

