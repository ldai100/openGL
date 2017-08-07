//
//  main.cpp
//  color_mixer
//
//  Created by Li Dai on 7/31/17.
//  Copyright © 2017 Li Dai. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <vector>
#include <string>
using namespace std;

int width = 800, height = 600;
GLint Xbox = width/2 + 50, Ybox = height/2;
GLfloat XGradient = width/2, YGradient = height/6;
GLfloat currentR = 0, currentG = 0, currentB = 0;
bool onR, onG, onB, onGradient;
bool onRy, onGy, onBy;
bool outBoundR, outBoundG, outBoundB;
GLint offset, newY;

struct edge{
    GLfloat R;
    GLfloat G;
    GLfloat B;
};

class slider{
public:
    GLfloat bottomX, bottomY;
    GLfloat tabX, tabY;
    GLfloat colorR, colorG, colorB;
    GLfloat tabR, tabG, tabB;

    int currentVal;
    char name;
    
    slider(char n, GLint x, GLint y, GLfloat cr, GLfloat cg, GLfloat cb){
        name = n;
        bottomX = x;
        bottomY = y;
        tabX = x;
        tabY = y;
        tabR = colorR = cr;
        tabG = colorG = cg;
        tabB = colorB = cb;
        currentVal = 0.0;
    }
};

vector<slider> myV;  //making it a global variable;
vector<edge*> edges;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //draw color box;
    glBegin(GL_QUADS);
        glColor3f(currentR, currentG, currentB);
        glVertex2i(Xbox, Ybox);
        glVertex2i(Xbox + 250, Ybox);
        glVertex2i(Xbox + 250, Ybox + 250);
        glVertex2i(Xbox, Ybox + 250);
    
    //draw gradient box;
        glColor3f(edges[0]->R, edges[0]->G, edges[0]->B);
        glVertex2i(XGradient, YGradient);
        glVertex2i(XGradient, YGradient+70);
        glColor3f(edges[1]->R, edges[1]->G, edges[1]->B);
        glVertex2i(XGradient+350, YGradient+70);
        glVertex2i(XGradient+350, YGradient);
    
    glEnd();
    
    //printing the characters of the slider;
    for(auto bar : myV){
        glColor3f(bar.colorR, bar.colorG, bar.colorB);
        glRasterPos2f(bar.bottomX - 6, bar.bottomY - 40);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bar.name);
        string val = to_string(bar.currentVal);
        int offset = 0;
        if(bar.currentVal >= 100) offset = -14;
        else if(bar.currentVal < 100 && bar.currentVal >= 10) offset = -8;
        else offset = -4;
        glRasterPos2f(bar.bottomX + offset, bar.bottomY + 320);
        for(int i = 0; i < val.length(); i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, val[i]);
        }
    }
    
    glBegin(GL_POINTS);
        //draw sliders;
        for(auto bar : myV){
            for(int i = bar.bottomX; i < bar.bottomX + 2; i++){
                glColor3f(bar.colorR, bar.colorG, bar.colorB);
                for(int j = bar.bottomY; j < bar.bottomY + 300; j++){
                    glVertex2i(i, j);
                }
            }
            //draw tabs;
            glColor3f(bar.tabR, bar.tabG, bar.tabB);
            for(int i = bar.tabX - 14; i < bar.tabX + 15; i++){
                for(int j = bar.tabY - 8; j < bar.tabY+9; j++){
                    glVertex2i(i, j);
                }
            }
        }
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'l':
            edges[0]->R = currentR;
            edges[0]->G = currentG;
            edges[0]->B = currentB;
            break;
        case 'r':
            edges[1]->R = currentR;
            edges[1]->G = currentG;
            edges[1]->B = currentB;
            break;
    }
    glutPostRedisplay();
}

//this function checks for all the conditions;
void checkposition(int mouseX, int mouseY){
    onR = mouseX <= myV[0].tabX + 16 && mouseX >= myV[0].tabX -14 &&
    mouseY >= height-1-myV[0].tabY-8 && mouseY <= height-1-myV[0].tabY+10;
    onG = mouseX <= myV[1].tabX + 16 && mouseX >= myV[1].tabX -14 &&
    mouseY >= height-1-myV[1].tabY-8 && mouseY <= height-1-myV[1].tabY+10;
    onB = mouseX <= myV[2].tabX + 16 && mouseX >= myV[2].tabX -14 &&
    mouseY >= height-1-myV[2].tabY-8 && mouseY <= height-1-myV[2].tabY+10;
    onGradient = mouseX >= XGradient && mouseX <= XGradient + 350 &&
    mouseY >= height - 1 - YGradient - 70 && mouseY <= height - 1 - YGradient;
    onRy = mouseX <= myV[0].bottomX + 4 && mouseX >= myV[0].bottomX - 4 &&
    mouseY >= height -1 - myV[0].bottomY - 300 && mouseY <= height - 1 - myV[0].bottomY;
    onGy = mouseX <= myV[1].bottomX + 4 && mouseX >= myV[1].bottomX - 4 &&
    mouseY >= height -1 - myV[1].bottomY - 300 && mouseY <= height - 1 - myV[1].bottomY;
    onBy = mouseX <= myV[2].bottomX + 4 && mouseX >= myV[2].bottomX - 4 &&
    mouseY >= height -1 - myV[2].bottomY - 300 && mouseY <= height - 1 - myV[2].bottomY;
}


void mouse(int button, int state, int x, int y){
    bool leftClick = button == GLUT_LEFT_BUTTON;
    bool clickDown = state == GLUT_DOWN;
    if(onR && leftClick){
        myV[0].tabR = 0.5;
        offset = height - 1 - myV[0].tabY - y;
    }
    else if(onG && leftClick){
        myV[1].tabG = 0.5;
        offset = height - 1 - myV[1].tabY - y;
    }
    else if(onB && leftClick){
        myV[2].tabB = 0.5;
        offset = height - 1 - myV[2].tabY - y;
    }
    else if(onRy && leftClick && clickDown){
        myV[0].tabR = 0.5;
        myV[0].tabY = height - 1 - y;
        offset = 0;
    }
    else if(onGy && leftClick && clickDown){
        myV[1].tabG = 0.5;
        myV[1].tabY = height - 1 - y;
        offset = 0;
    }
    else if(onBy && leftClick && clickDown){
        myV[2].tabB = 0.5;
        myV[2].tabY = height - 1 - y;
        offset = 0;
    }
    else if(onGradient && leftClick && state == GLUT_DOWN){
        //not using built in color capture as requested;
        //this will get the color on the gradient and update all related info;
        double percent = (x-XGradient)/350.0;
        currentR = edges[0]->R + percent*(edges[1]->R - edges[0]->R);
        myV[0].tabY = myV[0].bottomY + 299*(myV[0].currentVal = 255*currentR)/255;
        currentG = edges[0]->G + percent*(edges[1]->G - edges[0]->G);
        myV[1].tabY = myV[1].bottomY + 299*(myV[1].currentVal = 255*currentG)/255;
        currentB = edges[0]->B + percent*(edges[1]->B - edges[0]->B);
        myV[2].tabY = myV[2].bottomY + 299*(myV[2].currentVal = 255*currentB)/255;
    }
    else if(leftClick && state == GLUT_UP){
        myV[0].tabR = myV[1].tabG = myV[2].tabB = 1;
    }
    checkposition(x, y);
    glutPostRedisplay();
}

void checkDisEngage(int x, int y){  //this is to see if cursor is too far away;
    outBoundR = x >= (myV[0].tabX + 50) || x <= (myV[0].tabX - 50);
    outBoundG = x >= (myV[1].tabX + 50) || x <= (myV[1].tabX - 50);
    outBoundB = x >= (myV[2].tabX + 50) || x <= (myV[2].tabX - 50);
}

void motion(int x, int y){
    checkDisEngage(x, y);
    newY = y + offset;  //this line solves the tab jumping issue.  :)
    if(onR){
            if(outBoundR){
                onR = false;
                myV[0].tabR = 1;
            }
            if(newY < height - 1 - myV[0].bottomY - 300) myV[0].tabY = myV[0].bottomY+300;
            else if(newY >= height - 1 - myV[0].bottomY) myV[0].tabY = myV[0].bottomY;
            else  myV[0].tabY = height - 1 - y - offset;
            myV[0].currentVal = 255*(myV[0].tabY - myV[0].bottomY)/(300);
            currentR = (myV[0].tabY - myV[0].bottomY)/(300);
    }
    else if(onG){
            if(outBoundG){
                onG = false;
                myV[1].tabG = 1;
            }
            if(newY < height - 1 - myV[0].bottomY - 300) myV[1].tabY = myV[1].bottomY+300;
            else if(newY >= height - 1 - myV[0].bottomY) myV[1].tabY = myV[1].bottomY;
            else  myV[1].tabY = height - 1 - y - offset;
            myV[1].currentVal = 255*(myV[1].tabY - myV[1].bottomY)/(300);
            currentG = (myV[1].tabY - myV[1].bottomY)/(300);
    }
    else if(onB){
            if(outBoundB){
                onB = false;
                myV[2].tabB = 1;
            }
            if(newY < height - 1 - myV[0].bottomY - 300) myV[2].tabY = myV[2].bottomY+300;
            else if(newY >= height - 1 - myV[0].bottomY) myV[2].tabY = myV[2].bottomY;
            else  myV[2].tabY = height - 1 - y - offset;
            myV[2].currentVal = 255*(myV[2].tabY - myV[2].bottomY)/(300);
            currentB = (myV[2].tabY - myV[2].bottomY)/(300);
    }
    glutPostRedisplay();
}


void passive(int mouseX, int mouseY){
    checkposition(mouseX, mouseY);
    if(onR){
        myV[0].tabR = 0.90;
    }
    else if(onG){
        myV[1].tabG = 0.90;
    }
    else if(onB){
        myV[2].tabB = 0.90;
    }
    else{   //when cursor leaves any of the tabs, back to normal;
        myV[0].tabR = 1;
        myV[1].tabG = 1;
        myV[2].tabB = 1;
    }
    glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    char name[3] = {'R', 'G', 'B'};
    GLfloat colors[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for(int i = 0; i < 3; i++){
        slider newS(name[i], 100+i*100, 200, colors[i][0], colors[i][1], colors[i][2]);
        myV.push_back(newS);
    }
    edges.push_back(new edge{0,0,0});
    edges.push_back(new edge{0,0,0});
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Color Mixer");
    glClearColor(0.75, 0.75, 0.75, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passive);
    glutMainLoop();
    return 0;
}
