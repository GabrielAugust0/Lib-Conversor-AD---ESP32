#ifndef CONVERSORAD_H
#define CONVERSORAD_H

#include <Arduino.h>
#include <WiFi.h>
#include <stdexcept>

class ConversorAD{

    private:
        int _resolution;
        int _adcPin;
        double _voltageRef;
        
        // Métodos privados
        int getChannel();
        bool isWifiConnected();
        bool checkVoltage();
        bool checkResolution();
    
    public:
        // Construtor
        ConversorAD(int resolution, int adcPin, double voltageRef);
        // Métodos públicos
        double leituraAD();  // Declarando leituraAD()
        double calibracao(int offset);  // Declarando calibracao()

};

#endif