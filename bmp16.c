#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "Funkcje.h"
//  R5G5B5A0X1
void median_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4, int n)
{
    int padding = what_padding(pointer2, 2 );
    uint16_t *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(uint16_t)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a +padding) + t; i< j*(a+padding)+(a+padding)-padding-t;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data2[i-t*(a+padding) - t + e + d*(a+padding)];
            }
            int R[n*n];
            int G[n*n];
            int B[n*n];
            int A[n*n];
            for(int g =0 ; g<n*n;g++)
            {
             R[g] = ((tab[g] & 0xF800)>>10);
             G[g] = ((tab[g] & 0x3E0)>>5);
             B[g] = (tab[g] & 0x1F);
             A[g] = ((tab[g]&0x1)>>15);
            }
            mergeSort(R, 0, n*n -1);
            mergeSort(G, 0, n*n -1);
            mergeSort(B, 0, n*n -1);
            mergeSort(A, 0, n*n -1);
            int R2 = R[(n*n-1)/2];
            int G2 = G[(n*n-1)/2];
            int B2 = B[(n*n-1)/2];
            int A2 = A[(n*n-1)/2];
            uint16_t S =((R2<<10)|(G2<<5)|(A2<<15)|B2);
            pointer4->pixel_data2[i] = S;
        }
   }
free(tab);
}

void average_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n)
{
    int padding = what_padding(pointer2,2);
    uint16_t *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(uint16_t)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a +padding) + t; i< j*(a+padding)+(a+padding)-padding-t;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data2[i-t*(a+padding) - t + e + d*(a+padding)];
            }
            int R[n*n];
            int G[n*n];
            int B[n*n];
            int A[n*n];
            for(int g =0 ; g<n*n;g++)
            {
             R[g] = ((tab[g] & 0xF800)>>10);
             G[g] = ((tab[g] & 0x3E0)>>5);
             B[g] = (tab[g] & 0x1F);
             A[g] = ((tab[g]&0x1)>>15);
            }
            int sumaR=0;
            int sumaG=0;
            int sumaB=0;
            int sumaA=0;
            for(int v = 0 ; v< n*n ; v++)
            {
                sumaR= sumaR +R[v];
                sumaG= sumaG +G[v];
                sumaB= sumaB +B[v];
                sumaA= sumaA +A[v];
            }
            sumaR= sumaR/(n*n);
            sumaG= sumaG/(n*n);
            sumaB= sumaB/(n*n);
            sumaA= sumaA/(n*n);
            uint16_t S =(sumaR<<10)|(sumaG<<5)|(sumaA<<15)|(sumaB);
            pointer4->pixel_data2[i] = S;
        }
   }
free(tab);
}

void minimal_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n)
{
    int padding = what_padding(pointer2,2);
    uint16_t *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(uint16_t)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a +padding) + t; i< j*(a+padding)+(a+padding)-padding-t;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data2[i-t*(a+padding) - t + e + d*(a+padding)];
            }
            int R[n*n];
            int G[n*n];
            int B[n*n];
            int A[n*n];
            for(int g =0 ; g<n*n;g++)
            {
             R[g] = ((tab[g] & 0xF800)>>10);
             G[g] = ((tab[g] & 0x3E0)>>5);
             B[g] = (tab[g] & 0x1F);
             A[g] = ((tab[g]&0x1)>>15);
            }
            mergeSort(R, 0, n*n -1);
            mergeSort(G, 0, n*n -1);
            mergeSort(B, 0, n*n -1);
            mergeSort(A, 0, n*n -1);
            int R2 = R[0];
            int G2 = G[0];
            int B2 = B[0];
            int A2 = A[0];
            uint16_t S =((R2<<10)|(G2<<5)|(A2<<15)|B2);
            pointer4->pixel_data2[i] = S;
        }
   }
free(tab);
}

void maximal_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4,int n)
{
    int padding = what_padding(pointer2,2);
    uint16_t *tab;
    
    int a = pointer2->width;
    int b = pointer2->height;
    int t = (n-1)/2;
    tab = malloc(sizeof(uint16_t)*n*n);
    for(int j=t;j<b-t+1;j++)
    {
        for(int i = j*(a +padding) + t; i< j*(a+padding)+(a+padding)-padding-t;i++)
        {
            for(int d = 0 ; d< n ; d++)
            {
                for(int e = 0 ; e<n ; e++)
                    tab[e+n*d] = pointer3->pixel_data2[i-t*(a+padding) - t + e + d*(a+padding)];
            }
            int R[n*n];
            int G[n*n];
            int B[n*n];
            int A[n*n];
            for(int g =0 ; g<n*n;g++)
            {
             R[g] = ((tab[g] & 0xF800)>>10);
             G[g] = ((tab[g] & 0x3E0)>>5);
             B[g] = (tab[g] & 0x1F);
             A[g] = ((tab[g]&0x1)>>15);
            }
            mergeSort(R, 0, n*n -1);
            mergeSort(G, 0, n*n -1);
            mergeSort(B, 0, n*n -1);
            mergeSort(A, 0, n*n -1);
            int R2 = R[(n*n)-1];
            int G2 = G[(n*n)-1];
            int B2 = B[(n*n)-1];
            int A2 = A[(n*n)-1];
            uint16_t S =((R2<<10)|(G2<<5)|(A2<<15)|B2);
            pointer4->pixel_data2[i] = S;
        }
   }
free(tab);
}

void grey_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4)
{
    int padding = what_padding(pointer2,2);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++) 
    {
        for(int i = j*(a +padding) ; i< j*(a+padding)+(a+padding)-padding ;i= i +1) 
        {
            uint16_t  tab[1];
            tab[0] = pointer3->pixel_data2[i];
            int R = ((tab[0] & 0xF800)>>10);
            int G = ((tab[0] & 0x3E0)>>5);
            int B = (tab[0] & 0x1F);
            int A = ((tab[0]&0x1)>>15);
            int average = (R+G+B)/3;
          //  printf("%i, %i, %i,%i, %i\n",R,G,B,A,average);
            R = average;
            G = average;
            B = average;

            tab[0]=((R<<10)|(G<<5)|(A<<15)|B);
         //   printf("%i, %i, %i, %i , %i\n",R,G,B,tab[0],tab[1]);
            pointer4->pixel_data2[i] = tab[0];

        }
   }
}

void negative_16(struct InfoHeader *pointer2,struct data2*pointer3,struct data2*pointer4)
{
    int padding = what_padding(pointer2,2);
    int a = pointer2->width;
    int b = pointer2->height;
    for(int j=0;j<b;j++)
    {
        for(int i = j*(a +padding) ; i< j*(a+padding)+(a+padding)-padding ;i= i + 1)
        {
            uint16_t  tab[1];
            tab[0] = pointer3->pixel_data2[i];
            int R = ((tab[0] & 0xF800)>>10);
            int G = ((tab[0] & 0x3E0)>>5);
            int B = (tab[0] & 0x1F);
            int A = ((tab[0]&0x1)>>15);
            R = 31 - R;
            G = 31 - G;
            B = 31 - B;
            tab[0]=((R<<10)|(G<<5)|(A<<15)|B);
            pointer4->pixel_data2[i] = tab[0];
        }
   }
}
