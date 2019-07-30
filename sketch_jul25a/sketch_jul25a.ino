//collects data from an analog sensor 
#include "des.h"

int pin1 = 2;  
int pin2 = 1;  
int pin3 = 3;  
 
  
class gear_selector {
  sensor::Des middle;
  void (gear_selector::* state)();
void neutral() {
  if(middle.discm() > 5){
  state = &gear_selector::drive;}
  if(middle.discm() < 5){
  state = &gear_selector::reverse;}
}
void drive() {
  if(middle.discm() == 5){
  state = &gear_selector::neutral;}
}
void reverse(){
    if(middle.discm() == 5){
  state = &gear_selector::neutral;}
}
public:
gear_selector() : middle(A1), state(&gear_selector::neutral) {}
void init() {
}
void pool() { (this->*state)(); }
//gear_t _selected() { return _selected; }
}gear;

void setup(){
 Serial.begin(9600);             
}

void loop()
{  
} 
