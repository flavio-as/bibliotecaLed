#ifndef LED_h
#define LED_h
#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não-bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, 
 * piscar continuamente e por quantidade de vezes definida.
 * 
 * @note O método update() deve ser continuamente chamado
 * no escopo loop().
 */
class Led {
    private:

    uint8_t pino;

    bool estado;

    bool desligarPorTempo = false;

    uint32_t desligarNoMomento;

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();
    
    uint32_t tempoAnteriorPiscar;

    uint32_t tempoEspera;

    bool estadoPiscar;

    uint16_t repeticoes;

    public:

    /**
     * @brief Constrói um objeto LED.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pin);

    /**
     * @brief Registra a mudança de estado.
     */
    void update();

    /**
     * @brief Ativa o LED continuamente.
     */
    void ligar();

    /**
     * @brief Ativa o LED e, após tempo determinado, desativa, em ms.
     * @param tempoLigado_ms Duração do estado ativo, em ms.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desativa o LED e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief Ativa o LED, piscando em 1Hz.
     */
    void piscar ();

    /**
     * @brief Ativa o LED, piscando em frequência definida.
     * @param frequencia Frequênca da piscada em hertz.
     */
    void piscar(float frequencia);

    /**
     * @brief Ativa o LED, piscando em frequência e por quantidade de vezes definidas.
     * @param frequencia Frequênca da piscada em hertz.
     * @param repeticoes Quantidade de vezes em que o LED cumprirá o ciclo aceso-apagado.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Lê o estado do pino e obtém retorno em bool.
     */
    bool getEstado(); 

    /**
     * @brief Lê o endereço do pino e obtém retorno.
     */
    uint8_t getPino();

    void setEstado(bool estado);

    void alternar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

};

#endif