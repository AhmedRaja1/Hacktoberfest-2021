/****** Pin Definition ******/
const int cameraSignalPin = 13;
const int buzzerPin = 11;
const int receiverInputChannel6Pin = PC4;

uint32_t receiverInput, receiverInputPrevious, now;
int cameraCounter = 0;

/****** Prototypes ******/
void receiverChannel6();

void setup() {
  /****** Pins Setup ******/
  pinMode(cameraSignalPin, OUTPUT);
  digitalWrite(cameraSignalPin, HIGH); //Normally high
  pinMode(receiverInputChannel6Pin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); //Normally high

  //Serial Begin
  Serial_begin(115200);

  //Attach interrupt
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_IT);
  disableInterrupts();
  EXTI_SetExtIntSensitivity( EXTI_PORT_GPIOC, EXTI_SENSITIVITY_RISE_FALL);
  enableInterrupts();
  attachInterrupt(INT_PORTC & 0xFF, receiverChannel6, 0);
}

void loop() {
  delayMicroseconds(3500);
  Serial_print_u(receiverInput);
  Serial_print_s("\n");

  if (receiverInput > 1900 && receiverInput < 2000) {     //Switch in Position 1
    digitalWrite(cameraSignalPin, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(cameraSignalPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
}

void receiverChannel6 () {
  now = micros();
  if (digitalRead(receiverInputChannel6Pin) == 1) {
    receiverInputPrevious = now;
  } else {
    receiverInput = now - receiverInputPrevious;
  }
}
