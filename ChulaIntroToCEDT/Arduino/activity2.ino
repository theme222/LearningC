
const int LED_PIN = 2;
double val = 0;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() > 0)
    {
        char input = Serial.read();
        val = (input - '0') / 10.0;
    }
    if (val != 0) digitalWrite(LED_PIN, HIGH);
    delayMicroseconds((unsigned int)(val * 1000));
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds((unsigned int)((1-val) * 1000));
}
