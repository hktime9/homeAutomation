int IRin= 7;
int val= 0;
int IRledPin= 11;

int drawerIn= 6;
int val2= 0;
int drawerSig= 13;
 
void setup()
{
  pinMode(IRledPin, OUTPUT);
  pinMode(IRin, INPUT);
  pinMode(drawerIn, INPUT);
  pinMode(drawerSig, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(IRin);
  val2= digitalRead(drawerIn);
  Serial.print(val);
  Serial.print(" ");
  Serial.println(val2);
  if(val==HIGH)
  {
    Serial.println("Sending IR Pulse");
    SendChannelUpCode();
  }
  if(val2==HIGH)
  {
    digitalWrite(drawerSig, HIGH);
  }
  else
  {
    digitalWrite(drawerSig, LOW);
  }  
}

void pulseIR(long microsecs) {
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendChannelUpCode() {
delayMicroseconds(39940);pulseIR(4120);
delayMicroseconds(4120);pulseIR(560);
delayMicroseconds(2020);pulseIR(580);
delayMicroseconds(2020);pulseIR(540);
delayMicroseconds(2040);pulseIR(560);
delayMicroseconds(2040);pulseIR(540);
delayMicroseconds(1020);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2020);pulseIR(580);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2020);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2040);pulseIR(520);
delayMicroseconds(1040);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2020);pulseIR(560);
delayMicroseconds(2040);pulseIR(540);
delayMicroseconds(1020);pulseIR(560);
delayMicroseconds(2020);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2020);pulseIR(560);
delayMicroseconds(1020);pulseIR(520);
delayMicroseconds(2060);pulseIR(560);
delayMicroseconds(8820);pulseIR(4140);
delayMicroseconds(4100);pulseIR(560);
delayMicroseconds(2060);pulseIR(540);
delayMicroseconds(2040);pulseIR(540);
delayMicroseconds(2020);pulseIR(600);
delayMicroseconds(2000);pulseIR(600);
delayMicroseconds(980);pulseIR(580);
delayMicroseconds(980);pulseIR(540);
delayMicroseconds(2060);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2020);pulseIR(580);
delayMicroseconds(980);pulseIR(560);
delayMicroseconds(2040);pulseIR(540);
delayMicroseconds(1020);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(1000);pulseIR(580);
delayMicroseconds(2000);pulseIR(580);
delayMicroseconds(2020);pulseIR(560);
delayMicroseconds(1000);pulseIR(540);
delayMicroseconds(2020);pulseIR(600);
delayMicroseconds(1000);pulseIR(560);
delayMicroseconds(2000);pulseIR(600);
delayMicroseconds(980);pulseIR(560);
delayMicroseconds(2000);pulseIR(600);
}









