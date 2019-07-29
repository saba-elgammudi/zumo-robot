
//collects data from an analog sensor 
int pin1 = 2;  
int pin2 = 1;  
int pin3 = 3;  

class Des 
{  
 public:
    int pin;
    float dist;
    float volt;
    
    Des(int p) : pin(p) {
    }
    
    float discm() 
    { 
      int des = analogRead(pin);
        Serial.println(des);
        float volt = des * (5.0/1023.0); 
        Serial.println(volt);
        float dist= 1.0/(volt/23.0);
        Serial.println(dist);
        return dist;  
    } 
}; 

class gear_selector {
  Des middle;
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


 Des distance1(pin1);
 
 
void loop()
{
 

  
   
 }
