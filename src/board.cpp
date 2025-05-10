#include "board.hpp"
#include "input.hpp"

void coord(int y, int x, int z) {
    for (int l = 7; l >= 0; l--) {
        for (int c = 0; c < 4; c++) {
            matC[l][c].posicao = { (float)x, (float)y, 10.0f };
            if (l > 4) matC[l][c].id = 1;
            else if (l < 3) matC[l][c].id = 2;
            else matC[l][c].id = 0;
            x += 20;
        }
        x = (l % 2 == 1) ? -40 : -30;
        y += 10;
    }
}

void atualizaMatC(void) { // updating coordinate matrix

    if (trocaPlay) { // white pieces
        for (int y = 7; y >= 0; y--) {
            for (int x = 0; x < 4; x++) {
                if (matC[y][x].posicao.x == animacao.inicio.x && matC[y][x].posicao.y == animacao.inicio.y) {
                    if (animacao.rodando == 1) {
                        mudaID = matC[y][x].id;
                        matC[y][x].id = 0;
                    }
                }
                if (matC[y][x].posicao.x == animacao.fim.x && matC[y][x].posicao.y == animacao.fim.y) { // printando matriz de coordenadas após atualização. 
                    if (animacao.rodando == 0) {
                        matC[y][x].id = mudaID;
                    }
                }
            }
        }
    }
    else { // black pieces
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 4; x++) {
                if (matC[y][x].posicao.x == animacao.inicio.x && matC[y][x].posicao.y == animacao.inicio.y) {
                    if (animacao.rodando == 1) {
                        mudaID = matC[y][x].id;
                        matC[y][x].id = 0;
                    }
                }
                if (matC[y][x].posicao.x == animacao.fim.x && matC[y][x].posicao.y == animacao.fim.y) { // printando matriz de coordenadas após atualização.
                    if (animacao.rodando == 0) {
                        matC[y][x].id = mudaID;
                    }
                }
            }
        }
    }

}

void validaComerEsq(void) {
    if (trocaPlay) {
        for (int l = 7; l >= 0; l--) {
            for (int c = 0; c < 4; c++) {
                if (matC[l][c].posicao.x == esquerda.x - 10.0 && matC[l][c].posicao.y == esquerda.y + 10.0 && matC[l][c].id == 0) {
                    podeComerEsq = true;
                    idPecaEsquerda = 3;
                    comeEsquerda = { esquerda.x - 10, esquerda.y + 10, 5.1 };
                    esquerda = comeEsquerda;
                    direita.z = 5.0;
                    return;
                }
                else if (idPecaEsquerda != 3)
                    esquerda.z = 5.0;
            }
        }
    }
    else {
        for (int l = 7; l >= 0; l--) {
            for (int c = 0; c < 4; c++) {
                if (matC[l][c].posicao.x == esquerda.x - 10.0 && matC[l][c].posicao.y == esquerda.y - 10.0 && matC[l][c].id == 0) {
                    podeComerEsq = true;
                    idPecaEsquerda = 0;
                    comeEsquerda = { esquerda.x - 10, esquerda.y - 10, 5.1 };
                    esquerda = comeEsquerda;
                    direita.z = 5.0;
                    return;
                }
                else if (idPecaEsquerda != 0)
                    esquerda.z = 5.0;

            }
        }
    }
}

void validaDestino(void) { // creating the possible moves
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 4; x++) {

            if (trocaPlay) { // white pieces
                if (matC[y][x].posicao.x == esquerda.x && matC[y][x].posicao.y == esquerda.y) {
                    idPecaEsquerda = matC[y][x].id;
                    if (idPecaEsquerda == 1) {
                        esquerda.z = 5.0;
                    }
                    else if (idPecaEsquerda == 2) {
                        cdXesq = x;
                        cdYesq = y;
                        validaComerEsq();
                    }
                }
                if (matC[y][x].posicao.x == direita.x && matC[y][x].posicao.y == direita.y) {
                    idPecaDireita = matC[y][x].id;
                    if (idPecaDireita == 1) {
                        direita.z = 5.0;
                    }
                    else if (idPecaDireita == 2) {
                        cdXdir = x;
                        cdYdir = y;
                        for (int l = 7; l >= 0; l--) {
                            for (int c = 0; c < 4; c++) {
                                if (matC[l][c].posicao.x == direita.x + 10 && matC[l][c].posicao.y == direita.y + 10 && matC[l][c].id == 0) {
                                    podeComerDir = true;
                                    idPecaDireita = 3;
                                    comeDireita = { direita.x + 10, direita.y + 10, 5.1 };
                                    direita = comeDireita;
                                    if (not podeComerEsq)
                                        esquerda.z = 5.0;
                                    else
                                        direita.z = 5.1;
                                    return;
                                }
                                else if (idPecaDireita != 3)
                                    direita.z = 5.0;
                            }
                        }
                    }
                }
            }
            else { // black pieces
                if (matC[y][x].posicao.x == esquerda.x && matC[y][x].posicao.y == esquerda.y) {
                    idPecaEsquerda = matC[y][x].id;
                    if (idPecaEsquerda == 2) {
                        esquerda.z = 5.0;
                    }
                    else if (idPecaEsquerda == 1) {
                        cdXesq = x;
                        cdYesq = y;
                        validaComerEsq();
                    }

                }
                if (matC[y][x].posicao.x == direita.x && matC[y][x].posicao.y == direita.y) {
                    idPecaDireita = matC[y][x].id;
                    if (idPecaDireita == 2) {
                        direita.z = 5.0;
                    }
                    else if (idPecaDireita == 1) {
                        cdXdir = x;
                        cdYdir = y;
                        for (int l = 7; l >= 0; l--) {
                            for (int c = 0; c < 4; c++) {
                                if (matC[l][c].posicao.x == direita.x + 10.0 && matC[l][c].posicao.y == direita.y - 10.0 && matC[l][c].id == 0) {
                                    podeComerDir = true;
                                    idPecaDireita = 0;
                                    comeDireita = { direita.x + 10, direita.y - 10, 5.1 };
                                    direita = comeDireita;
                                    if (not podeComerEsq)
                                        esquerda.z = 5.0;
                                    else
                                        direita.z = 5.1;
                                    return;
                                }
                                else if (idPecaDireita != 0)
                                    direita.z = 5.0;
                            }
                        }
                    }
                }

            }
        }
    }

}

void destino(void) { // verificação da dimensão do tabuleiro (limites)

    if (trocaPlay) { // white pieces
        if (selecao.x == -40) {
            esquerda = { selecao.x, selecao.y, 5.1 };
            direita = { selecao.x + 10 , selecao.y + 10, 5.1 };
            validaDestino();
        }
        else if (selecao.x == 30) {
            esquerda = { selecao.x - 10, selecao.y + 10, 5.1 };
            direita = { selecao.x  , selecao.y , 6.0 };
            validaDestino();
        }
        else {
            esquerda = { selecao.x - 10, selecao.y + 10, 5.1 };
            direita = { selecao.x + 10 , selecao.y + 10, 5.1 };
            validaDestino();
        }
    }
    else { // black pieces
        if (selecao.x == -40) {
            esquerda = { selecao.x , selecao.y , 5.1 };
            direita = { selecao.x + 10 , selecao.y - 10, 5.1 };
            validaDestino();
        }
        else if (selecao.x == 30) {
            esquerda = { selecao.x - 10, selecao.y - 10, 5.1 };
            direita = { selecao.x  , selecao.y , 6.0 };
            validaDestino();
        }
        else {
            esquerda = { selecao.x - 10, selecao.y - 10, 5.1 };
            direita = { selecao.x + 10 , selecao.y - 10, 5.1 };
            validaDestino();
        }
    }

}


