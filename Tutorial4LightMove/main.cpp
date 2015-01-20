//
//  main.cpp
//  Tutorial4LightMove
//
//  Created by zzm on 1/20/15.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "pngloader.h"
#include "event_handler.h"
#include "font.h"
GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 1.0f, 0.0f};
GLfloat material[]  ={1.0f, 1.0f, 1.0f, 1.0f};

GLuint textureId;

extern int anglex;
extern int angley;
void drawCube(){
    glBegin(GL_QUADS);
    // Front Face
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    // Back Face
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    // Top Face
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    // Bottom Face
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    // Right face
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    // Left Face
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glLoadIdentity();
    glTranslated(0, 0, -15);
    glPushMatrix();
    glTranslated(-7, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube();glPopMatrix();
    glPushMatrix();
    glTranslated(2, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube();glPopMatrix();
    glPushMatrix();
    glTranslated(6, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube();

    glutSwapBuffers();
}
int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
    
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Light Move");
    
    glViewport(0, 0, 800, 800);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_LIGHT0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);
    
    textureId = load_png("resources/tex.png");
    register_event_func();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

