#include "Problems.h"

// A utility function that returns maximum of two integers
int Problems::max(int a, int b){ return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W 
int Problems::knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 

// Returns true if there is a subset of set[] with sun equal to given sum
bool Problems::isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a  
    // subset of set[0..j-1] with sum equal to i 
    bool subset[n+1][sum+1]; 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
   
     /*   // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }*/
   
     return subset[n][sum]; 
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
int Problems::MatrixChainOrder(int p[], int n) 
{ 
  
    /* For simplicity of the program, one extra row and one 
       extra column are allocated in m[][].  0th row and 0th 
       column of m[][] are not used */
    int m[n][n]; 
  
    int i, j, k, L, q; 
  
    /* m[i, j] = Minimum number of scalar multiplications needed 
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where 
       dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying one matrix. 
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L < n; L++) { 
        for (i = 1; i < n - L + 1; i++) { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
}