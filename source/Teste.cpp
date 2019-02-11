#include "Teste.h"
#include "Problems.h"

// Objeto da classe Problems
Problems p;

void Teste::tKnapSack()
{
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", p.knapSack(W, wt, val, n)); 
}

void Teste::tMatrixChainOrder()
{
    int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d ", p.MatrixChainOrder(arr, size)); 
}

void Teste::tSubsetSum()
{
    int set[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9; 
    int n = sizeof(set)/sizeof(set[0]); 
    if (p.isSubsetSum(set, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
}