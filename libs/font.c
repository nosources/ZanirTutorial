//
//  font.c
//  vertexArrayExample
//
//  Created by nosources on 14-10-28.
//
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <string.h>
GLuint fontTextureID;

GLuint base;
GLvoid build_font(){
    glGenLists(256);
    glBindTexture(GL_TEXTURE_2D, fontTextureID);
    float cx;
    float cy;
    float row_width = 1.0f / 16;
    float column_height = 1.0f / 16;
    for (int i = 0; i < 256; i++) {
        cx = (float)(i % 16) / 16.0f;
        cy = (float)(i / 16) / 16.0f;
        
        glNewList(base + i, GL_COMPILE);
        glBegin(GL_QUADS);
        glTexCoord2f(cx, 1.0f - cy - column_height);
        glVertex2i(0, 0);
        glTexCoord2f(cx + row_width, 1.0f - cy - column_height);
        glVertex2i(16, 0);
        glTexCoord2f(cx + row_width, 1.0f - cy);
        glVertex2i(16, 16);
        glTexCoord2f(cx, 1.0f - cy);
        glVertex2i(0, 16);
        glEnd();
        glTranslatef(11, 0, 0);
        glEndList();
    }
}

GLvoid delte_font() {
    glDeleteLists(base, 256);
}

GLvoid print_font(GLint x, GLint y, char* str, int set){
    if (set > 1) {
        set = 1;
    }
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
    glEnable(GL_BLEND);
    
    glBindTexture(GL_TEXTURE_2D, fontTextureID);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 600, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef((float)x, (float)y, 0);
    glListBase(base - 32 + 128 * set);
    glCallLists(strlen(str), GL_BYTE, str);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

GLvoid print_font_(GLint x, GLint y, char* str, int set){
    x *= 11;
    y = 600 - (y+1)*16;
    if (set > 1) {
        set = 1;
    }
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
    glEnable(GL_BLEND);
    
    glBindTexture(GL_TEXTURE_2D, fontTextureID);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 600, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef((float)x, (float)y, 0);
    glListBase(base - 32 + 128 * set);
    glCallLists(strlen(str), GL_BYTE, str);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

















