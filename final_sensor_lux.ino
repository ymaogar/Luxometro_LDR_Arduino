#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ
const int LDRPin = A0;   //Pin del LDR
 
int V;
int ilum;
 
void setup() 
{
   Serial.begin(9600);
   lcd.clear();
lcd.begin(16,2);
  lcd.print("luxometro");
  delay(2000);
   lcd.clear();
}
 
void loop()
{
   V = analogRead(LDRPin);         
 
   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
  
   Serial.println(ilum); 


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("lux:");
  lcd.setCursor(7, 0);
  lcd.print(ilum);
  delay(300);





   
}
