//
//  main.cpp
//  TutorialLightSphere
//
//  Created by zzm on 1/25/15.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <sys/time.h>
#include <GLUT/GLUT.h>
#include "pngloader.h"
#include "event_handler.h"
#include "font.h"


void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0, 0, -10);
    glutSolidCube(2);
    glTranslatef(5, 0, 0);
    glRotatef(30, 0, 1, 0);
    glutSolidCube(2);
    glPopMatrix();
    glTranslatef(0, 0, 20);
    glTranslated(-5, 0, -10);
//    glRotated(60, 1, 0, 0);
//    glutSolidSphere(2.0, 40, 32);
    
    glutSwapBuffers();
}
int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
    
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Light Move");
    
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 0.0, 0.0, 1.0, 1.0 };
    glShadeModel (GL_SMOOTH);
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

