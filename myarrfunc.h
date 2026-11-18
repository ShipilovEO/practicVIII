#ifndef MYARRFUNC_H
#define MYARRFUNC_H

#include <stddef.h>

void menu(void);
int* magnitudo(int magn);
void mass_complementum(int size, int *arith);
void inscripto(int size, const int *arith);
int magis(const int *arith, size_t size, size_t k, size_t m);
double mediocris(const int *arith, size_t size, size_t k, size_t m);
int superior(const int *arith, size_t size, int k);

#endif