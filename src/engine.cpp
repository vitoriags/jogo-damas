#include "engine.hpp"
#include "board.hpp"
#include "pieces.hpp"
#include "animation.hpp"
#include "input.hpp"

#include <GL/glut.h>
#include <cmath>

#include "types.hpp"

void renderScene() {
    bool flag = true;

    // Limpar buffers de cor e profundidade 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.5, 1.0, 0.0);

    // Reinicia as transformações 
    glLoadIdentity();

    // Defina a câmera 
    gluLookAt(0.0f, 0.0f, 300.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    glTranslatef(0.0, 0.0, cameraT_z);

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // calling animation
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    if (animacao.rodando == 1) {
        if (t - animacao.tInicio >= animacao.duracao) {
            selecao = animacao.fim;
            animacao.rodando = 0;
            atualizaMatC();

        }
        else {
            selecao = Mover(animacao.inicio, animacao.fim, animacao.tInicio, t, animacao.duracao);
        }
    }

    // checkerboard base
    for (int y = -4; y < 4; y++) {
        for (int x = -4; x < 4; x++) {
            glColor3f(0.30f, 0.10f, 0.10f);
            glPushMatrix();
            glRotatef(-90, 1.0, 0, 0);
            glTranslatef(10.0 * x, 10.0 * y, 0.0f);
            glutSolidCube(15.0);
            glPopMatrix();

            // checkerboard
            if (flag) {
                glColor3f(1.0f, 1.0f, 1.0f);
                flag = false;
            }
            else {
                glColor3f(0.0f, 0.0f, 0.0f);
                flag = true;

            }
            glPushMatrix();
            glRotatef(-90, 1.0, 0, 0);
            glTranslatef(10.0 * x, 10.0 * y, 5.0f);
            glutSolidCube(10.0f);
            glPopMatrix();
        }

        if (flag)
            flag = false;
        else
            flag = true;
    }

    if (selecionado)
        glColor3f(0.0f, cos(5 * t), 0.80f);
    else
        glColor3f(1.0f, 0.80f, 0.85f);

    glPushMatrix();
    glRotatef(-90, 1.0, 0, 0);
    glTranslatef(selecao.x, selecao.y, selecao.z);
    gluCylinder(quad, 4.1, 4.1, 2.1, 100, 100);
    glTranslatef(0, 0, 2.1);
    gluDisk(quad, 0, 4.1, 60, 8);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1.0, 0, 0);
    glTranslatef(esquerda.x, esquerda.y, esquerda.z);
    glutSolidCube(10.0f);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1.0, 0, 0);
    glTranslatef(direita.x, direita.y, direita.z);
    glutSolidCube(10.0f);
    glPopMatrix();

    drawPieces();

    // cup
    glColor3f(0.5f, 0.5f, 1.0f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(80.0, 15.0, -9.0);
    gluCylinder(quad, 6.0, 8.0, 18, 60, 80);
    glPopMatrix();

    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(80.0, 15.0, 9.0);
    gluDisk(quad, 0, 8.0, 60, 8);
    glPopMatrix();

    glColor3f(1.5f, 0.85f, 0.80f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(80.0, 15.0, 3.0);
    gluCylinder(quad, 8.1, 8.1, 5, 60, 80);
    glPopMatrix();

    // drink straw
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(80.0, 15.0, -9.0);
    gluCylinder(quad, 1.0, 1.0, 25, 60, 80);
    glPopMatrix();

    // donut
    glColor3f(1.5f, 0.85f, 0.80f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(70.0, -5.0, -5.0);
    glutSolidTorus(4.0, 6.0, 60, 60);
    glPopMatrix();

    glColor3f(0.30f, 0.1f, 0.1f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(70.0, -5.0, -5.1);
    glutSolidTorus(4.0, 6.0, 60, 60);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 1.0f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(70.0, -5.0, -9.0);
    gluDisk(quad, 0, 15.0, 60, 8);
    glPopMatrix();

    // table
    glColor3f(0.30f, 0.1f, 0.1f);
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -18.0);
    gluCylinder(quad, 100.0, 100.0, 7, 60, 80);
    glPopMatrix();

    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -12.0);
    gluDisk(quad, 0, 100.0, 60, 8);
    glPopMatrix();

    int w = 1.0, x = 1, y = 1, z = 0, cont, ador, aux;
    for (cont = 0; cont < 4; cont++) {
        if (cont == 2)
            glColor3f(1.5f, 0.85f, 0.80f);
        else
            glColor3f(0.21f, 0.10f, 0.21f);

        glPushMatrix();
        glRotated(-90, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -7.0 - w);
        gluDisk(quad, 0, 30.0 + z, 60, 8);
        glPopMatrix();
        w = w + 1.0;
        z = z + 20.0;
    }

    for (int line = -8; line <= 8; line++) {
        for (int column = -8; column <= 8; column++) {
            glColor3f(0.30f, 0.1f, 0.1f);
            glPushMatrix();
            glRotated(-90, 1.0, 0.0, 0.0);
            glTranslatef(8.0 * line, 8.0 * column, -18.0f);
            glutSolidCube(8.0);
            glPopMatrix();
        }
    }

    // table legs
    glColor3f(0.30f, 0.1f, 0.1f);

    for (cont = 0; cont < 2; cont++) {
        aux = 1;
        glPushMatrix();
        glRotated(-90, 1.0, 0.0, 0.0);
        glTranslatef(64.0 * y, 69.0 * aux, -22.0);
        glutSolidSphere(8.0, 60, 60);
        glPopMatrix();

        glPushMatrix();
        glRotated(-90, 1.0, 0.0, 0.0);
        glTranslatef(64.0 * y, 69.0 * aux, -115.0);
        gluCylinder(quad, 5.0, 5.0, 100, 60, 80);
        glPopMatrix();

        for (ador = 0; ador < 2; ador++) {
            y = -1;
            glPushMatrix();
            glRotated(-90, 1.0, 0.0, 0.0);
            glTranslatef(64.0 * x, 69.0 * y, -22.0);
            glutSolidSphere(8.0, 60, 60);
            glPopMatrix();

            glPushMatrix();
            glRotated(-90, 1.0, 0.0, 0.0);
            glTranslatef(64.0 * x, 69.0 * y, -115.0);
            gluCylinder(quad, 5.0, 5.0, 100, 60, 80);
            glPopMatrix();
            x = -1;
        }
    }

    // windows
    glColor3f(1.0f, 0.80f, 0.85f);
    y = 1;
    // right and left
    for (cont = 0; cont < 2; cont++) {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex3f(200.0f * y, -115.0f, -200.0f);     // esquerda baixo
        glVertex3f(170.0f * y, -115.0f, -200.0f);    // direita baixo
        glVertex3f(170.0f * y, 200.0f, -200.0f);    // direita cima
        glVertex3f(200.0f * y, 200.0f, -200.0f);   // esquerda cima
        glEnd();
        glPopMatrix();

        y = 285;
        for (ador = 0; ador < 2; ador++) {
            // windows base
            glPushMatrix();
            glBegin(GL_QUADS);
            glVertex3f(-200.0f, 170.0f - y, -200.0f);    // esquerda baixo
            glVertex3f(200.0f, 170.0f - y, -200.0f);    // direita baixo
            glVertex3f(200.0f, 200.0f - y, -200.0f);    // direita cima
            glVertex3f(-200.0f, 200.0f - y, -200.0f);  // esquerda cima
            glEnd();
            glPopMatrix();
            y = 0;
        }
        y = -1;
    }

    // rght and left walls
    y = 1;
    for (cont = 0; cont < 2; cont++) {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex3f(200.0f * y, -115.0f, 200.0f);      // esquerda baixo
        glVertex3f(200.0f * y, -115.0f, -200.0f);    // direita baixo
        glVertex3f(200.0f * y, 200.0f, -200.0f);    // direita cima
        glVertex3f(200.0f * y, 200.0f, 200.0f);    // esquerda cima
        glEnd();
        glPopMatrix();
        y = -1;
    }

    // back wall
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, -115.0f, -200.0f);    // esquerda baixo
    glVertex3f(100.0f, -115.0f, -200.0f);    // direita baixo
    glVertex3f(100.0f, 200.0f, -200.0f);    // direita cima
    glVertex3f(-100.0f, 200.0f, -200.0f);  // esquerda cima
    glEnd();
    glPopMatrix();

    // background
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-200.0f, -115.0f, 200.0f);       // esquerda baixo
    glVertex3f(200.0f, -115.0f, 200.0f);       // direita baixo
    glVertex3f(200.0f, -115.0f, -200.0f);     // direita cima
    glVertex3f(-200.0f, -115.0f, -200.0f);   // esquerda cima
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void changeSize(int w, int h) {
    if (h == 0) h = 1;
    float ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void CameraMove(int x, int y) {
    rotate_y -= 0.5;
    glutPostRedisplay();
}

void idle() {
    glutPostRedisplay();
}

void iluminacao() {
    GLfloat luzAmbiente[4]   = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat luzDifusa[4]     = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat luzEspecular[4]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat posicaoLuz[4]    = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat especularidade[4] = { 0.5, 0.5, 0.5, 1.0 };
    GLint especMaterial = 60;

    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
