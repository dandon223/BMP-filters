#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "..\include\Funkcje.h"

void median_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4, int n)
{
    int padding = what_padding(pointer2,4);
    int *tab;

    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*4 +padding) + t*4; i< j*(a*4+padding)+(a*4+padding)-padding-t*4;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*4+padding) - t*4 + e*4 + d*(a*4+padding)];
            }
            mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[(n*n-1)/2];
        }
    }
    free(tab);
}

void average_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,4);
    int *tab;

    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*4 +padding) + t*4; i< j*(a*4+padding)+(a*4+padding)-padding-t*4;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*4+padding) - t*4 + e*4 + d*(a*4+padding)];
            }
            int suma=0;
            for(int i = 0 ; i< n*n ; i++)
                suma = suma +tab[i];
            pointer4->pixel_data[i] = suma/(n*n);
        }
    }
    free(tab);
}

void minimal_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,4);
    int *tab;

    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*4 +padding) + t*4; i< j*(a*4+padding)+(a*4+padding)-padding-t*4;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*4+padding) - t*4 + e*4 + d*(a*4+padding)];
            }
            mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[0];
        }
    }
    free(tab);
}

void maximal_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,4);
    int *tab;

    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*4 +padding) + t*4; i< j*(a*4+padding)+(a*4+padding)-padding-t*4;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*4+padding) - t*4 + e*4 + d*(a*4+padding)];
            }
            mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[n*n-1];
        }
    }
    free(tab);
}

void grey_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4)
{
    int padding = what_padding(pointer2,4);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++)
    {
        for(int i = j*(a*4 +padding) ; i< j*(a*4+padding)+(a*4+padding)-padding ;i= i + 4)
        {
            int average = (pointer3->pixel_data[i] + pointer3->pixel_data[i+1] + pointer3->pixel_data[i+2])/3;
            pointer4->pixel_data[i] = average;
            pointer4->pixel_data[i+1] = average;
            pointer4->pixel_data[i+2] = average;
        }
    }
}

void negative_32(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4)
{
    int padding = what_padding(pointer2,4);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++)
    {
        for(int i = j*(a*4 +padding) ; i< j*(a*4+padding)+(a*4+padding)-padding ;i= i + 4)
        {
            pointer4->pixel_data[i] = 255 - pointer3->pixel_data[i];
            pointer4->pixel_data[i+1] = 255 -pointer3->pixel_data[i+1];
            pointer4->pixel_data[i+2] = 255 - pointer3->pixel_data[i+2];
        }
    }
}
