#include <iostream>
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

int main(){

    vector<arco> vectorFigura;
    crearImagen(5, 5, vectorFigura);

    for(auto pun : vectorFigura){
        cout << "arc(" << pun.x << ", " << pun.y << ", " << pun.ancho << ", " << pun.alto << ", "
        << pun.inicio << ", " << pun.final << ")" << endl;
    }

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
    int ancho=1;
    int altura=6;

    for(int x = 1; x < 30; x+=2){
        pVector.push_back(arco(pntx,pnty,ancho,altura, pi/2, 3*pi/2));
        pntx+=6;
        ancho++;
        altura+=8;
        
    }
    pVector.push_back(arco(pntx-4,pnty,0,altura-8,pi/2, 3*pi/2));
    
    altura-=8;
    pVector.push_back(arco(pntx-2,pnty,ancho,altura,-(pi/2), + (pi/2)));
    pVector.push_back(arco(pntx,pnty,ancho,altura,-(pi/2), +(pi/2)));
    
    for(int x = 1; x < 30; x+=2){
        pVector.push_back(arco(pntx,pnty,ancho,altura,-(pi/2), +(pi/2)));
        pntx+=9; //+=6 pero se pierden algunas lineas
        ancho--;
        altura-=8;
        
    }

    // for (double x = 0; x <= 1; x = x + 0.01){
    //     pVector.push_back(punto(x*pAnchura, y1*pAltura));
    //     pVector.push_back(punto(x*pAnchura, y2*pAltura));
    //     pVector.push_back(punto(x*pAnchura, y3*pAltura));
    //     pVector.push_back(punto(x*pAnchura, y4*pAltura));

    //     if (x < 0.25 || (x >= 0.5 && x < 0.75)){
    //         y1 = y1 - 0.01;
    //         y2 = y2 + 0.01;
    //         y3 = y3 - 0.01;
    //         y4 = y4 + 0.01;
    //     } else{
    //         y1 = y1 + 0.01;
    //         y2 = y2 - 0.01;
    //         y3 = y3 + 0.01;
    //         y4 = y4 - 0.01;
    //     }

    //     if (y1 < 0.009){
    //         y1 = 0;
    //     }
    // }
}

