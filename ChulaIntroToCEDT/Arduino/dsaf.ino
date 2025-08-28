
int LED_PIN = 2;
int BUTTON_PIN = 3;
int buttonState = 0;
bool currentLight = false;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}


void loop()
{
  int currentButtonState = digitalRead(BUTTON_PIN);
  if (buttonState == 0 && currentButtonState == 1){
    if (currentLight) digitalWrite(LED_PIN, LOW);
    else digitalWrite(LED_PIN, HIGH);
    currentLight = !currentLight;
  }
  buttonState = currentButtonState;
}
