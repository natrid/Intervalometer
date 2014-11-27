/* Arduino ohjelma Intervalometer
 By. Daniel Natri
 */
const int optPin = 12; //Pin which supplies voltage to 4N25
int kuvienMaara = 10;
int painalluksenPituus = 250;
int intervalLength = 10000; //in ms(milliseconds)

const int buttonPin = 2; 
const int ledPin =  13; 

boolean lastButton = LOW;
boolean currentButton = LOW;


void setup() 
{ 
  pinMode(ledPin, OUTPUT);    
  pinMode(buttonPin, INPUT);  

  pinMode(optPin, OUTPUT);

  otaKuva(kuvienMaara, optPin,intervalLength);
} 

void loop() 
{ 



  //  currentButton = debounce(lastButton);
  //  if (currentButton == HIGH) {     
  //    // turn LED on:    
  //    digitalWrite(ledPin, HIGH);  
  //  } 
  //  else {
  //    // turn LED off:
  //    digitalWrite(ledPin, LOW); 
  //  }
  //    lastButton = currentButton;
}

void otaKuva(int maara, int pin, int interval)
{
  if (maara>1)
  {
    for(int i=0;i<maara;i++)
    {
      digitalWrite(pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(painalluksenPituus); 
      digitalWrite(pin, LOW); 
      digitalWrite(ledPin, LOW);
      delay(interval);
    }
  }
  else
  {
    while(maara<1)
    {
      digitalWrite(pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(painalluksenPituus); 
      digitalWrite(pin, LOW); 
      digitalWrite(ledPin, LOW);
      delay(intervalLength);
    }
  }
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(buttonPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(buttonPin);
    return current;
  }
}



