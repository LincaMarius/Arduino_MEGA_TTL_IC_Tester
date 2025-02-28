/* 

Arduino MEGA Smart IC Tester

Author: Linca Marius Gheorghe

Version: 0.1 - 27.02.2025 

*/

// pins of the tested chip  1   2   3   4   5   6   7   8   9  10  11  12  13  14
// Arduino pins             |   |   |   |   |   |   |   |   |   |   |   |   |   |
const int chipPins [14] = {23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};

// Buffer to store incoming commands from serial port
String command;

// Finite State Machine
int state = 0;

void showCommands () {
  Serial.print ("\nCommands: IC name (eg. \"74LS00\"), or nr. of pins (eg. \"14pins\"), 74xx to test all TTL 74xx chip, 4xxx to test all CMOS 4xxx chips, help");
  command = "";
}

void test4xxx() {
  Serial.print ("\ntesting CMOS 4xxx chips");
  state = 0;
  command = "";
}

void test74xx() {
  Serial.print ("\ntesting TTL 74xx chips");
  state = 0;
  command = "";
}

void case16pins(){
  Serial.print ("\ntesting 16-pin chips");
  state = 0;
  command = "";
}

void case14pins(){
  Serial.print ("\ntesting 14-pin chips");
  state = 0;
  command = "";
}

void processCommand () {
    command.toUpperCase();
    Serial.print ("\nDEBUG Command=\"");
    Serial.print (command);
    Serial.print ("\"");
    if (command == "HELP")
      state = 2;
    else if (command == "H")
      state = 2; 
    else if (command == "--H")
      state = 2;
    else if (command == "\H")
      state = 2; 
    else if (command == "\n")
      state = 3;
    else if (command == "14PINS")
      state = 4;
    else if (command == "16PINS")
      state = 5;
    else if (command == "74XX")
      state = 6;
    else if (command == "4XXX")
      state = 7;
    else if (command == "")
      state = 0;
    else 
      state = 3;
}

void userInput () {
  // if serial data available, read the command and save it
  while (Serial.available() > 0)
    command = Serial.readStringUntil('\n');
}

void setup() {
  Serial.begin (9600);
  showCommands();
  state == 0;
  Serial.print ("\nArduino MEGA Smart IC Tester version 0.1 by Linca Marius Gheorghe");
  delay(100);
}

// Main loop
void loop() 
{
  // Finite State Machine
  // State 0 - Waiting for The User to enter a command
  if (state == 0) {
    userInput();
    state = 1;
  }

  //State 1 - Received command identification
  else if (state == 1) {
    processCommand();
  }

  //State 2 - executing the commands “Help”, “h”, “--h”, “\h”
  // display help message
  else if (state == 2) {
    showCommands();
    state = 0;
  }
  
  //State 3 - encountered unknown, invalid, or empty command
  // display wrong or empty command message
  // display help message
  else if (state == 3) {
    Serial.print ("\n\"");
    Serial.print (command);
    Serial.print ("\" is not recognized as a valid command");
    showCommands();
    state = 0;
  }

  //State 4 - encountered "14pins" command
  // Run all tests for all 14-pin chips
  else if (state == 4) {
    case14pins();
    state = 0;
  }

  //State 5 - encountered "16pins" command
  // Run all tests for all 16-pin chips
  else if (state == 5) {
    case16pins();
    state = 0;
  }

  //State 6 - encountered "74xx" command
  // Run all tests for all TTL 74xx chips
  else if (state == 6) {
    test74xx();
    state = 0;
  }

  //State 7 - encountered "4xxx" command
  // Run all tests for all CMOS 4xxx chips
  else if (state == 7) {
    test4xxx();
    state = 0;
  }

  delay(1000);
}
