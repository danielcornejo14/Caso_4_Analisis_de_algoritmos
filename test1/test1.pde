void setup(){
  //String[] settings = loadStrings("../settings.txt");
  //System.out.println(settings);
  
  size(500,500);
  background(255);
  noFill();
  smooth();
  
  String[] file = loadStrings("../caso4.txt");
  
  for(int i = 0; i < file.length; i++){
    String[] param = split(file[i], ";");
    arc(Float.valueOf(param[0]),Float.valueOf(param[1]),Float.valueOf(param[2]),Float.valueOf(param[3]),Float.valueOf(param[4]),Float.valueOf(param[5]));
  }
}
