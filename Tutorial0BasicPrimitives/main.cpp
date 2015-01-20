//
//  main.cpp
//  Tutorial0BasicPrimitives
//
//  Created by nosources on 15-1-20.
//  Copyright (c) 2015年 nosources. All rights reserved.
//

#include <iostream>

#include <GLUT/GLUT.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0f, 0.0f, -5.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_POINTS);
    glVertex3f(-2.0f, 2.0f, 0.0f);
    glVertex3f(-2.1f, 2.0f, 0.0f);
    glVertex3f(-2.2f, 2.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-1.8f, 2.0f, 0.0f);
    glVertex3f(-1.5f, 1.5f, 0.0f);
    
    glVertex3f(-1.3f, 2.0f, 0.0f);
    glVertex3f(-1.7f, 1.4f, 0.0f);
    
    glVertex3f(-1.4f, 2.0f, 0.0f);
    glVertex3f(-1.4f, 1.3f, 0.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();
    
    
    
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f,2.0f,0.0f);
    glVertex3f(-0.8f,1.5f,0.0f);
    glVertex3f(-0.5f,2.0f,0.0f);
    glVertex3f(-1.1f,1.8f,0.0f);
    glVertex3f(-0.8f,1.3f,0.0f);
	glEnd();
    
    glBegin(GL_POLYGON);		//kreslíme mnohouholník
    glVertex3f(0.0f,2.0f,0.0f);
    glVertex3f(0.5f,1.8f,0.0f);
    glVertex3f(0.8f,1.2f,0.0f);
    glVertex3f(0.5f,1.7f,0.0f);
    glVertex3f(0.0f,1.3f,0.0f);
    glVertex3f(-0.2f,1.5f,0.0f);
	glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(1.0f,2.0f,0.0f);
    glVertex3f(1.4f,1.8f,0.0f);
    glVertex3f(1.3f,1.0f,0.0f);
    glVertex3f(1.1f,1.2f,0.0f);
    
    glColor3f(0.8f,0.0f,0.5f);
	
    glVertex3f(1.5f,2.0f,0.0f);
    glVertex3f(1.9f,1.8f,0.0f);
    glVertex3f(1.8f,1.0f,0.0f);
    glVertex3f(1.6f,1.2f,0.0f);
	glEnd();
    
    glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_TRIANGLES);		//kreslíme trojuholníky
    glVertex3f(-1.8f,0.5f,0.0f);
    glVertex3f(-2.0f,-0.4f,0.0f);
    glVertex3f(-1.5f,-0.2f,0.0f);
    
    glColor3f(0.2f,0.0f,0.9f);
    glVertex3f(-2.0f,-0.2f,0.0f);
    glVertex3f(-2.3f,0.5f,0.0f);
    glVertex3f(-2.5f,-0.4f,0.0f);
    
    glColor3f(1.0f,0.0f,0.0f);		//farebný trojuholík
    glVertex3f(-1.4f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);		//zelená
    glVertex3f(-1.5f,-0.4f,0.0f);
    glColor3f(0.0f,0.0f,1.0f);		//modrá
    glVertex3f(-1.1f,0.2f,0.0f);
	glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);			//kreslíme pruh trojuholníkov
    glColor3f(0.1f,0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,0.0f);
    
    glColor3f(0.5f,0.0f,0.0f);
    glVertex3f(-0.7f,0.0f,0.0f);
    
    glColor3f(0.5f,0.5f,0.0f);
    glVertex3f(-0.4f,-0.8f,0.0f);
    
    glColor3f(0.5f,0.5f,0.5f);
    glVertex3f(-0.3f,-0.3f,0.0f);
    
    glColor3f(1.0f,0.5f,0.5f);
    glVertex3f(0.0f,-1.3f,0.0f);
    
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f(0.3f,0.1f,0.0f);
    
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(0.5f,-1.0f,0.0f);
	glEnd();
    
    
    glTranslatef(2.0f,0.0f,0.0f);		//posunieme suradnicovu sustavu do bodu 2.3,-1.5,0.0
	glRotatef(111.0f, 111.0f,111.0f,111.0f);	//rotujeme okolo z vektora
	glBegin(GL_TRIANGLES);				//kreslíme trojuholík
    glColor3f(1.0f,1.0f,1.0f);
	
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(1.0f,0.0f,0.0f);
    
	glEnd();
    
    glutSwapBuffers();
}
int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("primitives");
    glutDisplayFunc(display);
    
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 1, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glShadeModel(GL_SMOOTH);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClearDepth(100.0f);
    
    glutMainLoop();
    return 0;
}

