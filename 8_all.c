#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int* magnitudo(int magn);
void mass_complementum(int size, int *arith);
void inscripto(int size, const int *arith);
int magis(const int *arith, size_t size, size_t k, size_t m);
double mediocris(const int *arith, size_t size, size_t k, size_t m);
int superior(const int *arith, size_t size, int k);

int main(void)
{
    int size;
    if (scanf("%d", &size) == 1 && size > 0)
    {
        int* massiv = magnitudo(size);
        if (massiv != NULL)
        {
            mass_complementum(size, massiv);
            //printf("%d", massiv[0]);
            inscripto(size, massiv);
            size_t k = 0, m = 0;
            size_t k2 = 0, m2 = 0;
            int k3 = 0;
            if (scanf("%zu %zu", &k, &m) == 2)
            {
                int max_mass = magis(massiv, size, k, m);
                printf("%d\n", max_mass);

            }
            if (scanf("%zu %zu", &k2, &m2) == 2)
            {
                double sr_arifm = mediocris(massiv, size, k2, m2);
                printf("%.4f\n", sr_arifm);
            }

            if (scanf("%d", &k3) == 1)
            {
                int better_them_k = superior(massiv, size, k3);
                printf("%d\n", better_them_k);
            }
            free(massiv);
        }
    }




    return 0;
}

int* magnitudo(int magn)
{
    int* arith = malloc(magn * sizeof(int));
    return arith;
}


void mass_complementum(int size, int *arith)
{
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
    int j = 0;
    for (j = 0; j < size; j++)
    {
        printf("%d  %p\n", *(arith + j), (void *)(arith + j));
    }
}

int magis(const int *arith, size_t size, size_t k, size_t m)
{
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

    for(size_t l = 0; l < size; l++)
    {
        if (*(arith + l) > k)
        {
            better += 1;
        }
    }
    return better;
}