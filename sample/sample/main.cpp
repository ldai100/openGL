//
//  main.cpp
//  sample
//
//  Created by Li Dai on 7/11/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(50, 20);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
    glBegin(GL_POINTS);
    glVertex2i(0,0);
    glVertex2i(0,299);
    glVertex2i(399,0);
    glVertex2i(399,299);
    glEnd();
    glFlush();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(200,100);
    glutCreateWindow("sample");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
