#include <ConversorAD.h>

void setup() {

  Serial.begin(115200);
  delay(2000);

  try{
     ConversorAD sensor(12, 34, 1.1);
     Serial.println("Sensor inicializado com sucesso");

     while(true){
        Serial.print("Valor do ADC: ");
        Serial.println(sensor.leituraAD());
        delay(1000);
     }
  }
  catch(const std::exception &e){
      Serial.print("Erro ao inicializar: ");
      Serial.println(e.what());
  }
}

void loop() {


}
