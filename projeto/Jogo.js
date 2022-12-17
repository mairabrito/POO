export class Jogo {
    constructor(id, time_A, time_B) {
        this.id = id;
        this.time_A = time_A;
        this.time_B = time_B;
        this.pontos_A = 0;
        this.pontos_B = 0;
        this.time_venceu;
        this.time_perdeu;
    }

    iniciarJogo() {
        //Resultado aleatorio 
        this.pontos_A = Math.floor(Math.random() * (5 - 1 + 1)) + 1;
        this.pontos_B = Math.floor(Math.random() * (5 - 1 + 1)) + 1;
        

        if (this.pontos_A > this.pontos_B) {
            this.time_A.setVetorias();
            this.time_A.pontos += 3;
            this.time_A.status='Classificado';
            this.time_venceu = this.time_A;
            this.time_A.n_gols = this.pontos_A;
            this.time_A.saldo_gols = (this.pontos_A - this.pontos_B);

            this.time_B.setDerrotas();
            this.time_B.status = 'Eliminado';
            this.time_perdeu = this.time_B;
            this.time_B.n_gols = this.pontos_B;
            this.time_B.saldo_gols = (this.pontos_B - this.pontos_A);
        } else if (this.pontos_A < this.pontos_B) {
            this.time_B.setVetorias();
            this.time_B.pontos += 3;
            this.time_B.status='Classificado';
            this.time_venceu = this.time_B;
            this.time_B.n_gols = this.pontos_B;
            this.time_B.saldo_gols = (this.pontos_B - this.pontos_A);

            this.time_A.setDerrotas();
            this.time_A.status = 'Eliminado';
            this.time_perdeu = this.time_A;
            this.time_A.n_gols = this.pontos_A;
            this.time_A.saldo_gols = (this.pontos_A - this.pontos_B);
        } else {
            this.iniciarJogo();
        }
    }
}