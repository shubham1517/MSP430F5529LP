#define RST_PIN 10
#define LED RED_LED
int i=0;
String result;

int len;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);// this should be fast as the data from the debugging side should be more faster compared to that of the received side.
Serial1.begin(9600); // this is the baud rate of the external uart communication and it should be slow as compared to internal one
  Serial.println("Hello");// just for printing ine hello at the reset of the system
  pinMode(LED, OUTPUT); // This is the pin of the LED which will be set as OUTPUT  here
  pinMode(RST_PIN,OUTPUT); // setting the pin 10 as the output mode
  digitalWrite(RST_PIN,HIGH);// initially this pin should be high 
  
  
//the next lines till the end of setup indicates the pulse created by the signal as initially the LORA signal is high and we need to give the low to high signal before sending any signal to it 
delay(2000);// so always give a pulse low to high initially
digitalWrite(RST_PIN,LOW); 
delay(2000);
digitalWrite(RST_PIN,HIGH);
pinMode(LED, OUTPUT); 
 
}

void loop() {
  // put your main code here, to run repeatedly: 
digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500);   
  Serial1.write("AT+TEST=TXLRSTR, \"LoRaWAN Modem\"\r\n"); // here we have written the data on the LORA and we have sent the data as teh lora at commands which will interface with the LORA.
 // delay(500);
  if(Serial1.available()>0) // This should be the input from the port when the key is pressed or any data is sent from the keyboard
  {
    
    result=Serial1.readString(); // this reads the data in the string
    len = result.length();
    Serial.println(len);
    Serial.println(result); // this prints the result of the string in controller port
    i++;// increments the counter and prints it whenever this loop will be executed
  Serial.println(i);
  }
  delay(2000);
  }
