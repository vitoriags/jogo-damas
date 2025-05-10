#include "pieces.hpp"
#include "board.hpp"
#include "types.hpp"
#include <GL/glut.h>
#include <GL/glu.h>

// Sons desativados no momento, mas você pode usar SDL_Mixer no futuro
void pulaYpula() {
    // // set volume
    // Mix_VolumeMusic(100);
    // // open audio file
    // Mix_Music* music = Mix_LoadMUS("Checkerssoundfx.mp3");
    // Mix_PlayMusic(music, 1);
}

void comeYcome() {
    // // set volume
    // Mix_VolumeMusic(100);
    // // open audio file
    // Mix_Music* music = Mix_LoadMUS("Checkerssoundfx2.mp3");
    // Mix_PlayMusic(music, 1);
}

void Vitoria() {
    // // set volume
    // Mix_VolumeMusic(50);
    // // open audio file
    // Mix_Music* music = Mix_LoadMUS("You_Win.mp3");
    // Mix_PlayMusic(music, 1);
}

void drawPieces() {
    // drawing pieces
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 4; x++) {

            if (matC[y][x].id == 1) {
                glColor3f(1.0f, 1.0f, 1.0f);
                glPushMatrix();
                glRotatef(-90, 1.0, 0, 0);
                glTranslatef(matC[y][x].posicao.x, matC[y][x].posicao.y, matC[y][x].posicao.z);
                gluCylinder(quad, 4.0, 4.0, 2.0, 100, 100);
                glTranslatef(0, 0, 2.0);
                gluDisk(quad, 0, 4.0, 60, 8);
                glPopMatrix();
            }
            else if (matC[y][x].id == 2) {
                glColor3f(0.4f, 0.4f, 0.4f);
                glPushMatrix();
                glRotatef(-90, 1.0, 0, 0);
                glTranslatef(matC[y][x].posicao.x, matC[y][x].posicao.y, matC[y][x].posicao.z);
                gluCylinder(quad, 4.0, 4.0, 2.0, 100, 100);
                glTranslatef(0, 0, 2.0f);
                gluDisk(quad, 0, 4.0, 60, 8);
                glPopMatrix();
            }
        }
    }
}