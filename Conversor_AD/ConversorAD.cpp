#include "ConversorAD.h"

int ConversorAD::getChannel(){
    switch(this->_adcPin){
        case 0:
            return 0; // Canal 2
        case 2:
            return 0; // Canal 2
        case 4:
            return 0; // Canal 2
        case 12:
            return 0; // Canal 2
        case 13:
            return 0; // Canal 2
        case 14:
            return 0; // Canal 2
        case 15:
            return 0; // Canal 2
        case 25:
            return 0; // Canal 2
        case 26:
            return 0; // Canal 2
        case 27:
            return 0; // Canal 2
        case 32:
            return 1; // Canal 1
        case 33:
            return 1; // Canal 1
        case 34:
            return 1; // Canal 1
        case 35:
            return 1; // Canal 1
        case 36:
            return 1; // Canal 1
        case 37:
            return 1; // Canal 1
        case 38:
            return 1; // Canal 1
        case 39:
            return 1; // Canal 1
        default:
            Serial.println("Canal não encontrado");
            return -1;
    }
}

bool ConversorAD::isWifiConnected(){
    return WiFi.status() == WL_CONNECTED;
}

bool ConversorAD::checkVoltage(){
    if(this->_voltageRef == 1.1 || this->_voltageRef == 1.5 || this->_voltageRef == 2.2 || this->_voltageRef == 3.9){
        return true;
    }
    return false;
}

bool ConversorAD::checkResolution(){
    if(this->_resolution == 6 || this->_resolution == 8 || this->_resolution == 10 || this->_resolution == 12){
        return true;
    }
    return false;
}

double ConversorAD::leituraAD(){
    int readADC = analogRead(this->_adcPin);
    return (this->_voltageRef * readADC) / this->_resolution;
}

double ConversorAD::calibracao(int offset){
    return leituraAD() - offset;
}

ConversorAD::ConversorAD(int resolution, int adcPin, double voltageRef){

    this->_resolution = resolution;
    this->_adcPin = adcPin;
    this->_voltageRef = voltageRef;

    if(this->getChannel() == -1){
        throw std::invalid_argument("Canal não encontrado");
    }

    if(this->getChannel() == 0 && isWifiConnected()){
        throw std::invalid_argument("Canal 2 não pode ser utilizado quando o WiFi está conectado");
    }

    if(!this->checkVoltage()){
        throw std::invalid_argument("Tensão de referência inválida");
    }

    if(!this->checkResolution()){
        throw std::invalid_argument("Resolução inválida");
    }
    
    analogReadResolution(this->_resolution);
}