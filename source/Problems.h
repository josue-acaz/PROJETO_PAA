#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <limits.h>

class Problems{
    public:
        // FUNÇÃO AUXILIAR
        int max(int a, int b);

        // PROBLEMAS
        int knapSack(int c, int p[], int v[], int n);
        bool isSubsetSum(int set[], int n, int sum);
        int MatrixChainOrder(int p[], int n);
};

#endif