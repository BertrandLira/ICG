#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void){
    PutPixel(42,63,255,0,0);
    DrawLine(1,1,512,512,255,0,0);
    DrawLine(512,1,1,512,0,0,255);
    DrawLine(256,1,256,512,0,255,0);
    DrawLine(1,256,512,256,255,255,255);
    DrawTriangle(85,40,100,300,50,400,255,0,0);
    DrawTriangle(10,500,256,10,502,500,255,255,0);

}

void PutPixel(int x, int y, int r, int g, int b){
    int offset = x*4+y*2048;
    FBptr[offset] = r;
    FBptr[offset+1] = g;
    FBptr[offset+2] = b;
    FBptr[offset+3] = 255;
}

void DrawLine(int x0, int y0, int x1, int y1, int r, int g, int b){
    //int dx = x1 - x0;
    int dy; //= y1 - y0;
    //int d = 2 * dx - dy;
    //int inc_L = 2 * dy;
    //int inc_NE = 2 *(dy - dx);
    int x;// =  x0;
    int y;//= y0;
    bool steep = abs(y1 - y0) > abs(x1 - x0); //verifica se dy > dx
    
    if (steep == true){ //se dy > dx, coeficiente angular > 1, ent troca o eixo
    	int aux = x0;
    	x0 = y0;
    	y0 = aux;
    	aux = x1;
    	x1 = y1;
    	y1 = aux;
    }
    
    if(x0 > x1){ //troca o potno inicial com o ponto final, x e y
    	int aux = x0;
    	x0 = x1;
    	x1 = aux;
    	aux = y0;
    	y0 = y1;
    	y1 = aux;
    }
    
    if (y0 > y1){ 
    	dy = -1; 
    }else {
    	dy = 1;
    }
    
    int delta_x = x1-x0;
    int delta_y = abs(y1-y0);
    
    y = y0;
    int erro = 0;
    
    for(x = x0; x < x1; x++){
        if (steep){ 
            PutPixel(y, x, r, g ,b);
        }else{
            PutPixel(x, y, r, g ,b);
        }
        
        erro = erro + delta_y;
        if (erro*2 >= delta_x){
        	y = y + dy;
        	erro = erro - delta_x;
        }
    }
 

}

void DrawTriangle(int xa, int ya, int xb, int yb, int xc, int yc, int r, int g, int b)
{
    DrawLine(xa,ya,xb,yb,r,g,b);
    DrawLine(xa,ya,xc,yc,r,g,b);
    DrawLine(xb,yb,xc,yc,r,g,b);
}
