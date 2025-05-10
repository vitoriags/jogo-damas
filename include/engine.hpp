#ifndef ENGINE_HPP
#define ENGINE_HPP

// Variáveis de rotação e zoom da câmera
extern double rotate_x;
extern double rotate_y;
extern double cameraT_z;

// Funções principais da engine gráfica
void renderScene();
void changeSize(int w, int h);
void CameraMove(int x, int y);
void idle();
void iluminacao();

#endif
