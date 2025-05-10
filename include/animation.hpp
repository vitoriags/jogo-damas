#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "types.hpp" // Para usar o struct Ponto

// Struct de animação usada no jogo
struct Animacao {
    int rodando = 0;
    Ponto inicio, fim;
    float tInicio;
    float duracao;
};

// Função que calcula a posição da peça durante a animação
Ponto Mover(Ponto inicio, Ponto fim, float tInicio, float tAtual, float duracao);

// Variável global que controla a animação atual
extern Animacao animacao;

#endif
