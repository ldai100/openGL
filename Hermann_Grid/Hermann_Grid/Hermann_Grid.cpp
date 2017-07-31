//
//  main.cpp
//  Hermann_Grid
//
//  Created by Li Dai on 7/18/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>

void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            glVertex2i(i*120+20, j*120+20); //bottom left corner;
            glVertex2i(i*120+120, j*120+20); //bottom right corner;
            glVertex2i(i*120+120, j*120+120);  //top right corner;
            glVertex2i(i*120+20, j*120+120); //top left corner;
        }
    }
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(620, 620);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Hermann Grid");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 620.0, 0.0, 620.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
