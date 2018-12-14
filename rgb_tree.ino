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
int groups[10][3];

/* init function*/
void setup() {
  //filling groups-Array
  groups[0][0] = G0_R;
  groups[0][1] = G0_G;
  groups[0][2] = G0_B;

  groups[1][0] = G1_R;
  groups[1][1] = G1_G;
  groups[1][2] = G1_B;

  groups[2][0] = G2_R;
  groups[2][1] = G2_G;
  groups[2][2] = G2_B;

  groups[3][0] = G3_R;
  groups[3][1] = G3_G;
  groups[3][2] = G3_B;

  groups[4][0] = G4_R;
  groups[4][1] = G4_G;
  groups[4][2] = G4_B;

  groups[5][0] = G5_R;
  groups[5][1] = G5_G;
  groups[5][2] = G5_B;

  groups[6][0] = G6_R;
  groups[6][1] = G6_G;
  groups[6][2] = G6_B;

  groups[7][0] = G7_R;
  groups[7][1] = G7_G;
  groups[7][2] = G7_B;

  groups[8][0] = G8_R;
  groups[8][1] = G8_G;
  groups[8][2] = G8_B;

  groups[9][0] = G9_R;
  groups[9][1] = G9_G;
  groups[9][2] = G9_B;
  //Serial.begin(9600);

  pinMode(6, OUTPUT); // inhA
  pinMode(7,OUTPUT); // inhB
  pinMode(11,OUTPUT); // A
  pinMode(10,OUTPUT); // B
  pinMode(9,OUTPUT); // C

  pinMode(3, OUTPUT); // PWM
}

void loop() {
  //read = analogRead(3);     //Read potentiometer
  //Serial.println(read/4);
  //analogWrite(3, read/4);   //Write PWM Dutycycle


  breathRGB();
  for(int i=0; i<1000; i++){
    all_leds_on();
  }
  cycle_all_leds();
}

void all_leds_on() {
  set_leds(groups[0][1]);
  UDELAY(SW_DELAY);
  set_leds(groups[1][2]);
  UDELAY(SW_DELAY);
  set_leds(groups[2][0]);
  UDELAY(SW_DELAY);
  set_leds(groups[3][1]);
  UDELAY(SW_DELAY);
  set_leds(groups[4][2]);
  UDELAY(SW_DELAY);
  set_leds(groups[5][0]);
  UDELAY(SW_DELAY);
  set_leds(groups[6][1]);
  UDELAY(SW_DELAY);
  set_leds(groups[7][2]);
  UDELAY(SW_DELAY);
  set_leds(groups[8][0]);
  UDELAY(SW_DELAY);
  set_leds(groups[9][1]);
  UDELAY(SW_DELAY);
}

void cycle_all_leds() {
  for(int i=0; i<10; i++){
    for(int j=0; j<3; j++){
      set_leds(groups[i][j]);
      delay(500);
    }
  }
}

void breathRGB(){
  int duty;
  for(int k = 0; k<3; k++){
    for(int j = 0; j<10 ;j++){
      duty = 0;
      while(duty<255){
        for(int i = 0; i<100; i++){
          set_leds(groups[j][k]);
        }
        set_PWM(duty);
        duty++;
      }
      while(duty>0){
        for(int i = 0; i<100; i++){
          set_leds(groups[j][k]);
        }
        set_PWM(duty);
        duty--;
      }
    }
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

void set_PWM(int duty){
  if(duty <= 255){
    analogWrite(3, duty);
  }
}
