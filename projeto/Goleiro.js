import { Jogador } from "./Jogador.js"

export class Goleiro extends Jogador {
    constructor(nome, idade, ncamisa, altura, reflexos) {
        super(nome, idade, ncamisa);
        this.altura = altura;
        this.reflexos = reflexos
    }

    infoJogador(){
        super.infoJogador('Posição: Goleiro');
    }
}