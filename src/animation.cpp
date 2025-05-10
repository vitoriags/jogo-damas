#include "animation.hpp"
#include <cmath> // para sin()

Animacao animacao;

Ponto Mover(Ponto inicio, Ponto fim, float tInicio, float tAtual, float duracao) {
    Ponto resultado;
    float t = (tAtual - tInicio) / duracao;
    resultado.x = (fim.x - inicio.x) * t + inicio.x;
    resultado.y = (fim.y - inicio.y) * t + inicio.y;
    resultado.z = 10 * sin(3.14 * t) + (fim.z - inicio.z) * t + inicio.z;
    return resultado;
}
