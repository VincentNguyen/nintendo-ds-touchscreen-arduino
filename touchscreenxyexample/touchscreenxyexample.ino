//This program measures the coordinates of x and y, and will constantly update on wherever the touchscreen is touched.

int y1 = A0;
int y2 = A2;
int x1 = A3;
int x2 = A1;

void setup() {
  Serial.begin(9600);
} 

//Configures the specified pins to input/ouput
int readX(){
  pinMode(y1, INPUT);
  pinMode(x2, OUTPUT);
  pinMode(y2, INPUT);
  pinMode(x1, OUTPUT);

  digitalWrite(x2, LOW);
  digitalWrite(x1, HIGH);
  
  delay(10);
  return analogRead(y1);
}

int readY(){

  pinMode(y1, OUTPUT);
  pinMode(x2, INPUT);
  pinMode(y2, OUTPUT);
  pinMode(x1, INPUT);

  digitalWrite(y1, LOW);
  digitalWrite(y2, HIGH);
  delay(10); 
  return analogRead(x2);
}

void loop()
{
  int x = readX();
  int y = readY();

   if(x < 1000 & y < 1000){
    Serial.print("x coordinate: ");
    Serial.print(x-100);
    Serial.print(" ||");
    Serial.print(" y coordinate: ");
    Serial.println(y- 130);
  }
//Reads at a slower value, to see the difference in coordinates. 
//Increase for more accurate and faster read
  delay(500); 

}
