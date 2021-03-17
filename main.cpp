#include <iostream>
#include <vector>

using namespace std;

class punto{
public:
    double x;
    double y;

    punto(double pX, double pY){
        x = pX;
        y = pY;
    }
};
void crearImagen(int pAltura, int pAnchura, vector<punto> &pVector);

int main(){

    //sepa diosito como vamos a hacer esto

    vector<punto> vectorFigura;
    crearImagen(5, 5, vectorFigura);

    for(auto pun : vectorFigura){
        cout << "(" << pun.x << ", " << pun.y << ")" << endl;
    }

    return 0;
}

void crearImagen(int pAltura, int pAnchura, vector<punto> &pVector){
    double y1 = 0.25;
    double y2 = 0.25;
    double y3 = 0.75;
    double y4 = 0.75;

    for (double x = 0; x <= 1; x = x + 0.01){
        pVector.push_back(punto(x*pAnchura, y1*pAltura));
        pVector.push_back(punto(x*pAnchura, y2*pAltura));
        pVector.push_back(punto(x*pAnchura, y3*pAltura));
        pVector.push_back(punto(x*pAnchura, y4*pAltura));

        if (x < 0.25 || (x >= 0.5 && x < 0.75)){
            y1 = y1 - 0.01;
            y2 = y2 + 0.01;
            y3 = y3 - 0.01;
            y4 = y4 + 0.01;
        } else{
            y1 = y1 + 0.01;
            y2 = y2 - 0.01;
            y3 = y3 + 0.01;
            y4 = y4 - 0.01;
        }

        if (y1 < 0.009){
            y1 = 0;
        }
    }
}

