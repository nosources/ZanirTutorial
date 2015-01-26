//
//  main.cpp
//  Tutorial9Terrain
//
//  Created by nosources on 15-1-26.
//  Copyright (c) 2015年 nosources. All rights reserved.
//

#include <iostream>

#include <GLUT/GLUT.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}
int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("terrain");
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

