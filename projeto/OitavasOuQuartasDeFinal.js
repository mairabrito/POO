import { Fase } from "./Fase.js"
import { Jogo } from "./Jogo.js"

export class OitavasOuQuartasDeFinal extends Fase {
    constructor(times, fase, nPartidas) {
        super(times, fase, nPartidas); //usando o construtor da classe base
        this.jogo = []
        this.aux = 0;
    }

    iniciarJogos(){
        for (let i =0; i<this.nPartidas; i++){ // criar os objetos do tipo Jogo passando dois times e armazenar em um array 
            this.jogo.push(new Jogo(i, this.times[this.aux], this.times[this.aux+1]))
            this.aux = this.aux+2;
        }
        for (let i =0; i<this.nPartidas; i++){ // Iniciar os jogos
            this.jogo[i].iniciarJogo();
        }
    }

    getresultado() {

        super.getresultado(); // getresultado da classe base
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