// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>


int photoresistor = A0; // This is where your photoresistor is plugged in. The other side goes to the "power" pin (below).

int power = A5; 
WidgetLED led1(V1);

BlynkTimer timer;
int analogvalue;
unsigned long notifyTime; //for the 30 minutes notifying block
unsigned long Startmil = 0; //to cacluate the run time of the AC
unsigned long Totalmil = 0; // to calcuate the total run time of the AC in milliseconds
int ACled = 0; // the statuse of the ON LED of the AC
int ACstatus = 0;
void sendSensor()
{
    analogvalue = analogRead(photoresistor); //read the LDR output
    if (analogvalue > 15) // and reading abve 15 would indicate that the AC is ON
    {
        analogvalue = analogRead(photoresistor); //recheck for out of range values
        if (analogvalue > 11 || ACled == 1) // making sure that out of range values don't fool the code
        {
            led1.on(); //turn the LED on in the Blynk App
            if((millis() - notifyTime > 30 * 60 * 1000 )) // execute every 30 minutes
            {
                //Startmil = millis();
                if (ACled == 0) //check if the AC is on for the first time to start counting
                {
                    ACled = 1;
                    Startmil = millis(); //starting counting
                }
                
                notifyTime = millis(); //for the porpuse of meat the condinion every 30 minutes
                Totalmil = (notifyTime - Startmil) / (60 * 1000); //calculate the run time of the AC
                if (Totalmil > 29 && Totalmil < 31) //if it's more than 29 minutes notify the user
                {
                    Particle.publish("AC", "Thirty", PRIVATE); 
                }
                else if(Totalmil > 59 && Totalmil < 61) //if it's more than 59 minutes notify the user with different message
                {
                    Particle.publish("AC", "Hour", PRIVATE);
                }
                else if(Totalmil > 180)
                {
                    Particle.publish("AC", "more", PRIVATE);
                }
            }
        }
    }
    
    else if(analogvalue < 14)
    {
        analogvalue = analogRead(photoresistor); 
        if (analogvalue < 13 )
        {
            led1.off(); //turn the LED off in the Blynk App
            ACled = 0;
            //Blynk.virtualWrite(V5, 0);}
        }
    }
}

void publishhh()
{
    analogvalue = analogRead(photoresistor);
    Particle.publish("LED", String(analogvalue), PRIVATE); 
    delay(1000);
}
void setup()
{


    pinMode(photoresistor,INPUT); 
    pinMode(power,OUTPUT);
    digitalWrite(power,HIGH);
    Blynk.begin("YOUR_AUTH_TOKEN");   // insert your blynk Auth Token here
    timer.setInterval(1000L, sendSensor); //send the sensor data to blynk every second
}


void loop()
{
    Blynk.run();  // Start Blynk running.
    timer.run();  // start Blynk Timer.
    publishhh();  // Publish the LED data for node-red

    
}
