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
GLfloat lightPosition[] = {0.0f, 0.0, 1.0f, 0.0f};
GLfloat material[]  ={1.0f, 1.0f, 1.0f, 1.0f};

GLuint textureId;

extern int anglex;
extern int angley;
extern int lastx;
extern int lasty;
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
void drawCube2(){
    glBegin(GL_QUADS);
    // Front Face
    glNormal3f(-0.577f,-0.577f, 0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glNormal3f( 0.577f,-0.577f, 0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glNormal3f( 0.577f, 0.577f, 0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glNormal3f(-0.577f, 0.577f, 0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    // Back Face
    glNormal3f(-0.577f,-0.577f,-0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glNormal3f(-0.577f, 0.577f,-0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glNormal3f( 0.577f, 0.577f,-0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glNormal3f( 0.577f,-0.577f,-0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    // Top Face
    glNormal3f(-0.577f, 0.577f,-0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glNormal3f(-0.577f, 0.577f, 0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glNormal3f( 0.577f, 0.577f, 0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glNormal3f( 0.577f, 0.577f,-0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    // Bottom Face
    glNormal3f(-0.577f,-0.577f,-0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glNormal3f( 0.577f,-0.577f,-0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glNormal3f( 0.577f,-0.577f, 0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glNormal3f(-0.577f,-0.577f, 0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    // Right face
    glNormal3f( 0.577f,-0.577f,-0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glNormal3f( 0.577f, 0.577f,-0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glNormal3f( 0.577f, 0.577f, 0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glNormal3f( 0.577f,-0.577f, 0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    // Left Face
    glNormal3f(-0.577f,-0.577f,-0.577f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glNormal3f(-0.577f,-0.577f, 0.577f);glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glNormal3f(-0.577f, 0.577f, 0.577f);glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glNormal3f(-0.577f, 0.577f,-0.577f);glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
}
void drawCube(int z){
    glPushMatrix();
    glTranslated(-z, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube2();
    glPopMatrix();
}
void drawCube2(int z){
    glPushMatrix();
    glTranslated(-z, 0, 0);
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    drawCube2();
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLineWidth(6);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glLoadIdentity();
    glBegin(GL_LINES);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-500.0f, 0.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(500.0f, 0.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -500.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 500.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -500.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 500.0f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, textureId);
    for (int i = 0; i < 20; i++) {
        glTranslated(0, 0, -5);
        drawCube(-6);
        drawCube2(-3);
        drawCube(2);
        drawCube2(5);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
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
    gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
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

