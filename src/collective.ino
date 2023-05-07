
void setup()   {                
  Serial.begin(9600);
  // dont judge my pin setting mess
  // using INPUT_PULLUP the teensy is using internal resistors
  // this is especially nice because you can wire things directly on to the board.

  // 3 Way Switch ON-off-on
  pinMode(2, INPUT_PULLUP);
  // 3 Way Switch on-off-ON
  pinMode(3, INPUT_PULLUP);
  // 2 Way Stich ON-off
  pinMode(4, INPUT_PULLUP);
  // tactile button
  pinMode(7, INPUT_PULLUP);

  // Analog Pin A0 I believe, works without specific setup anyways
  //pinMode(0, INPUT);
}

void loop()                     
{
  int tactileButton = !digitalRead(7);
  Joystick.button(1, tactileButton);
  
  int pitch = analogRead(0);
  Joystick.slider(pitch);

  int switchUp = !digitalRead(2);
  int switchDown = !digitalRead(3);
  // programatically on-on-on switch
  int switchMiddle = !switchDown && !switchUp;
  Joystick.button(2, switchUp);
  Joystick.button(3, switchMiddle);
  Joystick.button(4, switchDown);

  int simpleSwitch = !digitalRead(4);
  Joystick.button(5, simpleSwitch);
  // programatically on-on switch
  Joystick.button(6, !simpleSwitch);

  delay(50);
}