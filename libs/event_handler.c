//
//  event_handler.c
//  openglmore
//
//  Created by nosources on 14-10-29.
//  Copyright (c) 2014年 nosources. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
int lastx = 0;
int lasty = 0;
int anglex = 0;
int angley = 0;

void mouse_func(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastx = x;
            lasty = y;
        }else if (state == GLUT_UP) {
            
        }
    }
}
void idle_func(){
    glutPostRedisplay();
}
void mouse_motion_func(int x, int y){
    angley += x - lastx;
    anglex += y - lasty;
    
    lastx = x;
    lasty = y;
    glutPostRedisplay();
}
void mouse_passive_motion_func(int x, int y){
    
}

void register_event_func(){
    glutMotionFunc(mouse_motion_func);
    glutMouseFunc(mouse_func);
    glutIdleFunc(idle_func);
}