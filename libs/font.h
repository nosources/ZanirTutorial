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
#ifdef __cplusplus
extern "C" {
#endif
    GLvoid build_font();
    GLvoid delte_font();
    GLvoid print_font(GLint x, GLint y, const char* str, int set);
    GLvoid print_font_(GLint x, GLint y, const char* str, int set);
#ifdef __cplusplus
}
#endif
