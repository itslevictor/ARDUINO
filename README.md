# ARDUINO
Arduino aula Instalações multimida

## ATIVIDADE 1

No primeiro contato com Arduino, percebi uma semelhança com Processing, que logo mais foi confirmada pelo professor que a linguagem tem relação com o Arduino.


Utilizando Tinkercad podemos visualizar o exemplo feito em sala:

A placa conectada no computador pela entrada USB (na esquerda), acima o LED conectado seu lado positivo no GND (polo positivo) e lado negativo no pino 13 (polo negativo). Vale ressaltar que o pino escolhido foi arbitrário para facilitar a montagem do LED, pode-se alternar entre 0 - 13 para entrada de polo negativo.
Uma vez conectado, fizemos um código inicial simples, para o LED acender e apagar.
Versão 1:

```C++
void setup() {
  pinMode(13, OUTPUT);
}


void loop() {
      digitalWrite(13,1);
      delay(150);
      digitalWrite(13,0);
      delay(150);
}
```

Observando o código, podemos notar a configuração do pino no setup como “13” e “output” mostrando qual o pino será utilizado e de que forma (no caso saída de energia). Note também que no loop, dentro da função “digitalWrite” temos novamente “13” seguido de “1” e mais abaixo “0” ligando com o conceito de booleanos, temos que “1” é ligado e “0” desligado. Finalizando com delay, ou seja, tempo que esta função permanecerá.


Uma vez ambientalizado, desenvolvi a versão 2 do código, que está no arquivo "aula 02". Agora, de forma mais confortável, temos a forma final com a frase “Ola mundo” em código morse, versão 3 encontrada neste repositório como "atividade 1 - codigo morse".

## ATIVIDADE 2

Já no segundo momento, mais ambientados, codificamos e produzimos um sensor luminoso, veja o código:

```C++
int valor;

void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode (13, OUTPUT);
  
}
void loop(){
  valor =  analogRead(A0);
  if (valor <=500){
  digitalWrite(13, 1);
  delay(200);
  Serial.println("tudo escuro");
  delay(100);
  }
  else {
    Serial.println("Luz luz!");
    delay(100);
    digitalWrite(13, 0);
    delay(10);
    }
}
```
Interessante como este simples código pode ser utilizado em luzes de emergência ou sensores mais básicos!.
