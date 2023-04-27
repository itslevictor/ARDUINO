import processing.serial.*;
Serial arduinoPort;

int spriteX, spriteY, tamanhopassarinho; // posição e tamanho do sprite
int canoX, canoY, canoWidth, canoGap, canoSpeed; // posição, tamanho e velocidade dos canos
int score; // pontuação do jogador
boolean gameOver; // controlador

void setup() {
  
  arduinoPort = new Serial(this, Serial.list()[1], 9600);
  size(600,600);
  restart();
}

void restart() {
  // reinicia as variáveis do jogo
  spriteX = width / 4;
  spriteY = height / 2;
  tamanhopassarinho = 20;
  canoX = width;
  canoWidth = 50;
  canoGap = 200;
  canoY = round(random(canoGap, height - canoGap));
  canoSpeed = 3;
  score = 0;
  gameOver = false;
}

void draw() {
  
 
  background(200, 200, 255); // define a cor do fundo
  
  if (!gameOver) {
    // atualiza a posição do pássaro
    spriteY += 2;
    
    // desenha o pássaro
    fill(255, 255, 0);
    ellipse(spriteX, spriteY, tamanhopassarinho, tamanhopassarinho);
    fill(0, 255,255);
    rect(spriteX, spriteY, tamanhopassarinho, tamanhopassarinho);
        
    // atualiza a posição dos canos
    canoX -= canoSpeed;
    
    // desenha os canos
    fill(0, 200, 0);
    rect(canoX, 0, canoWidth, canoY);
    rect(canoX, canoY + canoGap, canoWidth, height - (canoY + canoGap));
    
    // verifica se o pássaro colidiu com os canos
    if (spriteX + tamanhopassarinho > canoX && spriteX < canoX + canoWidth) {
      if (spriteY < canoY || spriteY + tamanhopassarinho > canoY + canoGap) {
        gameOver = true;
      }
    }
    
    // verifica se o pássaro passou pelos canos
    if (spriteX > canoX + canoWidth && !gameOver) {
      score++;
      canoX = width;
      canoY = round(random(canoGap, height - canoGap));
    }
    
    // exibe a pontuação do jogador
    textSize(32);
    fill(255, 255, 0);
    text(score, 10, 40);
  } else {
    // exibe a mensagem de fim de jogo
    textSize(64);
    fill(255, 0, 0);
    text("GAME OVER", width / 2 - 200, height / 2 - 50);
    textSize(32);
    fill(255);
    text("Pontuação: " + score, width / 2 - 100, height / 2 + 50);
    text("Pressione 'R' para jogar novamente", width / 2 - 200, height / 2 + 100);
  }
  
  
   while (arduinoPort.available() > 0) {
    // Lê a mensagem
    String message = arduinoPort.readStringUntil('\n');
    
    // Processa a mensagem
    if (message != null) {
      message = message.trim();
      if (message.equals("BUTTON_PRESSED")) {
        // Ação a ser executada quando o botão é pressionado
        spriteY -=50;
        println("vivo");
      }
    }
}
}


void keyPressed() {
  if (key == ' ' && !gameOver) {
    spriteY -= 50;
  } else if (key == 'r' || key == 'R') {
    restart();
  }
}
