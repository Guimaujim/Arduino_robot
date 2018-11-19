int potpin=0; // Inicialitzar pin analògic 0, connectat al photoresistor
int buzzer=8; // Inicializar pin altaveu
int rightLedPin=10; // Inicializar pin led dreta
int leftLedPin=11; // Inicialitzar pin led esquerra
int val=0; // Inicialitzar variable val

void setup()
{
  pinMode(buzzer,OUTPUT); // Establir pin 8 com a pin de output
  pinMode(rightLedPin,OUTPUT); // Establir pin 11 com a pin de output
  pinMode(leftLedPin,OUTPUT); // Establir pin 10 com a pin de output
  Serial.begin(9600); // Establir 9600 bauds com a freqüència de transmissió de bits
}

void loop(){
  val=analogRead(potpin); // Llegir valor rebut del photoresistor
  Serial.println(val);// display the value of val
  
  if(val < 30){ // Si no hi ha llum encendre leds, sinò apagar i si hi ha molta llum fer sonar el altaveu
    analogWrite(rightLedPin,255);
    analogWrite(leftLedPin,255);
    noTone(buzzer);
  } else if(val > 200){
    analogWrite(rightLedPin,0);
    analogWrite(leftLedPin,0);
    tone(buzzer, 277);
  } else {
    analogWrite(rightLedPin,0);
    analogWrite(leftLedPin,0);
    noTone(buzzer);
  }
  
  delay(10); // Espera de 0.01 segons per no saturar la placa amb lectures
}
