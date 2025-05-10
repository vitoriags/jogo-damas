#include "types.hpp"

GLUquadric* quad = gluNewQuadric();

// Definições reais
Ponto selecao{ -30, -40, 10.0 };
Ponto esquerda, direita, comeEsquerda, comeDireita;

int idPlay = 0, idPecaEsquerda = 0, idPecaDireita = 0, mudaID = 0, Moviment = 0;

bool trocaPlay = true;
bool podeComerEsq = false;
bool podeComerDir = false;
bool selecionado = false;

int qtdBranca = 12;
int qtdPreta = 12;

double rotate_x = 0, rotate_y = 0, cameraT_z = 0;

matCoord matC[8][4];

int cdXesq = 0, cdXdir = 0, cdYesq = 0, cdYdir = 0;
