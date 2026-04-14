#include "LED.h"

Led::Led(uint8_t pin):

    pino(pin),
    estado(LOW),
    desligarPorTempo(false),
    desligarNoMomento(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0) {

    pino = pin;
    pinMode(pino, OUTPUT);
}

void Led::update(){
    if(desligarPorTempo) funcaoDesligamento();
    
    if(estadoPiscar) funcaoPiscar();
    
    digitalWrite(pino, estado);
}

void Led::ligar(){
    estadoPiscar = false;       // redefinir valor
    desligarPorTempo = false;   // redefinir valor
    estado = HIGH;
}

void Led::ligar(uint32_t tempoLigado_ms){
    estadoPiscar = false;
    desligarPorTempo = true;
    desligarNoMomento = millis() + tempoLigado_ms;
    estado = HIGH;
}

void Led::desligar(){
    estadoPiscar = false;       // redefinir valor
    desligarPorTempo = false;   // redefinir valor
    estado = LOW;
}

void Led::alternar(){
    estado = !estado;
}

bool Led::getEstado(){
    return estado;
}

uint8_t Led::getPino(){
    return pino;
}

void Led::setEstado(bool estado){
    this->estado = estado;
}

void Led::piscar (){
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led::piscar(float frequencia){
    estadoPiscar = true;
    tempoEspera = (1000.0 / 2.0 * frequencia);
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    
}

void Led::piscar(float frequencia, uint16_t repeticoes){
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
}

void Led::funcaoPiscar(){
    if (millis() - tempoAnteriorPiscar >= tempoEspera){
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0){
            repeticoes--;
            if (!repeticoes){
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led::funcaoDesligamento(){
    if(millis() >= desligarNoMomento) {
        estado = LOW;
        desligarPorTempo = false;
    }   
}
