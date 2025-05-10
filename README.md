# Checkers 3D OpenGL Game

Este é um jogo de **Damas em 3D** desenvolvido como projeto do **Bacharelado em Ciência da Computação** em **2022**, para a disciplina de **Computação Gráfica**.

O jogo foi implementado em **C++ com OpenGL (GLUT)**, utilizando modelagem simples para representar peças e tabuleiro, além de aplicar conceitos de câmera, animação e entrada de usuário por teclado.

---

## Como Jogar

- O jogo segue as regras clássicas das damas:
  - Um jogador controla as **peças brancas**, que iniciam o jogo.
  - Outro jogador (ou o mesmo, alternando) controla as **peças pretas**.
  - As peças se movimentam em **diagonais** e podem **capturar pulando sobre a peça adversária**.
  - Ao capturar, um som é reproduzido.
  - Quando um dos jogadores não tiver mais peças, a vitória é exibida.

### Controles do Teclado

| Tecla      | Ação                                               |
|------------|----------------------------------------------------|
| `1`        | Move seleção para esquerda/baixo                   |
| `3`        | Move seleção para direita/baixo                    |
| `7`        | Move seleção para esquerda/cima                    |
| `9`        | Move seleção para direita/cima                     |
| `Espaço`   | Seleciona a peça atual                             |
| `←` `→`    | Move a peça selecionada (esquerda/direita)         |
| `w / s`    | Aproxima ou afasta a câmera                        |
| `a / d`    | Rotaciona a câmera lateralmente                    |
| `Esc`      | Fecha o jogo                                       |

---

## Como Compilar e Executar

### Requisitos

- Linux ou WSL com Ubuntu
  - `g++`
- Bibliotecas OpenGL:
  - `freeglut3-dev`
  - `libglu1-mesa-dev`

### Passos

1. Instale as dependências:

```bash
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
```
2. Compile o Projeto
```bash
make
```
2. Execute o jogo:
```bash
./damas
```
