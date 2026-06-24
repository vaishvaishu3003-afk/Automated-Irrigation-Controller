#define SOIL_PIN 34
#define RELAY_PIN 26
#define LED_PIN 27

int threshold = 2000;

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

void loop() {

  int moisture = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture Value: ");
  Serial.println(moisture);

  if (moisture > threshold) {

    Serial.println("Soil Dry -> Irrigation ON");

    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

  } else {

    Serial.println("Soil Wet -> Irrigation OFF");

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println("--------------------");

  delay(2000);
}