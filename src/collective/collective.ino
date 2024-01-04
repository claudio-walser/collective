
void setup()   {                
  Serial.begin(9600);
}
void loop()                     
{
 
  int pitch = analogRead(0);
  Joystick.slider(pitch);
  Serial.println(pitch);
  
  int thrust = analogRead(1);
  Joystick.sliderLeft(thrust);
  Serial.println(thrust);
  
  delay(200);
}