// codigo 1
int posicao = 0;
float posx = 50;
/* estados definem onde o jogo localiza, 0 = morte, 1 = jogo rodando, 2 = menu principal
*/
int state = 1;
float tick = 0;
PImage bg, flappy, cano;
//abrindo a variavel

void setup(){
  cano = loadImage("Flappy.png");
  bg = loadImage("backgroudn.png");
  flappy = loadImage("Flappy.png");
  //carregando as fotos
  size(1000,600);
}
// codigo 2
/*
int altura = 40;
posicao = 100;
*/
void draw(){
  println(posicao);
  switch(state){
    case 0:
      background(0);
      textAlign(CENTER,CENTER);
      textSize(100);
      fill(0, 408, 612);
      text("Voce Perdeu",width/2, height/2-200);
      textSize(50);
      text("Aperte ENTER para reiniciar",width/2, height/2-100);
      text("Aperte ESPACO para ir para o menu",width/2, height/2);
      break;
    case 1:
      background(0);
      posicao -=2;
     
      if(tick<=10){
        tick +=0.3;
      }
      rotate(tick*TWO_PI/360);
      // tenho que usar o translate para colocar o centro
      //https://processing.org/reference/translate_.html
      image(flappy, posx+2*tick, 100-posicao, width/8, height/8);
      if (posicao == -500){
        state = 0;
      // chama tela de game over, e reseta o jogo
      }
      break;
    case 2:
      background(0);
      text("Menu Principal",width/2, height/2-200);
      textSize(50);
      text("Aperte ENTER para iniciar",width/2, height/2-100);
      text("Aperte ESPACO para sair",width/2, height/2);
      break;
    }
    
}
  void keyPressed() {
  if (state == 1){
     posicao+=40;
     tick +=0.6;
  }
  if (state == 2 && keyCode == ' '){
    exit();
    // comando para voltar para o menu principal
  }
  if (state == 0 && keyCode == ' '){
    state = 2;
    posicao = 0;
    background(0);
    // comando para voltar para o menu principal
  }
  if ((state == 0 || state == 2) && keyCode == ENTER){
    state = 1;
    posicao = 0;
    background(0);
    // comando para reiniciar o jogo
  }

  // Codigo
  /*
  background(0);
  rect(posicao, 100-altura, 20, 100);
  posicao--;
  if (posicao < 0) {
    altura = int(random(100));
    posicao = 100;
  }
  if ((altura > 40) && (posicao > 20) && (posicao < 60)){
    fill(100);
  }
  else{
    fill(255);
    circle(50, 50, 20);
  */
}
