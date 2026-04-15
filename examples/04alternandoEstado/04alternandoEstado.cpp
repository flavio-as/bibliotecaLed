/** 
 * Autor: Flávio S.
 * Nome:  Alternador de nível lógico do LED
 * V. 1.0.0
 * Neste exemplo, temos um LED acoplado ao pino 45 de um circuito
 * que se acende a partir da inicialização e que apaga ou acende
 * quando o botão afixado ao pino 0 é pressionado.
 */

#include <Arduino.h>
#include <LED.h>

const uint32_t botaoA = 0;

Led ledX(45);

void setup(){
  digitalWrite(botaoA, INPUT_PULLUP);
  ledX.ligar();
}

void loop(){
  static bool estadoAnteriorBotaoA = 1;
  bool estadoAtualBotaoA = digitalRead(botaoA);
  
  if(estadoAnteriorBotaoA && !estadoAtualBotaoA) ledX.alternar();
  
  estadoAnteriorBotaoA = estadoAtualBotaoA;

  ledX.update();
}