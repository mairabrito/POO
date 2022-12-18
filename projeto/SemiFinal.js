import { Fase } from "./Fase.js"
import { Jogo } from "./Jogo.js"

export class SemiFinal extends Fase {
    constructor(times, fase, nPartidas) {
        super(times, fase, nPartidas);
        this.jogo = []
        this.aux = 0;
        this.disputar_1Lugar = [];
        this.disputar_3Lugar = [];
    }

    iniciarJogos(){
        for (let i =0; i<this.nPartidas; i++){
            this.jogo.push(new Jogo(i, this.times[this.aux], this.times[this.aux+1]))
            this.aux = this.aux+2;
        }
        for (let i =0; i<this.nPartidas; i++){
            this.jogo[i].iniciarJogo();
        }
    }

    getresultado() {

        super.getresultado();
        
        let resultados = []
        let n = 1;

        this.jogo.forEach((ganhadores) => {
            console.log(`${n}º Partida: ${ganhadores.time_A.nome} vs ${ganhadores.time_B.nome}`);
            console.log(`   Vencedor: ${ganhadores.time_venceu.nome}`);
            resultados.push(ganhadores.time_venceu);
            this.disputar_1Lugar.push(ganhadores.time_venceu);
            this.disputar_3Lugar.push(ganhadores.time_perdeu);
            n++;
        })
        console.log('');
        resultados.push(this.disputar_3Lugar[0]);
        resultados.push(this.disputar_3Lugar[1]);
        
        return resultados;
    }
}