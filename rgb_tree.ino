#define SW_DELAY 50 // switch delay in microseconds

#define PRINT(x) { Serial.println(x); }
#define UDELAY(x) { delayMicroseconds(x) ; }

/* Register mapping */
#define G0_B 0x18
#define G0_G 0x19
#define G0_R 0x1A

#define G1_B 0x1B
#define G1_G 0x1C
#define G1_R 0x1D

#define G2_B 0x1E
#define G2_G 0x1F
#define G2_R 0x08

#define G3_B 0x09
#define G3_G 0x0A
#define G3_R 0x0C

#define G4_B 0x0D
#define G4_G 0x0E
#define G4_R 0x0B

#define G5_B 0x0F
#define G5_G 0x10
#define G5_R 0x11

#define G6_B 0x12
#define G6_G 0x13
#define G6_R 0x14

#define G7_B 0x15
#define G7_G 0x16
#define G7_R 0x17

#define G8_B 0x00
#define G8_G 0x01
#define G8_R 0x02

#define G9_B 0x03
#define G9_G 0x04
#define G9_R 0x05

#define G10_B 0x06
#define G10_G 0x07

/* End register mapping */

/* Masks */
#define MASK_INHA 0x10
#define MASK_INHB 0x08
#define MASK_C 0x04
#define MASK_B 0x02
#define MASK_A 0x01


//Function prototypes
void breathRGB();
void set_PWM(int duty);     //Takes value between 0-255 for dutycycle
/* global variables */
int read=0;

/* init function*/
void setup() {

  //Serial.begin(9600);

  pinMode(6, OUTPUT); // inhA
  pinMode(7,OUTPUT); // inhB
  pinMode(11,OUTPUT); // A
  pinMode(10,OUTPUT); // B
  pinMode(9,OUTPUT); // C

  pinMode(3, OUTPUT); // PWM
}

void loop() {
  read = analogRead(3);
  //Serial.println(read/4);
  analogWrite(3, read/4);

  all_leds_on();
}

void all_leds_on() {

  set_leds(G0_B);
  UDELAY(SW_DELAY);

  set_leds(G0_G);
  UDELAY(SW_DELAY);

  set_leds(G0_R);
  UDELAY(SW_DELAY);

  set_leds(G1_B);
  UDELAY(SW_DELAY);

  set_leds(G1_G);
  UDELAY(SW_DELAY);

  set_leds(G1_R);
  UDELAY(SW_DELAY);

  set_leds(G2_B);
  UDELAY(SW_DELAY);

  set_leds(G2_G);
  UDELAY(SW_DELAY);

  set_leds(G2_R);
  UDELAY(SW_DELAY);

  set_leds(G3_B);
  UDELAY(SW_DELAY);

  set_leds(G3_G);
  UDELAY(SW_DELAY);

  set_leds(G3_R);
  UDELAY(SW_DELAY);

  set_leds(G4_B);
  UDELAY(SW_DELAY);

  set_leds(G4_G);
  UDELAY(SW_DELAY);

  set_leds(G4_R);
  UDELAY(SW_DELAY);

  set_leds(G5_B);
  UDELAY(SW_DELAY);

  set_leds(G5_G);
  UDELAY(SW_DELAY);

  set_leds(G5_R);
  UDELAY(SW_DELAY);

  set_leds(G6_B);
  UDELAY(SW_DELAY);

  set_leds(G6_G);
  UDELAY(SW_DELAY);

  set_leds(G6_R);
  UDELAY(SW_DELAY);

  set_leds(G7_B);
  UDELAY(SW_DELAY);

  set_leds(G7_G);
  UDELAY(SW_DELAY);

  set_leds(G7_R);
  UDELAY(SW_DELAY);

  set_leds(G8_B);
  UDELAY(SW_DELAY);

  set_leds(G8_G);
  UDELAY(SW_DELAY);

  set_leds(G8_R);
  UDELAY(SW_DELAY);

  set_leds(G9_B);
  UDELAY(SW_DELAY);

  set_leds(G9_G);
  UDELAY(SW_DELAY);

  set_leds(G9_R);
  UDELAY(SW_DELAY);

  set_leds(G10_B);
  UDELAY(SW_DELAY);

  set_leds(G10_G);
  UDELAY(SW_DELAY);
}

void cycle_all_leds() {

  set_leds(G0_B);
  delay(500);

  set_leds(G0_G);
  delay(500);

  set_leds(G0_R);
  delay(500);

  set_leds(G1_B);
  delay(500);

  set_leds(G1_G);
  delay(500);

  set_leds(G1_R);
  delay(500);

  set_leds(G2_B);
  delay(500);

  set_leds(G2_G);
  delay(500);

  set_leds(G2_R);
  delay(500);

  set_leds(G3_B);
  delay(500);

  set_leds(G3_G);
  delay(500);

  set_leds(G3_R);
  delay(500);

  set_leds(G4_B);
  delay(500);

  set_leds(G4_G);
  delay(500);

  set_leds(G4_R);
  delay(500);

  set_leds(G5_B);
  delay(500);

  set_leds(G5_G);
  delay(500);

  set_leds(G5_R);
  delay(500);

  set_leds(G6_B);
  delay(500);

  set_leds(G6_G);
  delay(500);

  set_leds(G6_R);
  delay(500);

  set_leds(G7_B);
  delay(500);

  set_leds(G7_G);
  delay(500);

  set_leds(G7_R);
  delay(500);

  set_leds(G8_B);
  delay(500);

  set_leds(G8_G);
  delay(500);

  set_leds(G8_R);
  delay(500);

  set_leds(G9_B);
  delay(500);

  set_leds(G9_G);
  delay(500);

  set_leds(G9_R);
  delay(500);
}

void breathRGB(){
  int duty = 0;
  while(duty<255){
    for(int i = 0; i<100; i++){
      set_leds(G0_R);
      set_leds(G2_R);
      set_leds(G3_R);
      set_leds(G4_R);
      set_leds(G5_R);
      set_leds(G6_R);
      set_leds(G7_R);
      set_leds(G8_R);
      set_leds(G9_R);
    }
    set_PWM(duty);
    duty++;
  }
  while(duty>0){
    for(int i = 0; i<100; i++){
      set_leds(G0_R);
      set_leds(G2_R);
      set_leds(G3_R);
      set_leds(G4_R);
      set_leds(G5_R);
      set_leds(G6_R);
      set_leds(G7_R);
      set_leds(G8_R);
      set_leds(G9_R);
    }
    set_PWM(duty);
    duty--;
  }


}

void set_leds(int group_color) {

    int inhA = (group_color & MASK_INHA) >> 4;
    int inhB = (group_color & MASK_INHB) >> 3;
    int C = (group_color & MASK_C) >> 2;
    int B = (group_color & MASK_B) >>1;
    int A = group_color & MASK_A;

    //PRINT(inhA)
    //PRINT(inhB)
    //PRINT(C)
    //PRINT(B)
    //PRINT(A)

   set_pins(inhA, inhB, C, B, A);
}

void set_pins(int pin0, int pin1, int pin2, int pin3, int pin4) {
  if (pin0 == 1 || pin0 == 0)
    digitalWrite(6, pin0);
  else
    PRINT("INVALID INPUT ON PIN 6")

  if (pin1 == 1 || pin1 == 0)
    digitalWrite(7, pin1);
  else
    PRINT("INVALID INPUT ON PIN 7")

  if (pin2 == 1 || pin2 == 0)
    digitalWrite(9, pin2);
  else
    PRINT("INVALID INPUT ON PIN 9")

  if (pin3 == 1 || pin3 == 0)
    digitalWrite(10, pin3);
  else
    PRINT("INVALID INPUT ON PIN 10")

  if (pin4 == 1 || pin4 == 0)
    digitalWrite(11, pin4);
  else
    PRINT("INVALID INPUT ON PIN 11")
}

set_PWM(int duty){
  if(duty <= 255){
    analogWrite(3, duty);
  }
}
