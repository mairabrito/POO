import { Jogador } from "./Jogador.js"

export class Defesa extends Jogador {
    constructor(nome, idade, ncamisa, desarme) {
        super(nome, idade, ncamisa);
        this.desarme = desarme;
    }

    infoJogador(){
        super.infoJogador('Posição: Defesa');
    }
}