# Caso_4_Analisis_de_algoritmos

## Explicacion del algoritmo

La funcion de este algoritmo es calcular coordenadas para el dibujo de lineas curvas dentro de un area establecida de pintado y asi dibujar un el patron #9 del cuarto caso del curso Analisis de algoritmos.

#### Analisis del algoritmo
-->O(n)
-->f(n) = 5040*n + 17
'''c++
int crearImagen(int pAltura, int pAnchura, vector<arco> &pVector){
    double pi = 3.1415927; //-->1

    //Se define el tamaño de la imagen (se hace cuadrada)
    int size;
    if (pAltura < pAnchura){ //-->1
        size = pAltura; //-->1
    } else{
        size = pAnchura; //-->1
    }


    //Se definen los puntos para crear las líneas
    double pntx=-57.5; //-->1
    double pnty=00; //-->1
    double cont = -57.5; //-->1
    int contLineas = 0; //-->1

    int currentYHorizontal=-57.5; //-->1
    
    int largo = ((size - 57.5)/115) + 2; //-->4

    //Se averigua el total de cuadrados por pintar
    int cantTotal = 2*(largo*largo); //-->3
    
    //-->1
    for(int i = 0; i < cantTotal; i++){ //-->3
        //Cada vez que se termina una fila, se hacen los ajustes para comenzar la siguiente
        if (cont >= size){ //-->1
            contLineas++; //-->2
            if (contLineas%2 == 1){ //-->2
                cont = 0; //-->1
                pntx = 0; //-->1
            } else{
                cont = -57.5; //-->1
                pntx = -57.5; //-->1
            }
            pnty += 57.5; //-->1
            currentYHorizontal += 57.5; //-->1
        }

        //Se definen mas variables para crear las líneas
        int yHorizontal=currentYHorizontal; //-->1

        int offsetX = 4; //-->1
        int anchoX=1; //-->1
        int alturaX=8; //-->1
        int anchoY=1; //-->1
        int alturaY=17; //-->1
        

        //Se crean las líneas verticales de la izquierda del cuadrado
        //-->1
        for(int x = 1; x < 30; x+=2){ //-->3
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,pi/2, 3*pi/2));//-->9
            pntx+=offsetX; //-->2
            anchoX++; //-->2
            alturaX+=8; //-->2
        }
        
        alturaX-=8; //-->2
        pntx-=offsetX; //-->2
        pVector.push_back(arco(pntx,pnty,0,alturaX,pi/2, 3*pi/2)); //-->9
        
        
        
        //Se crean las líneas horizontales de arriba del cuadrado
        //-->1
        for(int x =1; x < 30; x+=2){ //-->3
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,-pi,0)); //-->9
            yHorizontal+=4; //-->2
            anchoY+=8; //-->2
            alturaY++; //-->2
        }
        
        yHorizontal-=4; //-->2
        anchoY-=8; //-->2
        pVector.push_back(arco(pntx,yHorizontal,anchoY,0,-pi,0)); //-->9
        
        
        //Se crean las líneas horizontales de abajo del cuadrado
        //-->1
        for(int x =1; x < 30; x+=2){ //-->3
            pVector.push_back(arco(pntx,yHorizontal,anchoY,alturaY,0,pi)); //-->9
            yHorizontal+=4; //-->2
            anchoY-=8; //-->2
            alturaY--; //-->2
        }
        
        //Se crean las líneas verticales de la derecha del cuadrado
        //-->1
        for(int x = 1; x < 30; x+=2){ //-->3
            pVector.push_back(arco(pntx,pnty,anchoX,alturaX,-(pi/2), +(pi/2))); //-->9
            pntx+=offsetX; //-->2
            anchoX--; //-->2
            alturaX-=8; //-->2
        }


        cont += 115; //-->2
    }
    return size; //-->1
}
'''
## Instrucciones de ejecuccion

* Correr el main.exe
* Abrir el archivo test1\test1.pde (processing)
* Seleccionar la prueba 1 o 2 mediante la variable path en la linea 1
* Correr el codigo 
