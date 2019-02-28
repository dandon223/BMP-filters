#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "Funkcje.h"


int massage;

int  main(int argc , char *argv[])
{
     if(   argc < 5   )
     {
        printf("Za malo argumentow!\n");
        return -1;
     }

     if((argc==5) && atoi(argv[4])%2==0)
     {
         printf("Maska musi byc o nieparzystej dlugosci!\n");
         return -1;
     }
     Header *pointer;
     pointer = malloc(sizeof(Header));
     if(pointer==NULL)
     {
         printf("Nie mozna bylo przydzielic pamieci plikowi!");
         return -1;
     }
     FILE *fp = fopen( argv[1], "rb");
     if (fp ==NULL )
     {
        printf("Zla nazwa!");
        return 1;
     }
     fread(pointer, sizeof(Header),1,fp);
     int w = pointer->type;
     if (w != 0x4D42){
         printf("Zly plik do odczytu");
         return 1;
        }
    InfoHeader * pointer2;
    pointer2 = malloc(sizeof(InfoHeader));
    fread(pointer2,sizeof(InfoHeader),1,fp);
    if(pointer2==NULL)
     {
         printf("Nie mozna bylo przydzielic pamieci plikowi!");
         return -1;
     }
    if(pointer2->compression !=0)
    {
        printf("Niestety kompresja nie jest zerowa :(\n");
        return -1;
    }
if(pointer2->bits_per_pixel ==24 ||pointer2->bits_per_pixel ==32)
{
    data* pointer3;
    pointer3 = malloc(sizeof(data));
    pointer3->pixel_data = malloc(pointer2->image_size);
    fread(pointer3->pixel_data,pointer2->image_size,1 ,fp);
    if(pointer3==NULL)
     {
         printf("Nie mozna bylo przydzielic pamieci plikowi!");
         return -1;
     }
    data* pointer4;
    pointer4 = malloc(sizeof(data));
    pointer4->pixel_data = malloc(pointer2->image_size);
    if(pointer4==NULL)
     {
         printf("Nie mozna bylo przydzielic pamieci plikowi!");
         return -1;
     }
   for(int i=0; i< pointer2->image_size;i++)
   {
       pointer4->pixel_data[i] = pointer3->pixel_data[i];
   }
    int x =3;
    if(argc == 5)
         x = atoi(argv[4]);

    if( pointer2->bits_per_pixel ==24 )
    {
        if (strcmp(argv[3],"med") == 0)
            median_24(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "ave") ==0)
            average_24(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "min") ==0)
            minimal_24(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "max") ==0)
            maximal_24(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "grey") ==0)
            grey_24(pointer2,pointer3,pointer4);
        else if (strcmp(argv[3], "neg") ==0)
            negative_24(pointer2,pointer3,pointer4);
        else
        {
        printf("Podano zly argument!\n");
        return 1;
        }
    }
    if( pointer2->bits_per_pixel ==32 )
    {
        if (strcmp(argv[3],"med") == 0)
            median_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "ave") ==0)
            average_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "min") ==0)
            minimal_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "max") ==0)
            maximal_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "grey") ==0)
            grey_32(pointer2,pointer3,pointer4);
        else if (strcmp(argv[3], "neg") ==0)
            negative_32(pointer2,pointer3,pointer4);
        else
        {
        printf("Podano zly argument!\n");
        return 1;
        }
    }
    FILE *fw = fopen(argv[2], "wb");
    if (fw ==NULL )
    {
        printf("Nie mozna bylo zapisac pliku!");
        return -1;
    }
    fwrite(pointer, sizeof(Header),1,fw);
    fwrite(pointer2,sizeof(InfoHeader),1,fw);
    fwrite(pointer4->pixel_data,pointer2->image_size,1 ,fw);
    free(pointer);
    free(pointer2);
    free(pointer3->pixel_data);
    free(pointer3);
    free(pointer4->pixel_data);
    free(pointer4);
    fclose(fp);
    fclose (fw);
    return 0;
}
    if(pointer2->bits_per_pixel ==16)
    {
        data2* pointer3;
        pointer3 = malloc(sizeof(data2));
        pointer3->pixel_data2 = malloc(pointer2->image_size*2);
        fread(pointer3->pixel_data2,pointer2->image_size,1 ,fp);
        if(pointer3==NULL)
        {
            printf("Nie mozna bylo przydzielic pamieci plikowi!");
            return -1;
        }
        data2* pointer4;
        pointer4 = malloc(sizeof(data2));
        pointer4->pixel_data2 = malloc(pointer2->image_size*2);
        if(pointer4==NULL)
        {
            printf("Nie mozna bylo przydzielic pamieci plikowi!");
            return -1;
        }
        for(int i=0; i< pointer2->image_size;i++)
        {
            pointer4->pixel_data2[i] = pointer3->pixel_data2[i];
        }
        int x =3;
        if(argc == 5)
            x = atoi(argv[4]);
        if (strcmp(argv[3],"med") == 0)
            median_16(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "ave") ==0)
            average_16(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "min") ==0)
            minimal_16(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "max") ==0)
            maximal_16(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "grey") ==0)
            grey_16(pointer2,pointer3,pointer4);
        else if (strcmp(argv[3], "neg") ==0)
            negative_16(pointer2,pointer3,pointer4);
        else
        {
        printf("Podano zly argument!\n");
        return 1;
        }




        FILE *fw = fopen(argv[2], "wb");
        if (fw ==NULL )
        {
            printf("Nie mozna bylo zapisac pliku!");
            return -1;
        }
        fwrite(pointer, sizeof(Header),1,fw);
        fwrite(pointer2,sizeof(InfoHeader),1,fw);
        fwrite(pointer4->pixel_data2,pointer2->image_size,1 ,fw);
        free(pointer);
        free(pointer2);
        free(pointer3->pixel_data2);
        free(pointer3);
        free(pointer4->pixel_data2);
        free(pointer4);
        fclose(fp);
        fclose (fw);
        return 0;
    }
    if(pointer2->bits_per_pixel ==8)   // autor : _0x666_ , przerobione przeze mnie
    {
        uint32_t* color_table = malloc(pointer2->colors_used * 4);
        fread(color_table, pointer2->colors_used * 4, 1, fp);
        fseek(fp, pointer->data_offset, SEEK_SET);
        unsigned char* pixel_data = malloc(pointer2->image_size);
        fread(pixel_data, pointer2->image_size, 1, fp);
        int bmp_width = pointer2->width;
        int bmp_height = pointer2->height;

        data* pointer3;
        pointer3 = malloc(sizeof(data));
        pointer3->pixel_data = malloc(bmp_height * bmp_width * 4);

        size_t scanline_size = bmp_width % 4;
        if(scanline_size==1) scanline_size = 4 - scanline_size;
        else if(scanline_size==3) scanline_size = 4 - scanline_size;
        scanline_size += bmp_width;

        unsigned char* src_line = pixel_data;
        unsigned char* dst_ptr = pointer3->pixel_data;

        for(int j = 0; j < bmp_height; j++)
        {
            for(int i = 0; i < bmp_width; i++)
            {
                uint32_t value = color_table[src_line[i]];
                unsigned char R = ((value & 0xFF0000) >> 16);
                unsigned char G = ((value & 0xFF00) >> 8);
                unsigned char B = (value & 0xFF);
                unsigned char A = ((value & 0xFF000000)>>24);
                *dst_ptr++ = B;
                *dst_ptr++ = G;
                *dst_ptr++ = R;
                *dst_ptr++ = A;
            }

            src_line += scanline_size;
        }
    pointer2->image_size = 4 * bmp_width * bmp_height;
    pointer->file_size = 54 + pointer2->image_size;
    pointer->data_offset = 54;
    pointer2->bits_per_pixel = 32;
    pointer2->colors_used = 0;

    data* pointer4;
    pointer4 = malloc(sizeof(data));
    pointer4->pixel_data = malloc(pointer2->image_size);

        int x =3;
        if(argc == 5)
            x = atoi(argv[4]);
        if (strcmp(argv[3],"med") == 0)
            median_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "ave") ==0)
            average_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "min") ==0)
            minimal_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "max") ==0)
            maximal_32(pointer2,pointer3,pointer4,x);
        else if (strcmp(argv[3], "grey") ==0)
            grey_32(pointer2,pointer3,pointer4);
        else if (strcmp(argv[3], "neg") ==0)
            negative_32(pointer2,pointer3,pointer4);
        else
        {
        printf("Podano zly argument!\n");
        return 1;
        }

        FILE *fw = fopen(argv[2], "wb");
        if (fw ==NULL )
        {
            printf("Nie mozna bylo zapisac pliku!");
            return -1;
        }
        fwrite(pointer, sizeof(Header),1,fw);
        fwrite(pointer2,sizeof(InfoHeader),1,fw);
        fwrite(pointer4->pixel_data,pointer2->image_size,1 ,fw);
        free(pointer);
        free(pointer2);
        free(pointer3->pixel_data);
        free(pointer3);
        free(pointer4->pixel_data);
        free(pointer4);
        free(color_table);
        free(pixel_data);
        fclose(fp);
        fclose (fw);
        return 0;
    }
    else
        {
        printf("Podano obrazek nie obslugiwany!\n");
        return 1;
        }
}


