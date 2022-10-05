//link:  https://editor.p5js.org/mairabrito/sketches/wI5oxlBW9S
var Bola1, Bola2, Bola3;

function setup() {
  createCanvas(720, 400);
  noStroke();
  frameRate(30);
  ellipseMode(RADIUS);

  xpos = width / 2;
  ypos = height / 2;
  
  Bola1 = new bola(xpos, ypos,60, 'pink');
  Bola2 = new bola(xpos, ypos,30, 'blue');
  Bola3 = new bola(xpos, ypos,40, 'yellow');
  
}

function draw() {
  background(102);
  Bola1.desenhar();
  Bola1.movimentar();
  Bola1.checarParedes();
  
  Bola2.desenhar();
  Bola2.movimentar();
  Bola2.checarParedes();
  
  Bola3.desenhar();
  Bola3.movimentar();
  Bola3.checarParedes();

}

class bola {
  constructor(posX, posY, rad, cor) {
    this.rad = rad;
    this.x = posX;
    this.y = posY;
    this.dirX = 1;
    this.dirY = 1;
    this.xspeed = 2.8;
    this.yspeed = 2.2;
    this.cor = cor;
  }
  movimentar(){
    this.x = this.x + this.xspeed * this.dirX;
    this.y = this.y + this.yspeed * this.dirY;  
  }
  
  checarParedes(){
    if (this.x > width - this.rad || this.x < this.rad) {
    this.dirX *= -1;
    }
    if (this.y > height - this.rad || this.y < this.rad) {
    this.dirY *= -1;
    }
  }
  
  desenhar(){
    fill(this.cor);
    ellipse(this.x, this.y, this.rad, this.rad);
  }
}