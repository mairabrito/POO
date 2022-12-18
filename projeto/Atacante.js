import { Jogador } from "./Jogador.js"

export class Atacante extends Jogador {
    constructor(nome, idade, ncamisa, velocidade) {
        super(nome, idade, ncamisa);
        this.velocidade = velocidade;
    }

    infoJogador(){
        super.infoJogador('Posição: Atacante');
    }
}