#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //*************************************************************************
    PutPixel();
    //DrawLine();
    PutPixel(42,63,255,0,0);

}

void PutPixel(void) {
    // Escreve um pixel vermelho na posicao (0,0) da tela:
    FBptr[0] = 255; // componente R
    FBptr[1] = 0;   // componente G
    FBptr[2] = 0;   // componente B
    FBptr[3] = 255; // componente A

    // Escreve um pixel verde na posicao (1,0) da tela:
    FBptr[4] = 0;   // componente R
    FBptr[5] = 255; // componente G
    FBptr[6] = 0;   // componente B
    FBptr[7] = 255; // componente A

    // Escreve um pixel azul na posicao (2,0) da tela:
    FBptr[8] = 0;    // componente R
    FBptr[9] = 0;    // componente G
    FBptr[10] = 255; // componente B
    FBptr[11] = 255; // componente A

    // Escreve um pixel qualquer na posicao (3,2) da tela:
    FBptr[4108] = 127;    // componente R
    FBptr[4109] = 3;    // componente G
    FBptr[4110] = 14; // componente B
    FBptr[4111] = 255; // componente A

    // Escreve um pixel branco na posicao (256,256) da tela:
    FBptr[525312] = 255;    // componente R
    FBptr[525313] = 255;    // componente G
    FBptr[525314] = 255; // componente B
    FBptr[525315] = 255; // componente A
}

void PutPixel(int x, int y, int r, int g, int b){
    int offset = x*4+y*2048;
    FBptr[offset] = r; // componente R
    FBptr[offset+1] = g;   // componente G
    FBptr[offset+2] = b;   // componente B
    FBptr[offset+3] = 255; // componente A
}

void DrawLine(void)
{
    for (unsigned int i = 0; i < 512; ++i)
    {
        FBptr[4 * i + 4 * i * IMAGE_WIDTH + 0] = 255;
        FBptr[4 * i + 4 * i * IMAGE_WIDTH + 1] = 0;
        FBptr[4 * i + 4 * i * IMAGE_WIDTH + 2] = 255;
        FBptr[4 * i + 4 * i * IMAGE_WIDTH + 3] = 255;
    }
}