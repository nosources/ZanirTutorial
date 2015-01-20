//
//  png.c
//  openglmore
//
//  Created by nosources on 14-10-29.
//  Copyright (c) 2014年 nosources. All rights reserved.
//

#include <stdio.h>
#include "png.h"
#include "pngloader.h"
GLuint load_png(char* file_name){
    png_structp png_ptr;
    png_infop info_ptr;
    unsigned int sig_read = 0;
    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("file not exit.\n");
        exit(1);
    }
    
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        printf("png ptr create failed.\n");
        exit(1);
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        printf("info ptr create failed.\n");
        exit(1);
    }
    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_info_struct(png_ptr, &info_ptr);
        exit(1);
    }
    png_init_io(png_ptr, file);
    png_set_sig_bytes(png_ptr, sig_read);
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, png_voidp_NULL);
    
    png_uint_32 width = info_ptr->width;
    png_uint_32 height = info_ptr->height;
    int has_alpha = 0;
    switch (info_ptr->color_type) {
        case PNG_COLOR_TYPE_RGBA:
            has_alpha = 1;
            break;
        case PNG_COLOR_TYPE_RGB:
            has_alpha = 0;
            break;
        default:
            printf("color type error.\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
            exit(1);
            break;
    }
    unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    unsigned char* data = (unsigned char*)malloc(row_bytes * height);
    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
    for (int i = 0; i < height; i++) {
        memcpy(data + row_bytes * (height - 1 - i), row_pointers[i], row_bytes);
    }
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(file);
    
    GLuint textureID = 0;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, has_alpha ? 4 : 3, width,
                 height, 0, has_alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE,
                 data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    return textureID;
}