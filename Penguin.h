#ifndef PENGUIN_H
#define PENGUIN_H

#define N_SERVOS 4
#define INTERVALTIME 10.0
#define CENTRE 90
#define AMPLITUDE 30
#define ULTRA_HIGH_RATE 0.3
#define HIGH_RATE 0.5
#define MID_RATE 0.7
#define LOW_RATE 1.0
#define ULTRA_LOW_RATE 1.5

#define YL_PIN 10
#define YR_PIN 9
#define RL_PIN 12
#define RR_PIN 6

#define BTN_RR_ADD   '7'
#define BTN_RL_ADD   '8'
#define BTN_YR_ADD   '9'
#define BTN_YL_ADD   '0'

#define BTN_RR_SUB   'a'
#define BTN_RL_SUB   'c'
#define BTN_YR_SUB   'd'
#define BTN_YL_SUB   'e'

#define ECHO_PIN 4//Ultrasound interface
#define TRIG_PIN 5

#define ST188_R_PIN A1//Infrared Controller Interface
#define ST188_L_PIN A0

#define INDICATOR_LED_PIN A5 //LED Indicator Interface

#define VOLTAGE_MEASURE_PIN A4 //Voltage Detection Interface


#include <Arduino.h>
#include "Oscillator.h"
#include <EEPROM.h>
#include "MY1690_16S.h"

class Penguin {
  public:
    Penguin(MY1690_16S& mp3Instance);

    /* movement methods */
    bool walk(int steps, int T, int dir);
    bool moveNServos(int time, int newPosition[]);
    bool delays(unsigned long ms);
    void servoAttach();
    void servoDetach();
    void servoInit();
    bool home();
    void homes(int millis_t);
    bool oscillate(int A[N_SERVOS], int O[N_SERVOS], int T, double phase_diff[N_SERVOS]);
    bool turn(int steps, int T, int dir);
    bool moonWalkRight(int steps, int T);
    bool moonWalkLeft(int steps, int T);
    bool crusaito(int steps, int T);
    bool swing(int steps, int T);
    bool upDown(int steps, int T);
    bool flapping(int steps, int T);
    bool run(int steps, int T);
    bool backyard(int steps, int T);
    bool backyardSlow(int steps, int T);
    bool goingUp(int tempo);
    bool drunk(int tempo);
    bool noGravity(int tempo);
    bool kickLeft(int tempo);
    bool kickRight(int tempo);
    bool legRaise(int tempo, int dir);
    bool legRaise1(int tempo, int dir);
    bool legRaise2(int steps, int tempo, int dir);
    bool legRaise3(int steps, int tempo, int dir);
    bool legRaise4(int tempo, int dir);
    bool sitdown();
    bool lateral_fuerte(boolean dir, int tempo);
    bool primera_parte();
    bool segunda_parte();
    void dance();
    void dance2();
    void dance3();
    void dance4();

    void setSerialFlag(boolean flag);
    bool getSerialFlag();
    char getBluetoothValue();
    void setBluetoothValue(char v);
    void getCommand();

    void trimServo(char btn);

    void startAnimation();

    int getDistance();
    void obstacleMode();
    void followMode();
    void st188Adjust(int dis);
    void Test_voltageMeasure(void);
  


  private:
    /* fine-tuning temporary storage variables*/
    int trim_rr;
    int trim_rl;
    int trim_yr;
    int trim_yl;
    int addr_trim_rr = 0;
    int addr_trim_rl = 1;
    int addr_trim_yr = 2;
    int addr_trim_yl = 3;

    MY1690_16S& mp3;

    int t = 495;
    double pause = 0;
    char btValue = '\0';            // it's "null", so if('\0') è false
    bool serial_flag = false;       // becomes "true" when there is serial communication
    float increment[N_SERVOS];
    unsigned long final_time;
    unsigned long interval_time;
    int oneTime;
    int iteration;
    Oscillator servo[N_SERVOS];
    int oldPosition[N_SERVOS];

    double distance_value = 0;
    int st188Val_L;
    int st188Val_R;
    long int ST188Threshold;
    long int ST188RightDataMin;
    long int ST188LeftDataMin;
    unsigned long infraredMeasureTime;

    unsigned long voltageMeasureTime;

  
};

#endif // PENGUIN_H
