/* Interrupt Notes
 
1- External interrupt on pin 2,3 ONLY
2- Interrupt Function/API: attachInterrupt(digitalPinToInterrupt(InterruptPin),ISR_function,Interrupt_Signal_Mode);
    ISR_Function : will be written under void loop() and will be something like:
                                                void myInterruptFunction(){
                                                  // Code
          
                                                }
    Interrupt Signal Mode: LOW , CHANGE , RISING , FALLING  
    
 ****************************************************
 Circuit:
 *********
 Limit Switch : Comm pin to GND with 10K pull down resistor and connected to pin 2
                Normally Open Pin (NO) is connected to VCC [ 5v ]
 
 [ Limit Switch requires debouncing ]
 
 LED : Cathod terminal with current limiting resistor [ 330 Ohm ] to GND and Anode terminal to pin 7
*/
const int limitSwitch=2;
const int LED=7;
volatile bool state=LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(limitSwitch,INPUT);
pinMode(LED,OUTPUT);
attachInterrupt(digitalPinToInterrupt(limitSwitch),myBlink,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,state);
}
void myBlink(){
  state = !state;
}
