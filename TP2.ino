// C++ code
//
int r1=8; 
int o1=9; 
int g1=10; 

int r2=11; 
int o2=12; 
int g2=13; 

const int LIGHT_SONSOR = A0; 
const int BUTTON_DROIT = 7 ;
const int BUTTON_GAUCHE =6; 

int i=0;

void setup()
{
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  
  pinMode(BUTTON_DROIT,INPUT);
  pinMode(BUTTON_GAUCHE,INPUT);

  Serial.begin(9600); 

}

void loop()
{
  if(analogRead(LIGHT_SONSOR) > 400){
    digitalWrite(r1, HIGH);
    digitalWrite(g2, HIGH);
    //delay(3000);
    for(i=0;i<100 && digitalRead(BUTTON_GAUCHE)==0 ;i++){ 
    	delay(30);
    }
    digitalWrite(g2, LOW);
    digitalWrite(o2, HIGH);
    delay(2000);
    digitalWrite(o2, LOW);
    digitalWrite(r1, LOW);

    digitalWrite(r2, HIGH);
    digitalWrite(g1, HIGH);
   
    // faire une boucle pour tester si le user n'appuis pas sur le bouton 
    for(i=0;i<100 && digitalRead(BUTTON_DROIT)==0 ;i++){ 
    	delay(30);
    }
    digitalWrite(g1, LOW);
    digitalWrite(o1, HIGH);
    delay(2000);
    digitalWrite(o1, LOW);
    digitalWrite(r2, LOW);
  }else{ 
    digitalWrite(o2, HIGH);
    digitalWrite(o1, HIGH);
    delay(500);
    digitalWrite(o1, LOW);
    digitalWrite(o2, LOW);
    delay(1000);
  }

}