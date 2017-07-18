//
//  main.cpp
//  Hering_Illusion
//
//  Created by Li Dai on 7/15/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>

void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for(int i=-800; i<1600; i += 100){
        glVertex2i(i, 0);
        glVertex2i(800-i, 399);
    }
    glColor3f(1.0, 0.0, 0.0);
    for(int i=139; i<260; i += 120){
        //this inner loop is to make the red line thicker;
        //because the red line in the book is thicker than others;
        for(int j=-1; j<=1; j++){
            glVertex2i(0, i+j);
            glVertex2i(800, i+j);
        }
    }
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Hering Illusion");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 400.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
