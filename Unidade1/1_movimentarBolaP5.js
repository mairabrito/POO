//Link: https://editor.p5js.org/mairabrito/sketches/Kz7gLPT35

let dirX = 1; 
let dirY = 1
let xspeed = 4.8; 
let yspeed = 4.2; 

function setup() {
  createCanvas(400, 400);
  
  createCanvas(720, 400);
  noStroke();
  frameRate(30);
  ellipseMode(RADIUS);

  xpos = width / 2;
  ypos = height / 2;
  rad = 45;
  cor =  'pink';
}

function desenharComponentes(){
    fill(cor);
    ellipse(xpos, ypos, rad, rad);
}

function movimentarComponentes(){

  xpos = xpos + xspeed * dirX;
  ypos = ypos + yspeed * dirY;
  

}
function checarParedes(){
    if (xpos > width - rad || xpos < rad) {
    dirX *= -1;
    }
    if (ypos > height - rad || ypos < rad) {
    dirY *= -1;
    }
}


function draw() {
  background(100,20,40);
  desenharComponentes();
  movimentarComponentes();
  checarParedes();
}