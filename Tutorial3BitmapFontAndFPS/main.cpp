//
//  main.cpp
//  Tutorial3BitmapFontAndFPS
//
//  Created by nosources on 15-1-20.
//  Copyright (c) 2015年 nosources. All rights reserved.
//

#include <iostream>

#include <GLUT/GLUT.h>
#include "png.h"
#include <sys/time.h>
#include "event_handler.h"
#include "pngloader.h"
#include "font.h"

extern int anglex;
extern int angley;

extern GLuint fontTextureID;

struct timeval last_draw_time;
int drawCount=0;
std::string labelContent;

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0, 0, -5);
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    
    for (int i = 1; i < 2; i++) {
        glColor3f(1.0f,1.0f,1.0f);		//biela farba
        glBindTexture(GL_TEXTURE_2D, fontTextureID);
        glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        // Back Face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        // Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        // Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glEnd();
    }
#define REFRESH_FRAMES 1000
    if (drawCount++ == REFRESH_FRAMES) {
        //every 60 times refresh the label.
        drawCount = 0;
        struct timeval temp = last_draw_time;
        gettimeofday(&last_draw_time, NULL);
        double duration = (double)( last_draw_time.tv_sec - temp.tv_sec ) + (double)(last_draw_time.tv_usec - temp.tv_usec) / 1000000;
        int fps = (float)REFRESH_FRAMES / duration;
        char t[128] = {0};
        sprintf(t, "FPS:%d", fps);
        print_font(0, 0, t, 0);
        labelContent = t;
    }else{
        print_font(0, 0, labelContent.c_str(), 0);
    }

    
    glutSwapBuffers();
}


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
    glutCreateWindow("font of bitmap");
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    fontTextureID = load_png("resources/font.png");
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    build_font();
    drawCount = 0;
    glutDisplayFunc(display);
    register_event_func();
    glutMainLoop();
    return 0;
}

