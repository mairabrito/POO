import { Time } from "./Time.js"
import { SemiFinal } from "./SemiFinal.js"
import { OitavasOuQuartasDeFinal } from "./OitavasOuQuartasDeFinal.js";
import { Atacante } from "./Atacante.js"
import { Defesa } from "./Defesa.js"
import { Goleiro } from "./Goleiro.js"
import { getNomeAleatorio } from "./Jogador.js"
import { Final } from "./Final.js"

//Times
const Brasil = new Time('Brasil', 1);
const Argentina = new Time('Argentina', 2);
const Holanda = new Time('Holanda', 3);
const EUA = new Time('EUA', 4);
const Australia = new Time('Austrália', 5);
const Japão = new Time('Japão', 6);
const Croacia = new Time('Croacia', 7);
const Espanha = new Time('Espanha', 8);
const CoreiaDoSul = new Time('CoreiaDoSul', 9);
const Franca = new Time('França', 10);
const Polonia = new Time('Polônia', 11);
const Inglaterra = new Time('Inglaterra', 12);
const Senegal = new Time('Senegal', 13);
const Marrocos = new Time('Marrocos', 14);
const Portugal = new Time('Portugal', 15);
const Suica = new Time('Suiça', 16);

//Array contendo todos os Times
const Times = [Brasil, Argentina, Holanda, EUA, Australia, Japão, Croacia, Espanha, CoreiaDoSul, Franca, Polonia, Inglaterra, Senegal, Marrocos, Portugal, Suica]

//Incrementando Jogadores no Brasil e na Argentina
const jogadoresBrasil = []
const jogadoresArgentina = []
//Aleatório 
for (let i = 0; i < 11; i++) {
    if (i < 2) {
        jogadoresBrasil[i] = new Goleiro(getNomeAleatorio(), 18 + i, i + 1, 75+i);
        jogadoresArgentina[i] = new Goleiro(getNomeAleatorio(), 18 + i, i + 1, 65+i);
    }
    else if (i < 6) {
        jogadoresBrasil[i] = new Atacante(getNomeAleatorio(), 18 + i, i + 1, 55+i);
        jogadoresArgentina[i] = new Atacante(getNomeAleatorio(), 18 + i, i + 1, 65+i);
    }
    else {
        jogadoresBrasil[i] = new Defesa(getNomeAleatorio(), 18 + i, i + 1, 30+i);
        jogadoresArgentina[i] = new Defesa(getNomeAleatorio(), 18 + i, i + 1, 55+i);
    }
}
//Set Manual o nome
Brasil.jogadores = jogadoresBrasil;
Brasil.jogadores[9].setNome('Neymar');
Argentina.jogadores = jogadoresArgentina;
Argentina.jogadores[9].setNome('Messi');

// Iniciar os jogos (Oitavas de Final > Quartas de Final > Semi Final > Final)

const _OitavasDeFinal = new OitavasOuQuartasDeFinal(Times, 'Oitavas de Final', 8)
_OitavasDeFinal.iniciarJogos();
const ResultadoOitavas = _OitavasDeFinal.getresultado();

const _QuartasdeFinal = new OitavasOuQuartasDeFinal(ResultadoOitavas, 'Quartas de Final', 4)
_QuartasdeFinal.iniciarJogos();
const ResultadoQuartas = _QuartasdeFinal.getresultado();

const _SemiFinal = new SemiFinal(ResultadoQuartas, 'Semi Final', 2)
_SemiFinal.iniciarJogos();
const ResultadoSemi = _SemiFinal.getresultado();

const _Final = new Final(ResultadoSemi, 'Final', 2);
_Final.iniciarJogos();
const ResultadoFinal = _Final.getresultado();

// 1º a classe OitavasOuQuartasDeFinal recebe todos os times inicializados (Oitavas)
// 2º a classe OitavasOuQuartasDeFinal recebe o resultado com todos os times que se classificaram na fase anterior (Quartas)
// A classe SemiFinal recebe os times do resultado das Quartas
// A classe Final recebe recebe os times seguindo a ordem do resultado da semiFinal
// A classe Jogo recebe dois times, e aleatoriamente, set os resultados dos dois times


// EXEMPLO DE SAÍDA (RESULTADO ALEATORIO)
/**
 * -----------------------Oitavas de Final----------------------
Número partidas: 8
Times:
   Brasil
   Argentina
   Holanda
   EUA
   Austrália
   Japão
   Croacia
   Espanha
   CoreiaDoSul
   França
   Polônia
   Inglaterra
   Senegal
   Marrocos
   Portugal
   Suiça

1º Partida: Brasil vs Argentina
   Vencedor: Argentina
2º Partida: Holanda vs EUA
   Vencedor: Holanda
3º Partida: Austrália vs Japão
   Vencedor: Japão
4º Partida: Croacia vs Espanha
   Vencedor: Espanha
5º Partida: CoreiaDoSul vs França
   Vencedor: França
6º Partida: Polônia vs Inglaterra
   Vencedor: Inglaterra
7º Partida: Senegal vs Marrocos
   Vencedor: Marrocos
8º Partida: Portugal vs Suiça
   Vencedor: Suiça

-----------------------Quartas de Final----------------------
Número partidas: 4
Times:
   Argentina
   Holanda
   Japão
   Espanha
   França
   Inglaterra
   Marrocos
   Suiça

1º Partida: Argentina vs Holanda
   Vencedor: Argentina
2º Partida: Japão vs Espanha
   Vencedor: Japão
3º Partida: França vs Inglaterra
   Vencedor: França
4º Partida: Marrocos vs Suiça
   Vencedor: Marrocos

-----------------------Semi Final----------------------
Número partidas: 2
Times:
   Argentina
   Japão
   França
   Marrocos

1º Partida: Argentina vs Japão
   Vencedor: Argentina
2º Partida: França vs Marrocos
   Vencedor: Marrocos

-----------------------Final----------------------
Número partidas: 2
Times:
   Argentina
   Marrocos
   Japão
   França

1º Partida: Argentina vs Marrocos
   Vencedor: Argentina
2º Partida: Japão vs França
   Vencedor: França

Resultado Final:

        PRIMEIRO LUGAR: Argentina
        SEGUNDO LUGAR: Marrocos
        TERCEIRO LUGAR: França

        **Dados do vencedor**

        Argentina:
        Vitórias: 4
        Derrotas: 0
        Empates: 0
        
        Gols: 16
        SG: 9
        Pontos: 12
        Colocação: 1º Lugar

        Jogadores:

        nome: TIME - idade: 18 - camisa: 1  - Posição: Posição: Goleiro

        nome: VUGINI - idade: 19 - camisa: 2  - Posição: Posição: Goleiro

        nome: LOBE - idade: 20 - camisa: 3  - Posição: Posição: Atacante

        nome: COTALO - idade: 21 - camisa: 4  - Posição: Posição: Atacante

        nome: PIDUGI - idade: 22 - camisa: 5  - Posição: Posição: Atacante

        nome: CINONO - idade: 23 - camisa: 6  - Posição: Posição: Atacante

        nome: GALUYE - idade: 24 - camisa: 7  - Posição: Posição: Defesa

        nome: TUFU - idade: 25 - camisa: 8  - Posição: Posição: Defesa

        nome: GIXUKU - idade: 26 - camisa: 9  - Posição: Posição: Defesa

        nome: Messi - idade: 27 - camisa: 10  - Posição: Posição: Defesa

        nome: DANI - idade: 28 - camisa: 11  - Posição: Posição: Defesa
 */









