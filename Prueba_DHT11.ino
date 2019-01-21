/**********************************************Capitulo 13 - Sensor DHT11    *****************************************************
*                                                                                                                                 *
*    En este treceavo capitulo aprenderemos a utilizar el sensor de DHT11. Este sensor nos permite conocer el valor de la humedad *
*  y la temperatura del ambiente. Este sensor se presume de tener una alta fiabilidad y estabilidad debido a su señal digital     *
*  Lo podemos encontrar de dos manera con una PCB o solamente el sensor. La diferencia esta en que la PCB nos incluye un led que  *
*  nos avisa el funcionamiento y una resistencia de 5k en pull-up y otra diferencia son los pines esta cuenta solo con 3 pines y  *
*  la version sin PCB tiene 4 pines.                                                                                              *
*                                                                                                                                 *
*  Para lograr esto necesitaremos:                                                                                                *
*                                                                                                                                 *
*  -Placa arduino Uno                                                                                                             *
*  -1 Sensor DHT11.                                                                                                               *
*  -Protoboard                                                                                                                    *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                              Facebook: ESociety *
*                                                                                                              GitHub: eSociety97 *
*                                                                                                                                 *
*                                                         #NuncaDejenDeCrear                                                      *
***********************************************************************************************************************************/ 


#include <DHT.h>

#include "DHT.h"
#define DHTPIN 2    
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

float h;
float t;
float f;
float temperatura;
float humedad;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();

}
void loop() {     
     sensorHT();
}
void sensorHT(){
    
  float h = dht.readHumidity();  
  float t = dht.readTemperature();  
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);
  
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  temperatura = t;
  humedad = h;
  }
