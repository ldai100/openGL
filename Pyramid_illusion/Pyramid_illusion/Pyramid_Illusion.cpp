//
//  main.cpp
//  Pyramid_illusion
//
//  Created by Li Dai on 7/19/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>

void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    float current = 0.0;
    int x, y;
    x=0;
    y=0;
    
    glBegin(GL_QUADS);
    while(current < 1.0){
        glColor3f(current, 1-current, 1-current);
        //above code would work as long as current is in there;
        glVertex2f(x, y);  //bottom left;
        glVertex2f(600-x, y);  //bottom right;
        glVertex2f(600-x, 600-y);  //top right;
        glVertex2f(x, 600-y);  //top left;
        
        //since I'm using 600x600, the iteration should be 30 times;
        //thus, the values below were pre-calculated;
        current += 0.0333333333;
        x += 10;
        y += 10;
    }
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Pyramid Illusion");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
