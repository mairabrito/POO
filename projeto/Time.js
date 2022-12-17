export class Time {
    constructor(nome, id_time) {
        this.nome = nome;
        this.id_time = id_time;
        this.status = 'indefinido';
        this.jogadores = [];
        this.derrotas = 0;
        this.vitorias = 0;
        this.empates = 0;
        this.pontos = 0;
        this.n_gols = 0;
        this.saldo_gols = 0;
    }
    getNome() {
        console.log(`Time: ${this.nome}`)
    }
    getJogadores() {
        this.jogadores.forEach((jogador) => {
            console.log(jogador.nome)
        })
    }
    setVetorias() {
        this.vitorias++;
    }
    setDerrotas() {
        this.derrotas++;
    }
    setEmpates() {
        this.empates++;
    }

    info() {
        console.log(`${this.nome}:
        Vitórias: ${this.vitorias}
        Derrotas: ${this.derrotas}
        Empates: ${this.empates}
        
        Gols: ${this.n_gols}
        SG: ${this.saldo_gols}
        Pontos: ${this.pontos}
        Resultado Final: ${this.status}

        Jogadores:`)

        this.jogadores.forEach((jogador, i) => {
            console.log(`          - ${jogador.nome}  - Camisa: ${jogador.ncamisa}`)
        })
    }
}