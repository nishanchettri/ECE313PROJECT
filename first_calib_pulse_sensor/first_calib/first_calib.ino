bool bpmTiming = false;
bool beatComplete = false;
int lastTime=0;
int bpm=0;
#define upperTh 550 //upper threshlold
#define lowerTh 500 // lower threshhold
void bpmCalc()
{

 int value= analogRead(0);
  if (value>upperTh)
  {
    if(beatComplete)
    {
      bpm= millis()-lastTime;
      bpm= int(60/(float(bpm)/1000));
      bpmTiming=false;
      beatComplete=false;
    }
    if(bpmTiming == false)
    {
      lastTime= millis();
      bpmTiming= true;
    }
    
  }
  if((value<lowerTh)&(bpmTiming))
  {
    beatComplete=true;
  }
  Serial.println(bpm);
  Serial.println(value);
  delay(1000);
}

void setup()
{
  Serial.begin(112500);
}

void loop()
{
 bpmCalc();
}

