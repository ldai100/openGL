//
//  main.cpp
//  Cafe_Wall
//
//  Created by Li Dai on 7/18/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>

void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    int i=0;  //used to move squares back and forth;
    bool moveLeft=true;
    for(int y=0; y<9; y++){
        for(int x=0; x<15; x++){
            float currentColor;
            
            currentColor = x%2 ? 0.0:1.0;  //determines which color to print;
            glColor3f(currentColor, currentColor, currentColor);
            glVertex2i(x*60+i+2, y*60+2); //bottom left corner;
            glVertex2i(x*60+i+60, y*60+2); //bottom right corner;
            glVertex2i(x*60+i+60, y*60+60);  //top right corner;
            glVertex2i(x*60+i+2, y*60+60); //top left corner;
        }
        
        if(y%2 == 0) moveLeft = !moveLeft;  //every two lines movement is reversed;
        if(moveLeft) i += 20;  //move more to the right;
        else i -= 20;   //move more to the left;
    }
    glEnd();
    glFlush();
    
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(860, 540);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Cafe Wall");
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 860.0, 0.0, 540.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
