#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "Funkcje.h"
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
}


int what_padding(struct InfoHeader *pointer2,int bits)
{
    int a = pointer2->width;
    int c = a*bits;
    int padding=0; 
    if (c%4==0)
        padding =0;
    if (c%4==1)
        padding =3;
    if (c%4==2)
        padding =2;
    if (c%4==3)
        padding =1;
    return padding;
}

void median_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4, int n)
{
    int padding = what_padding(pointer2, 3 );
    int *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*3 +padding) + t*3; i< j*(a*3+padding)+(a*3+padding)-padding-t*3;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*3+padding) - t*3 + e*3 + d*(a*3+padding)];
            }
                mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[(n*n-1)/2];
        }
   }
free(tab);
}

void average_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,3);
    int *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*3 +padding) + t*3; i< j*(a*3+padding)+(a*3+padding)-padding-t*3;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*3+padding) - t*3 + e*3 + d*(a*3+padding)];
            }
            int suma=0;
            for(int i = 0 ; i< n*n ; i++)
                suma = suma +tab[i];
            pointer4->pixel_data[i] = suma/(n*n);
        }
   }
free(tab);
}

void minimal_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,3);
    int *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*3 +padding) + t*3; i< j*(a*3+padding)+(a*3+padding)-padding-t*3;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*3+padding) - t*3 + e*3 + d*(a*3+padding)];
            }
            mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[0];
        }
   }
free(tab);
}

void maximal_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4,int n)
{
    int padding = what_padding(pointer2,3);
    int *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(int)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a*3 +padding) + t*3; i< j*(a*3+padding)+(a*3+padding)-padding-t*3;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data[i-t*(a*3+padding) - t*3 + e*3 + d*(a*3+padding)];
            }
            mergeSort(tab, 0, n*n -1);
            pointer4->pixel_data[i] = tab[n*n-1];
        }
   }
free(tab);
}

void grey_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4)
{
    int padding = what_padding(pointer2,3);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++)
    {
        for(int i = j*(a*3 +padding) ; i< j*(a*3+padding)+(a*3+padding)-padding ;i= i + 3)
        {
            int average = (pointer3->pixel_data[i] + pointer3->pixel_data[i+1] + pointer3->pixel_data[i+2])/3;
            pointer4->pixel_data[i] = average;
            pointer4->pixel_data[i+1] = average;
            pointer4->pixel_data[i+2] = average;
        }
   }
}

void negative_24(struct InfoHeader *pointer2,struct data*pointer3,struct data*pointer4)
{
    int padding = what_padding(pointer2,3);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++)
    {
        for(int i = j*(a*3 +padding) ; i< j*(a*3+padding)+(a*3+padding)-padding ;i= i + 3)
        {
            pointer4->pixel_data[i] = 255 - pointer3->pixel_data[i];
            pointer4->pixel_data[i+1] = 255 -pointer3->pixel_data[i+1];
            pointer4->pixel_data[i+2] = 255 - pointer3->pixel_data[i+2];
        }
   }
}

