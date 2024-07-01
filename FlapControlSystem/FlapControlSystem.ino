// With Pi 
//3,5,6 servo
#include <LiquidCrystal_I2C.h>// 
LiquidCrystal_I2C lcd(0x27, 16,2);

#include <Servo.h>
#define ledPin     13

Servo myServo1;
Servo myServo2;
Servo myServo3;

int IR_Sensor = 7;
int motor_Pin = A1;

int input_1 = 2;
int input_2 = 4;
int input_3 = 6;
int input_4 = A0;

// TCS230 pins connected to Arduino
const int s0 = 8;
const int s1 = A3;
const int s2 = 10;
const int s3 = 11;
const int out = 12;

int sensor_1Pin = A2;

int red = 0;
int green = 0;
int blue = 0;


uint8_t volatile  sonar_data =0;

int count = 0;
uint8_t state=0;
int count_1value =0;
int sensor_1State = 0;
int prestate1 =0;


 void setup() 
 {
  Serial.begin(9600);
  lcd.init();                       
  lcd.init();
  lcd.backlight();
  myServo1.attach(3);
  myServo2.attach(5);
  myServo3.attach(9);
  
  myServo1.write(0);
  delay(200);
  myServo2.write(170);
  delay(200);
  myServo3.write(180);
  
  lcd.clear();
  lcd.print("   WELCOME  ");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print(" Classification ");
  lcd.setCursor(0, 1);
  lcd.print("    System  ");
  delay(2000);
  lcd.clear();

  pinMode(IR_Sensor, INPUT_PULLUP);
  pinMode(sensor_1Pin, INPUT_PULLUP);

  pinMode(input_1, INPUT);
  pinMode(input_2, INPUT);
  pinMode(input_3, INPUT);
  
  pinMode(out, INPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motor_Pin, OUTPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(ledPin, LOW);
  digitalWrite(motor_Pin, HIGH);

 lcd.print("wait.......!");
 
 }

void loop ()
{
    lcd.print("Start Conveyer");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("wait Signal from");
    lcd.setCursor(0,1);
    lcd.print("  Raspberry Pi  ");
    state=2;

     if(state==2)
  {
   
  color();
  Serial.print("R =");
  Serial.print(red, DEC);
  Serial.print(" G = ");
  Serial.print(green, DEC);
  Serial.print(" B = ");
  Serial.print(blue, DEC);
  Serial.print("\t");
  
if (red < blue && red < green && red < 25)
  {
  //  if (green - blue >= 10 && green - blue <= 25 && green - ( 2 * red ) >= 8 )
    if (red >= 14 && red <= 20 && green>=30  && green <=50 && blue>=27  && blue <=40)
    {
     // lcd.clear();
    //  lcd.setCursor(0, 0);
    //  lcd.print("Color Detection");
    //  lcd.setCursor(6, 1);
    //  lcd.print("Color : ");
    //  lcd.print("Red");
    //  Serial.println(" - (Red Color)");
     // delay(1000);
     // lcd.clear();
    }

   Serial.println();
  // digitalWrite(motor_Pin, LOW);
  // state=0;

if(digitalRead(input_1)==HIGH)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Miscillaneous ");
  lcd.setCursor(0,1);
  lcd.print("   Detected   ");
  digitalWrite(motor_Pin, LOW);
  delay(22000);   //////////////////////////  time Change                
  digitalWrite(motor_Pin, HIGH);
  myServo1.write(70);
  delay(2000);
  lcd.clear();
  myServo1.write(10);
  delay(500);
  digitalWrite(motor_Pin, HIGH);
 // state=1;
 }

if(digitalRead(input_2)==HIGH)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    Glass   ");
  lcd.setCursor(0,1);
  lcd.print("   Detected   ");
  
  digitalWrite(motor_Pin, LOW);
  
  delay(16000);     /////////////////////  time Change
  
  myServo2.write(100);
  delay(2000);
  myServo2.write(170);
  lcd.clear();
  delay(500);
  digitalWrite(motor_Pin, HIGH);

}

if(digitalRead(input_3)==HIGH)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    Plastic  ");
  lcd.setCursor(0,1);
  lcd.print("   Detected   ");
  
  digitalWrite(motor_Pin, LOW);
  
  delay(13000);  ////////////////////////////  time Change
  
  myServo3.write(140);
  delay(2000);
  myServo3.write(180);
  lcd.clear();
  delay(500);
  digitalWrite(motor_Pin, HIGH);
  
  lcd.clear();

}

}

}
void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
