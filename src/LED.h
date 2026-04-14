#ifndef LED_h
#define LED_h
#include <Arduino.h>

class Led {
    private:
    uint8_t pino;
    bool estado;

    bool desligarPorTempo = false;
    uint32_t desligarNoMomento;

    void funcaoPiscar();
    
    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    public:
    Led(uint8_t pin); // Metodo construtor: deverá ter o mesmo nome da classe

    void update();

    void ligar();
    void ligar(uint32_t tempoLigado_ms);

    void desligar();
    
    void piscar ();
    void piscar(float frequencia);
    void piscar(float frequencia, uint16_t repeticoes);

    bool getEstado(); 
    uint8_t getPino();

    void setEstado(bool estado);

    void alternar();

    void funcaoDesligamento();

};

#endif