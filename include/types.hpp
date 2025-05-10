#ifndef TYPES_HPP
#define TYPES_HPP

#include <GL/glu.h> // Necessário para GLUquadric

extern GLUquadric* quad;

struct Ponto {
    float x, y, z;
};

struct matCoord {
    Ponto posicao;
    int id;
};

// Declarações globais
extern Ponto selecao;
extern Ponto esquerda, direita, comeEsquerda, comeDireita;
extern int idPlay, idPecaEsquerda, idPecaDireita, mudaID, Moviment;
extern bool trocaPlay, podeComerEsq, podeComerDir, selecionado;
extern int qtdBranca, qtdPreta;
extern double rotate_x, rotate_y, cameraT_z;
extern matCoord matC[8][4];
extern int cdXesq, cdXdir, cdYesq, cdYdir;

#endif
