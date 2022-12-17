export class Jogador {
    constructor(nome, idade, ncamisa) {
        this.nome = nome;
        this.idade = idade;
        this.ncamisa = ncamisa;
    }

    setNome(novo_nome) { this.nome = novo_nome; }
    setNumero(novo_numero) { this.ncamisa = novo_numero; }
    setIdade(nova_idade) { this.idade = nova_idade; }

    infoJogador() {
        console.log(`Jogador:
        nome: ${this.nome}
        idade: ${this.idade}
        camisa: ${this.ncamisa}`)
    }
}


// Função para gerar nomes aleatórios
export function getNomeAleatorio() {

    let quantidadeDeSilabas = getRandomIntInclusive(2, 3);
    let nome = "";

    for (let contadorSilaba = 1; contadorSilaba <= quantidadeDeSilabas; contadorSilaba++) { nome = nome + getConsoanteAleatoria() + getVogalAleatoria(); }
    return nome;
}

function getRandomIntInclusive(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getVogalAleatoria() {

    let listaVogais = "AEOIU";
    let numeroAleatorio = getRandomIntInclusive(1, 5);

    return listaVogais.substring(numeroAleatorio - 1, numeroAleatorio);
}

function getConsoanteAleatoria() {

    let listaConsoantes = "BCDFGHJKLMNPQRSTWVXYZ";
    let numeroAleatorio = getRandomIntInclusive(1, 21);

    return listaConsoantes.substring(numeroAleatorio - 1, numeroAleatorio);
}
