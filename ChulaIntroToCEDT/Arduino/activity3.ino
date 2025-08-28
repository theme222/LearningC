
int buttonAPressed = 0;
int buttonBPressed = 0;

const char password[] = "ABAB";
char currentInput[4];

int inputIndex = 0;

const int GREEN_PIN = 8;
const int RED_PIN = 9;

const int BUTTONA_PIN = 2;
const int BUTTONB_PIN = 3;

void setup()
{
    pinMode(RED_PIN, INPUT);
    pinMode(GREEN_PIN, INPUT);
    pinMode(BUTTONA_PIN, OUTPUT);
    pinMode(BUTTONB_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int currentButtonAPressed = digitalRead(BUTTONA_PIN);
    int currentButtonBPressed = digitalRead(BUTTONB_PIN);

    if (buttonAPressed == 0 && currentButtonAPressed == 1) {
        Serial.println('A');
        currentInput[inputIndex] = 'A';
        inputIndex++;
    }

    if (buttonBPressed == 0 && currentButtonBPressed == 1) {
        Serial.println('B');
        currentInput[inputIndex] = 'B';
        inputIndex++;
    }

    if (inputIndex == 4) // password filled in
    {
        bool correctPassword = true;
        for (int i = 0; i < 4; i++)
        {
            if (password[i] != currentInput[i])
            {
                correctPassword = false;
                break;
            }
        }

        if (correctPassword)
            digitalWrite(GREEN_PIN, HIGH);
        else
            digitalWrite(RED_PIN, HIGH);
    }


    buttonAPressed = currentButtonAPressed;
    buttonBPressed = currentButtonBPressed;
}
