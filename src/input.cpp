#include "input.hpp"
#include "board.hpp"
#include "animation.hpp"
#include "pieces.hpp"
#include "types.hpp"
#include <GL/glut.h>


void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 27) exit(0);
    else if (key == 's') cameraT_z -= 3;
    else if (key == 'w') cameraT_z += 3;
    else if (key == 'a') rotate_x += 3;
    else if (key == 'd') rotate_y -= 3;

    else if (key == 32) {
        for (int y = 7; y >= 0; y--) {
            for (int x = 0; x < 8; x++) {
                if (matC[y][x].posicao.x == selecao.x && matC[y][x].posicao.y == selecao.y) {
                    idPlay = matC[y][x].id;
                    if ((trocaPlay && idPlay == 1) || (!trocaPlay && idPlay == 2)) {
                        selecionado = true;
                        destino();
                    }
                }
            }
        }
    }
    else if (!podeComerEsq && !podeComerDir) {
        esquerda.z = 5.0;
        direita.z = 5.0;
        selecionado = false;

        if (key == '9' && selecao.x < 30 && selecao.y < 30) {
            selecao.x += 10.0; selecao.y += 10.0;
        } else if (key == '1' && selecao.x > -40.0 && selecao.y > -40) {
            selecao.x -= 10.0; selecao.y -= 10.0;
        } else if (key == '3' && selecao.x < 40.0 && selecao.y > -40) {
            selecao.x += 10.0; selecao.y -= 10.0;
        } else if (key == '7' && selecao.x > -40.0 && selecao.y < 30) {
            selecao.x -= 10.0; selecao.y += 10.0;
        }
    }
}

void processSpecialKeys(int key, int x, int y) {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    if (animacao.rodando == 0 && selecionado) {
        if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) {
            bool esquerdaSelecionada = esquerda.z >= 5.09 && esquerda.z <= 5.19;
            bool direitaSelecionada = direita.z >= 5.09 && direita.z <= 5.19;

            Ponto destino = (key == GLUT_KEY_LEFT) ? esquerda : direita;
            int cdX = (key == GLUT_KEY_LEFT) ? cdXesq : cdXdir;
            int cdY = (key == GLUT_KEY_LEFT) ? cdYesq : cdYdir;
            bool podeComer = (key == GLUT_KEY_LEFT) ? podeComerEsq : podeComerDir;

            bool direcaoValida =
                (key == GLUT_KEY_LEFT && esquerdaSelecionada) ||
                (key == GLUT_KEY_RIGHT && direitaSelecionada);

            if ((trocaPlay && idPlay == 1 && direcaoValida) || (!trocaPlay && idPlay == 2 && direcaoValida)) {
                bool comerValido = podeComer &&
                    matC[cdY][cdX].posicao.x == selecao.x + (key == GLUT_KEY_LEFT ? -10 : +10) &&
                    matC[cdY][cdX].posicao.y == selecao.y + (trocaPlay ? +10 : -10);

                if (comerValido) {
                    int idAlvo = matC[cdY][cdX].id;
                    (idAlvo == 2) ? qtdPreta-- : qtdBranca--;
                    matC[cdY][cdX].id = 0;
                    (qtdPreta == 0 || qtdBranca == 0) ? Vitoria() : comeYcome();
                } else {
                    pulaYpula();
                }

                animacao.inicio = selecao;
                animacao.fim = { destino.x, destino.y, 10.0 };
                animacao.tInicio = t;
                animacao.duracao = 0.5;
                animacao.rodando = 1;

                esquerda.z = 5.0;
                direita.z = 5.0;
                selecionado = false;
                podeComerEsq = podeComerDir = false;
                trocaPlay = !trocaPlay;
                atualizaMatC();
            }
        }
    }
    glutPostRedisplay();
}
