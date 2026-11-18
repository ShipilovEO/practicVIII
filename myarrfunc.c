#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

int* magnitudo(int magn)
{
    int* arith = malloc(magn * sizeof(int));
    return arith;
}

void menu(void)
{
        printf("\t\t### МЕНЮ ###\n");
        printf("a — Задать размер массива\nb — Заполнить массив\nc — Представление массива (значения, адреса)\n");
        printf("d — Определение максимального значения массива в заданном диапазоне индексов k – m\n");
        printf("e — Вычисление среднего арифметического элементов в заданном диапазоне индексов k–m\n");
        printf("f — Определение количества элементов массива по значению выше введенного k\n");
        printf("g — Выход\nВыберите пункт: ");
}
void mass_complementum(int size, int *arith)
{
    if (arith == NULL)
    {
        printf("!!!ВНИМАНИЕ!!!\tДля начала стоит задать размер массива\n");
        return;
    }
    printf("если хотите вводить сами нажмите - 1\nесли хотите воспользоваться автовводом нажмите - 2\n");
    int n = 0;
    while(scanf("%d", &n) == 1)
    {

        if (n == 1)
        {
            printf("вводите по одному числу и после каждого введенного числа нажимайте клавишу 'enter'\n");
            int i = 0;
            int m = 0;
            for (i = 0; i < size; i ++)
            {
                scanf("%d", &m);
                *(arith + i) = m;
            }
            break;
        }
        else if (n == 2)
        {
            int j = 0;
            for (j = 0; j < size; j++)
            {
                *(arith + j) = j;
            }
            break;
        }
        else
        {
            printf("просим вводить коректные значения из списка\n");
            
        }
    }
}
void inscripto(int size, const int *arith)
{
    if (arith == NULL)
    {
        printf("!!!ВНИМАНИЕ!!!\tДля начала стоит задать размер массива\n");
        return;
    }
    int j = 0;
    for (j = 0; j < size; j++)
    {
        printf("%d  %p\n", *(arith + j), (void *)(arith + j));
    }
}

int magis(const int *arith, size_t size, size_t k, size_t m)
{
    if (arith == NULL)
    {
        printf("!!!ВНИМАНИЕ!!!\tДля начала стоит задать размер массива\n");
        return -1;
    }
    if (k < size && m < size && k <= m)
    {
        int max_mass = *(arith + k);

        for(size_t l = k; l <= m; l++)
        {
            if (*(arith + l) > max_mass)
            {
                max_mass = *(arith + l);
            }
        }
        return max_mass;
    }
    return -1;
}

double mediocris(const int *arith, size_t size, size_t k, size_t m)
{
    if (arith == NULL)
    {
        printf("!!!ВНИМАНИЕ!!!\tДля начала стоит задать размер массива\n");
        return -1;
    }
    if (k < size && m < size && k <= m)
    {
        int summ_all = 0;
        for(size_t l = k; l <= m; l++)
        {
            summ_all += *(arith + l);
        }
        double sr_arif = (double)summ_all / (m - k + 1);
        return sr_arif;
    }
    return -1;
}

int superior(const int *arith, size_t size, int k)
{
    int better = 0;
    if (arith == NULL)
    {
        printf("!!!ВНИМАНИЕ!!!\tДля начала стоит задать размер массива\n");
        return -1;
    }
    for(size_t l = 0; l < size; l++)
    {
        if (*(arith + l) > k)
        {
            better += 1;
        }
    }
    return better;
}