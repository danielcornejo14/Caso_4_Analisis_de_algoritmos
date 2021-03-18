void setup(){
  size(500,500);
  background(255);
  noFill();
  smooth();
  
  
  int pntx=10;
  int pnty=80;
  int ancho=1;
  int altura=6;
  
  print(PI);
  
  for(int d = 0; d < 3; d++){
      for(int x = 1; x < 30; x+=2){
    arc(pntx,pnty,ancho,altura,PI/2, 3*PI/2);
    pntx+=6;
    ancho++;
    altura+=8;
    
  }
  arc(pntx-4,pnty,0,altura-8,PI/2, 3*PI/2);
  
  altura-=8;
  pntx-=2;
  //arc(pntx-2,pnty,ancho,altura,-(PI/2), +(PI/2));
  //arc(pntx,pnty,ancho,altura,-(PI/2), +(PI/2));
  
  for(int x = 1; x < 30; x+=2){
    arc(pntx,pnty,ancho,altura,-(PI/2), +(PI/2));
    pntx+=6; //+=6 pero se pierden algunas lineas
    ancho--;
    altura-=8;
    
  }
}
  

  
  
  //arc(50,pnty,25,150,-(PI/2), +(PI/2));
  
}
