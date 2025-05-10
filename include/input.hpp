#ifndef INPUT_HPP
#define INPUT_HPP

#pragma once
#include "types.hpp"

extern Ponto selecao;
extern Ponto esquerda;
extern Ponto direita;
extern Ponto comeEsquerda;
extern Ponto comeDireita;

extern bool trocaPlay;
extern bool podeComerEsq;
extern bool podeComerDir;
extern bool selecionado;

extern int mudaID;
extern int Moviment;
extern int idPecaEsquerda;
extern int idPecaDireita;
extern int idPlay;

extern int qtdBranca;
extern int qtdPreta;

extern double rotate_x, rotate_y, cameraT_z;

void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void CameraMove(int x, int y);

#endif
