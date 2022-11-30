class Car {

    constructor(cColor, x, y) {
        this.color = cColor;
        this.doors = 4;
        this.isConvertible = false;
        this.x = x;
        this.y = y;
        this.speed = 0;
    }

    start(speed) {
        this.speed = speed;
    }

    display() {
        fill(this.color);
        rect(this.x, this.y, 40, 30);
    }

    move() {
        this.x += this.speed;

        if (this.x < -20) {
            this.x = width;
        } else if (this.x > width) {
            this.x = -20;
        }
    }
}

class Carferrari extends Car { //Classe derivada de Car
    constructor(cor, x, y) {
        super(cor, x, y); //construtor da classe base
    }

    display() { // método reescrito
        fill('#F3F302');
        ellipse(this.x + 1, this.y + 5, 6);
        ellipse(this.x + 1, this.y + 25, 6);
        fill('#3B3838');
        rect(this.x + 2, this.y - 2, 6);
        rect(this.x + 2, this.y + 26, 6);
        rect(this.x + 30, this.y - 2, 6);
        rect(this.x + 30, this.y + 26, 6);


        super.display(); // display da classe base

        fill('#F9A8A8');
        rect(this.x + 10, this.y + 6, 8);
        rect(this.x + 10, this.y + 16, 8);
        fill('black');
        rect(this.x + 30, this.y + 2, 1, 26); rect(this.x + 25, this.y + 2, 1, 26);
        rect(this.x + 35, this.y + 2, 1, 26);
    }
}

class CarVolvo extends Car { //Classe derivada de Car
    constructor(cor, x, y) {
        super(cor, x, y); //construtor da classe base
    }

    display() { // Método reescrito
        fill('red');
        ellipse(this.x + 1, this.y + 5, 6);
        ellipse(this.x + 1, this.y + 25, 6);
        fill('#FFD119');
        ellipse(this.x + 39, this.y + 5, 6);
        ellipse(this.x + 39, this.y + 25, 6);
        fill('black');
        ellipse(this.x + 8, this.y + 1, 8);
        ellipse(this.x + 30, this.y + 1, 8);
        ellipse(this.x + 8, this.y + 29, 8);
        ellipse(this.x + 30, this.y + 29, 8);

        super.display(); // display da classe base

        fill('#A9C3C2')
        rect(this.x + 8, this.y + 5, 10, 20)
        fill('black')
        rect(this.x + 20, this.y + 7, 17, 16)
    }
}

let rav4;
let ferrari;
let volvo;

function setup() {
    createCanvas(400, 400);

    rav4 = new Car("silver", 100, 300);
    ferrari = new Carferrari("red", 0, 235);
    volvo = new CarVolvo("blue", 200, 80);
    rav4.doors = 2;

    console.log("rav4", rav4);
    console.log("charger", ferrari);
    console.log("nova", volvo);

    rav4.start(2);
    ferrari.start(-4);
    volvo.start(-4);
}

function draw() {
    //cenário
    background("beige");
    for (let i = -10; i < 400; i++) {
        i += 15;
        rect(i, 125, 6, 4);
        rect(i, 280, 6, 4);
    }
    rect(0, 200, 400, 8);
    fill('#096B15');
    rect(0, 0, 400, 50);
    fill('#6A6F6B');
    rect(0, 50, 400, 4);
    fill('#096B15');
    rect(0, 350, 400, 50);
    fill('#6A6F6B');
    rect(0, 350, 400, 4);

    //métodos display e move
    rav4.display();
    ferrari.display();
    volvo.display();

    rav4.move();
    ferrari.move();
    volvo.move();
}


/**
 * Acrescentei mais duas classes derivadas da classe base Car e reescrevi o método display.
 */