using namespace std;
int speed = 700;
int cod[8] = {1,2,3,4,5,6,7,8};
/*  para não usar a lib com a ferramenta str2int
	decidir codificar:
    Onde o "-" significa piscada longa e "." piscada curta.
	/ significa tempo de pausa.
    	    1    2   3    4  5  6   7   8
    	    o    l   a    m  u  n   d   o
    morse: --- .-.. .- / -- ..- -. -.. ---
    Quando as luzes acenderem por 2 segundos é sinal que
    a frase terminou.
	*/
int i = (sizeof(cod)/2);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j<=i;j++){
  	int x = cod[j];
    switch(x){
      case 1:
            digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed/2);
   	  	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed/2);
     	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed+speed/4);
    	break;
      case 2:
      	  digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed/2);
          digitalWrite(13,1);
          delay(speed);
          digitalWrite(13,0);
          delay(speed/2);
    	  digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed+speed/4);
    	break;
      case 3:
    	  digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed/2);
      	  digitalWrite(13,1);
          delay(speed);
          digitalWrite(13,0);
          delay(speed+speed/2+speed/4);
    	break;
      case 4:
    		digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed/2);
     	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed+speed/4);
    	break;
      case 5:
    	  digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed/2);
          digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed/2);
          digitalWrite(13,1);
          delay(speed);
          digitalWrite(13,0);
          delay(speed+speed/4);
    	break;
      case 6:
      	  digitalWrite(13,1);
          delay(speed);
          digitalWrite(13,0);
          delay(speed/2);
    	  digitalWrite(13,1);
          delay(speed/2);
          digitalWrite(13,0);
          delay(speed+speed/4);
    	break;
      case 7:
        digitalWrite(13,1);
        delay(speed);
        digitalWrite(13,0);
        delay(speed/2);
        digitalWrite(13,1);
        delay(speed/2);
        digitalWrite(13,0);
        delay(speed/2);
    	digitalWrite(13,1);
        delay(speed/2);
        digitalWrite(13,0);
        delay(speed+speed/4);
    	break;
      case 8:
     	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed/2);
   	  	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed/2);
     	    digitalWrite(13,1);
            delay(speed);
            digitalWrite(13,0);
            delay(speed+speed/4);
    	break;
    }
    if(j==sizeof(cod)/2){
      digitalWrite(13,1);
      delay(2000);
      digitalWrite(13,0);
      delay(300);
      digitalWrite(13,1);
      delay(2000);
      digitalWrite(13,0);
      delay(300);
    }
  }
}
