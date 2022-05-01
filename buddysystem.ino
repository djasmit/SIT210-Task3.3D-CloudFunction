
//LED pins
int ledW = D8;
int ledP = D7;


//initialize LED pin outputs and subscribe to event
void setup() {
  pinMode(ledW, OUTPUT);
  pinMode(ledP, OUTPUT);
  Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

void loop() {
    //nothing here
}

//method to handle operations on receiving subscription event
void myHandler(const char *event, const char *data)
{
    //flash our red led if we receive a wave
    if (strcmp(data, "wave") == 0) {
        flashLED(ledW);
    }
    
    //flash our blue led if we receive a pat
    else if (strcmp(data, "pat") == 0) {
        flashLED(ledP);
    }    
}

//flashes the selected led 3 times
void flashLED(int LED) {
    for (int i = 0; i < 3; i++) {
        
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
        delay(1000);
    }
}

