/* Interrupt Notes
 
1- External interrupt on pin 2,3 ONLY
2- Interrupt Function/API: attachInterrupt(digitalPinToInterrupt(InterruptPin),ISR_function,Interrupt_Signal_Mode);
    ISR_Function : will be written under void loop() and will be something like:
                                                void myInterruptFunction(){
                                                  // Code
          
                                                }
    Interrupt Signal Mode: LOW , CHANGE , RISING , FALLING                                             
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
