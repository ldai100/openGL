//
//  main.cpp
//  sample2
//
//  Created by Li Dai on 7/12/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <math.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>

GLfloat r(double angle){
    return 1 - cos(angle);
}

void display(void){
    double t, p=3.141593/180;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for(int i=0; i<360; i=i+4){
        t = i * p;
        glVertex2f(r(t)*cos(t), r(t)*sin(t));
    }
    glEnd();
    glFlush();
}

void reshape(int width, int height){
    float w_aspect = 4.0/3.0, aspect = ((float) width) / height;
    if(aspect <= w_aspect)
        glViewport(0, (height-width/w_aspect)/2, width, width/w_aspect);
    else
        glViewport((width-height*w_aspect)/2, 0, height*w_aspect, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -1.5, 1.5);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("sample2");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -1.5, 1.5);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
