void setup(){
  size(500,500);
  background(255);
  noFill();
  smooth();
  
  String[] file = loadStrings("../caso4.txt");
  
  for(int i = 0; i < file.length; i++){
    String[] param = split(file[i], ";");
    arc(Float.valueOf(param[0]),Float.valueOf(param[1]),Float.valueOf(param[2]),Float.valueOf(param[3]),Float.valueOf(param[4]),Float.valueOf(param[5]));
  }
  
  
  
//  print(PI);
 // for(int i = 0; i < 2; i++){
    
 //   int anchoX=1;
 //   int alturaX=6;
 //   int anchoY=1;
 //   int alturaY=6;
    
 //   int yHorizontal=24;
    
 // //Lineas verticales izquierda
 // for(int x = 1; x < 30; x+=2){
 //   arc(pntx,pnty,anchoX,alturaX,PI/2, 3*PI/2);
 //   pntx+=4;
 //   anchoX++;
 //   alturaX+=8;
 // }
  
 // arc(pntx-4,pnty,0,alturaX-8,PI/2, 3*PI/2);
 // alturaX-=8;
 // pntx-=4;
  
  
 // //Lineas horizontales arriba
 // for(int x =1; x < 30; x+=2){
 //   arc(pntx,yHorizontal,anchoY,alturaY,-PI,0);
 //   yHorizontal+=4;
 //   anchoY+=8;
 //   alturaY++;
  
  
 // }
  
 // arc(pntx,yHorizontal-4,anchoY-8,0,-PI,0);
 // yHorizontal-=4;
 // anchoY-=8;
 // //Lineas horizonatales abajo
 // for(int x =1; x < 30; x+=2){
 //   arc(pntx,yHorizontal,anchoY,alturaY,0,PI);
 //   yHorizontal+=4;
 //   anchoY-=8;
 //   alturaY--;
  
  
 // }
 // //Lineas horizontales izquierda
 //for(int x = 1; x < 30; x+=2){
 //   arc(pntx,pnty,anchoX,alturaX,-(PI/2), +(PI/2));
 //   pntx+=4; //+=6 pero se pierden algunas lineas
 //   anchoX--;
 //   alturaX-=8;
    
 // }
 // }
}
