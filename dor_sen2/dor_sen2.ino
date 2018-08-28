int sen1=2;
int sen2=3;
int count=0;
int led=13;
int s1=0;
int s2=0;
int s3=0;
int s4=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(sen1,INPUT_PULLUP);
  pinMode(sen2,INPUT_PULLUP);
pinMode(13,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
 
  
 call(); 

// Serial.print("count");
}
void call()
{
  sensor();
  if(s1==1)
  {
    increment();
    }
  if(s2==1)
  {
    d();
    }
 Serial.print(count);
 
 if(count>0)
 {
  
  digitalWrite(13,HIGH);
  
  }
 else
 {
  digitalWrite(13,LOW);
 }
 
 }
void d()
{
  while(1)
  {sensors();
  if(s3==1)
  {
    count=count-1;
   delay(350);
   //Serial.print(count);
  break;
  }
  }
  }
void increment()
{
  while(1)
  {sensors();
  if(s4==1)
  {
    count=count+1;
  delay(350);
  // Serial.print(count);
 
   break;
    }
  
  }}
void sensor()
{
  
  s1=digitalRead(sen1);
  s2=digitalRead(sen2);
 Serial.print(s1);
 Serial.print("");
 Serial.print(s2);
 Serial.print("\n");
}
void sensors()
{
  
  s3=digitalRead(sen1);
  s4=digitalRead(sen2);
Serial.print(s3);
 Serial.print("");
 Serial.print(s4);
 Serial.print("\n");

}
