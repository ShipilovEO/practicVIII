#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"


int main(void)
{
    char move;
    size_t k = 0, m = 0;
    size_t k2 = 0, m2 = 0;
    int k3 = 0;
    int *massiv = NULL;
    int flg = 0;
    int size = 0;
    menu();
    while(scanf(" %c", &move) == 1 && move != 'g')
    {
        switch(move)
        {
            case 'a':
                printf("Задайте размер массива, любое целое положительное число\n");
                if (scanf("%d", &size) == 1 && size > 0)
                {
                    free(massiv);
                    massiv = magnitudo(size);
                    flg = 0;
                }
                else
                {
                    printf("!!!ВНИМАНИЕ!!! некорректный размер\n");
                    size = 0;
                }
                break;
            
            case 'b':
                if (massiv == NULL)
                {
                    printf("!!!ВНИМАНИЕ!!!\tСначала задайте размер массива (пункт a)\n");
                }
                else
                {
                    mass_complementum(size, massiv);
                    flg = 1;
                }
                break;

            case 'c':
                if (flg == 0)
                {
                    printf("!!!ВНИМАНИЕ!!!\tДля начала стоит заполнить массив(пункт b)\n");
                    break;
                }
                else
                {
                    inscripto(size, massiv);
                    break;
                }

            case 'd':
                if (flg == 0)
                {
                    printf("!!!ВНИМАНИЕ!!!\tДля начала стоит заполнить массив(пункт b)\n");
                    break;
                }
                else 
                {
                    printf("задайте целое неотрицательное значение k и m через пробел:\n");
                    if (scanf("%zu %zu", &k, &m) == 2)
                    {
                        int max_mass = magis(massiv, size, k, m);
                        printf("%d\n", max_mass);
                    }
                    break;
                }

            case 'e':
                if (flg == 0)
                {
                    printf("!!!ВНИМАНИЕ!!!\tДля начала стоит заполнить массив(пункт b)\n");
                    break;
                }
                else 
                {
                    printf("задайте целое неотрицательное значение k и m через пробел:\n");
                    if (scanf("%zu %zu", &k2, &m2) == 2)
                    {
                        double sr_arifm = mediocris(massiv, size, k2, m2);
                        printf("%.4f\n", sr_arifm);
                    }
                    break;
                }
            
            case 'f':
                if (flg == 0)
                {
                    printf("!!!ВНИМАНИЕ!!!\tДля начала стоит заполнить массив(пункт b)\n");
                    break;
                }
                else
                {        
                    printf("задайте целое значение k: \n");
                    if (scanf("%d", &k3) == 1)
                    {
                        int better_them_k = superior(massiv, size, k3);
                        printf("%d\n", better_them_k);
                    }
                    break;
                }
            
            default:
                printf("неизвестная команда, попробуйте другую из списка!!!\n");
                break;
        }
        menu();
    }
    free(massiv);
    return 0;



}