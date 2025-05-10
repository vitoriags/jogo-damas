#include <GL/glut.h>
#include "board.hpp"
#include "engine.hpp"
#include "input.hpp"
#include "types.hpp"

int main(int argc, char** argv) {
    // Inicializa o GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("JOGOS DE DAMAS");

    // Inicializa quadric
    quad = gluNewQuadric();

    // Inicializa tabuleiro com posições e peças
    coord(-40, -30, 10.0);

    // Callbacks de renderização e interação
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(idle);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(CameraMove);

    // Configura a iluminação do ambiente
    iluminacao();

    // Inicia o loop principal
    glutMainLoop();

    return 0;
}
