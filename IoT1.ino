#define echoPin 7
#define trigPin 8
int led1 = 3;
int led2 = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long jarak, ketinggianAir, duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(18);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 28.5;
  ketinggianAir = 18.5 -jarak;
  Serial.println("Ketinggian Air = ");
  Serial.print(ketinggianAir);
  Serial.println(" cm");
  if (ketinggianAir < 5){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.println("Air Tersedia");
  }else if (ketinggianAir > 5) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("Air Habis");
  }
  delay(2000);
}
