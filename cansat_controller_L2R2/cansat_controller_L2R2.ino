#include "constant.h"
#include "motor.h"

Motor leftMotor = Motor(LEFT_MOTOR_VREF_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN);
Motor rightMotor = Motor(RIGHT_MOTOR_VREF_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN);
HardwareSerial & SerialRadio = Serial2; // Change the name of Serial from Serial3 -> SerialRadio

int i = 0;
char buf[100];
int l2;
int r2;
//int ls;
//int rs;
//int module;

void setup() {
  Serial.begin(9600);
  SerialRadio.begin(9600);
   leftMotor.stop();
   rightMotor.stop();
}

void loop() {
 if (SerialRadio.available()) {
    buf[i] = SerialRadio.read();
    if (buf[i] == 'e') {
      buf[i] = '\0';
      Serial.println(buf);

      l2 = atoi(strtok(buf, ","));
      r2 = atoi(strtok(NULL, ","));
//      left2 = atoi(strtok(NULL, ","));
//      right2 = atoi(strtok(NULL, ","));
//      module= atoi(strtok(NULL, ","));

      Serial.print(l2);
      Serial.print(",");
      Serial.print(r2);
//      Serial.print(",");
//      Serial.print(left2);
//      Serial.print(",");
//      Serial.print(right2);
//      Serial.print(module);
      Serial.print("\n");
// if(module==0){
      // digitalWrite(PIN_RELEASING_XBEE1,LOW);
       leftMotor.go(r2);
       rightMotor.go(l2);
   //     }
// else if(module==1){
//        digitalWrite(PIN_RELEASING_XBEE1,HIGH);
//        leftMotor.stop();
//        rightMotor.stop();
//        }
//  if(ls==0&&rs==255){
//        digitalWrite(PIN_RELEASING_XBEE1,HIGH);
//        leftMotor.stop();
//        rightMotor.stop();
//        }
//        else{
//         digitalWrite(PIN_RELEASING_XBEE2,LOW);
//         }
     
//    if(left<110){
//       leftMotor.setSpeedAt((127-left)*2);
//      }
//    if(left>140){
//       leftMotor.goBack((left-127)*2);
   // }
//    if(right<110){
//      rightMotor.setSpeedAt((127-right)*2);
//      }
//    if(right>140){
//       rightMotor.goBack((right-127)*2);
//      }
//    if(left>110&&left<140){
//       leftMotor.stop();
//      }
//    if(right>110&&right<140){
//       rightMotor.stop();
//      }
//      if(left2==255&&right2==255){
//        leftMotor.stop();
//        rightMotor.stop();
//        digitalWrite(PIN_RELEASING_XBEE2,HIGH);
//        }
//       if(left2!=255||right2!=255){
//        digitalWrite(PIN_RELEASING_XBEE2,LOW);
//        }
      
//    if(module==1){
//        digitalWrite(PIN_RELEASING_XBEE1,HIGH);
//        leftMotor.stop();
//        rightMotor.stop();
//        delay(150000);
//        digitalWrite(PIN_RELEASING_XBEE1,LOW);
//        }
//    if(module==2){
//        digitalWrite(PIN_RELEASING_XBEE2,HIGH);
//        leftMotor.stop();
//        rightMotor.stop();
//        delay(150000);
//        digitalWrite(PIN_RELEASING_XBEE2,LOW);
//        }
      i = 0;
    }
    else {
      i++;
    }
  }
}
