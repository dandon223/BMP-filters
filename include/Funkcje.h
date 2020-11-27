//
// Created by Magda on 25.09.2020.
//

#ifndef BMP2_FUNKCJE_H
#define BMP2_FUNKCJE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#pragma pack(push)
#pragma pack(1)

typedef struct Header{
    uint16_t type;
    uint32_t file_size;
    uint32_t reserved;
    uint32_t data_offset;
} Header;
typedef struct InfoHeader{
    uint32_t Info_Header_Size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t resolution_x;
    int32_t resolution_y;
    uint32_t colors_used;
    uint32_t important_colors;
}InfoHeader;

typedef struct data{
    unsigned char *pixel_data;
}data;
typedef struct data2{
    uint16_t *pixel_data2;
}data2;



#pragma pack(pop)

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int what_padding(struct InfoHeader *pointer2, int n);

void median_24(struct InfoHeader *pointer2,struct data *pointer3,struct data *pointer4,int n);
void average_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n );
void minimal_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n);
void maximal_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n);
void grey_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4);
void negative_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4);

void median_32(struct InfoHeader *pointer2,struct data *pointer3,struct data *pointer4,int n);
void average_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n );
void minimal_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n);
void maximal_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n);
void grey_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4);
void negative_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4);

void median_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n);
void average_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n );
void minimal_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n);
void maximal_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n);
void grey_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4);
void negative_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4);










#endif

