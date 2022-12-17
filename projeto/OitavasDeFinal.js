import { Fase } from "./Fase.js"
import { Jogo } from "./Jogo.js"

export class OitavasDeFinal extends Fase {
    constructor(times, fase, nPartidas) {
        super(times, fase, nPartidas); //usando o construtor da classe herdada
        this.jogo = []
        this.k = 0;
    }

    iniciarJogos(){
        for (let i =0; i<this.nPartidas; i++){
            this.jogo.push(new Jogo(i, this.times[this.k], this.times[this.k+1]))
            this.k = this.k+2;
        }
        for (let i =0; i<this.nPartidas; i++){
            this.jogo[i].iniciarJogo();
        }
    }

    getresultado() {

        super.getresultado(); // usando a função 
        let resultados = []
        let n = 1;

        this.jogo.forEach((ganhadores) => {
            console.log(`${n}º Partida: ${ganhadores.time_A.nome} vs ${ganhadores.time_B.nome}`);
            console.log(`   Vencedor: ${ganhadores.time_venceu.nome}`);
            resultados.push(ganhadores.time_venceu);
            n++;
        })
        console.log('');
        return resultados;
    }
}