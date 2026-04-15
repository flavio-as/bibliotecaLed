/** 
 * Autor: Flávio S.
 * Nome:  Acendimento Piscando
 * V. 1.0.0
 * Neste exemplo, temos um LED acoplado ao pino 45 de um circuito
 * que pisca a 6 Hz por 60 ciclos (acendimento e apagamento)
 * quando o botão afixado ao pino 0 é pressionado.
 */

#include <Arduino.h>
#include <LED.h>

const uint32_t botaoA = 0;

Led ledX(45);

void setup(){
  digitalWrite(botaoA, INPUT_PULLUP);
}

void loop(){
  static bool estadoAnteriorBotaoA = 1;
  bool estadoAtualBotaoA = digitalRead(botaoA);
  
  if(estadoAnteriorBotaoA && !estadoAtualBotaoA) ledX.piscar(6, 60);
  
  estadoAnteriorBotaoA = estadoAtualBotaoA;

  ledX.update();
}