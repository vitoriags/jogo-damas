#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"     // Para Ponto e matCoord
#include "animation.hpp" // Para acessar animacao

// Tamanho do tabuleiro e matriz com as peças
extern matCoord matC[8][4];

// Coordenadas de controle para movimentação e captura
extern int cdXesq, cdYdir, cdXdir, cdYesq;
extern int mudaID;

// Funções de manipulação do tabuleiro
void coord(int y, int x, int z);
void atualizaMatC();
void validaComerEsq();
void validaDestino();
void destino();

#endif
