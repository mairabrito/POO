export class Fase {
    constructor(times, fase, nPartidas) {
        this.times = times;
        this.nPartidas = Number(nPartidas);
        this.fase = fase;
    }

    getresultado() {
        let i = 1;
        console.log(`-----------------------${this.fase}----------------------`);
        console.log(`Número partidas: ${this.nPartidas}`);
        console.log('Times:');
        for (let i = 0; i < this.times.length; i++) {
            console.log(`   ${this.times[i].nome}`);
        }
        console.log('');
    }
}