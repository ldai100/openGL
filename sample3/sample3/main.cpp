//
//  main.cpp
//  sample3
//
//  Created by Li Dai on 7/31/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>

int width =400, height=300, x,y=-1;
void display(){
    glBegin(GL_POINT);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN) glColor3f(0, 1, 0);
            else glColor3f(1, 0, 0);
            break;
            
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN) glColor3f(0, 0, 1);
            else glColor3f(1, 0, 0);
            break;
    }
}

void motion(int mouseX, int mouseY){
    x=mouseX;
    y=height - 1 - mouseY;
    glutPostRedisplay();
}

void passive(int mouseX, int mouseY){
    x=mouseX;
    y=height-1-mouseY;
    glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Trace cursor");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passive);
    glutMainLoop();
    return 0;
}
