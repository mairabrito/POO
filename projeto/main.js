import { Time } from "./Time.js"
import { Jogo } from "./Jogo.js"
import { QuartasDeFinal } from "./QuartasDeFinal.js"
import { SemiFinal } from "./SemiFinal.js"
import { OitavasDeFinal } from "./OitavasDeFinal.js";
import { Jogador } from "./Jogador.js"
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
const Times = [Brasil,Argentina,Holanda,EUA,Australia,Japão,Croacia,Espanha,CoreiaDoSul,Franca,Polonia,Inglaterra,Senegal,Marrocos,Portugal,Suica]

//Incrementando Jogadores no Brasil e na Argentina
const jogadoresBrasil = []
const jogadoresArgentina = []
//Aleatório 
for(let i=0; i<11; i++){
    jogadoresBrasil[i] = new Jogador(getNomeAleatorio(), 18+i, i+1);
    jogadoresArgentina[i] = new Jogador(getNomeAleatorio(), 18+i, i+1);
}
//Manual
Brasil.jogadores = jogadoresBrasil;
Brasil.jogadores[9].setNome('Neymar');
Argentina.jogadores = jogadoresArgentina;
Argentina.jogadores[9].setNome('Messi');

// Iniciar os jogos (Oitavas de Final > Quartas de Final > Semi Final > Final)

const _OitavasDeFinal = new OitavasDeFinal(Times, 'Oitavas de Final', 8)
_OitavasDeFinal.iniciarJogos();
const ResultadoOitavas = _OitavasDeFinal.getresultado();

const _QuartasdeFinal = new QuartasDeFinal(ResultadoOitavas, 'Quartas de Final', 4)
_QuartasdeFinal.iniciarJogos();
const ResultadoQuartas = _QuartasdeFinal.getresultado();
/*
const _SemiFinal = new SemiFinal(ResultadoQuartas, 'Semi Final', 2)
_SemiFinal.info();
_SemiFinal.iniciarJogos();
const ResultadoSemi = _SemiFinal.getresultado();

const _Final = new Final(ResultadoSemi, 'Final', 2)
_Final.info();
_Final.iniciarJogos();
const ResultadoFinal = _Final.getresultado(); */




//const ResultadoOitavas= _OitavasDeFinal.getresultado()
//const quatas = new OitavasDeFinal(ResultadoOitavas, 'quartas', 4)
//quatas.info();
//Brasil.info();
//Argentina.info();
//Brasil.getJogadores()







