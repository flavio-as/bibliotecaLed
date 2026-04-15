# Biblioteca LED

Biblioteca para controle não-bloqueante de LED com Arduino e ESP32.

A classe `Led` permite:

- Ligar o LED continuamente;
- Ligar por tempo determinado;
- Desligar o LED;
- Alternar o estado entre ligado e desligado;
- Fazê-lo piscar continuamente, ou;
- Fazê-lo piscar uma quantidade definida de vezes.

O funcionamento é não bloqueante, usando `millis()`.  
Por isso, o método `update()` deve ser chamado repetidamente no escopo `loop()`.

---

## Estrutura da biblioteca

```text
bibliotecaLed/
├── Library.json
├── README.md
├── LICENSE
├── src/
│   ├── LED.h
│   └── LED.cpp
└── examples/
    └── 01acendimentoContinuo/
    │   └── 01acendimentoContinuo.cpp
    └── 02acendimentoTemporizado/
    │   └── 02acendimentoTemporizado.cpp
    └── 03acendimentoPiscando/
    │   └── 03acendimentoPiscando.cpp
    └── 04alternandoEstado/
    │   └── 04alternandoEstado.cpp
    └── 05desligandoLED/
        └── 05desligandoLED.cpp