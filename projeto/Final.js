import { Fase } from "./Fase.js"
import { Jogo } from "./Jogo.js"

export class Final extends Fase {
    constructor(times, fase, nPartidas) {
        super(times, fase, nPartidas);
        this.jogo = []
        this.k = 0;
        this.ganhou = []
        this.perdeu = []
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

        super.getresultado();

        let resultados = []
        let n = 1;

        this.jogo.forEach((ganhadores) => {
            console.log(`${n}º Partida: ${ganhadores.time_A.nome} vs ${ganhadores.time_B.nome}`);
            console.log(`   Vencedor: ${ganhadores.time_venceu.nome}`);
            this.ganhou.push(ganhadores.time_venceu);
            this.perdeu.push(ganhadores.time_perdeu);
            n++;
        })
        console.log('');

        resultados.push(this.ganhou[0]); //1º lugar
        resultados.push(this.perdeu[0]); //2º lugar
        resultados.push(this.ganhou[1]); //3º lugar

        this.ganhou[0].status = "1º Lugar";
        this.perdeu[0].status = "2º Lugar"
        this.ganhou[1].status = "3º Lugar";

        console.log('Resultado Final:')
        console.log(`
        PRIMEIRO LUGAR: ${this.ganhou[0].nome}
        SEGUNDO LUGAR: ${this.perdeu[0].nome}
        TERCEIRO LUGAR: ${this.ganhou[1].nome}`)

        console.log(`
        **Dados do vencedor**`)
        this.ganhou[0].info();
        return resultados;
    }


}