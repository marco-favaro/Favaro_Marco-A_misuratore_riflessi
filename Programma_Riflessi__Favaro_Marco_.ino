int button1 = 11;
int buzzer1 = 12;
int led1 = 13;
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);             
int Tmp_Rnd_Buzzer;
int Tmp_Rnd_Led;
double led_ms;
double tempo_totale;
double tempo_parziale;
 
void setup() 
{
  pinMode(button1, INPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(led1, OUTPUT);      
  lcd.begin(16,2);
  randomSeed(analogRead(0));      
}
void loop()
{
  led_riflessi();
  buzzer_riflessi();
}
void buzzer_riflessi()
{
  Tmp_Rnd_Buzzer = random(500, 5000);
  delay(Tmp_Rnd_Buzzer);
  tone(buzzer1, 500, 5000);
  tempo_parziale = millis();
  while(digitalRead(button1) == LOW);
  noTone(buzzer1);
  lcd.clear();
  led_ms = millis();
  tempo_totale = led_ms - tempo_parziale;
  lcd.print(tempo_totale);
}
void led_riflessi()
{
  Tmp_Rnd_Led = random(1000, 5000); 
  delay(Tmp_Rnd_Led);
  digitalWrite(led1, HIGH);
  tempo_parziale = millis();
  while (digitalRead(button1) == LOW);
  digitalWrite(led1, LOW);
  lcd.clear();
  led_ms = millis();
  tempo_totale = led_ms - tempo_parziale;
  lcd.print(tempo_totale);
}
