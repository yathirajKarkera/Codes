/******************************************************************************

                            Maximum path sum in matrix

*******************************************************************************/

#include <iostream>

using namespace std;


int findMaxPath(int mat[3][3]) 
{ 
    int N = 3;
    int M = 3;
    
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
  
            // When all paths are possible 
            if (j > 0 && j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                             max(mat[i - 1][j - 1],  
                             mat[i - 1][j + 1])); 
  
            // When diagonal right is not possible 
            else if (j > 0) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j - 1]); 
  
            // When diagonal left is not possible 
            else if (j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j + 1]); 
  
            // Store max path sum 
        } 
    } 
    int res = 0; 
    for (int j = 0; j < M; j++)  
        res = max(mat[N-1][j], res); 
    return res; 
} 


int main()
{
    int mat1[3][3] = { 
                        { 1, 2, 4 }, 
                        { 4, 2, 2 }, 
                        { 7, 2, 2 }
                    }; 
              
    cout << findMaxPath(mat1) << endl; 
    return 0; 
}