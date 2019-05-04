/******************************************************************************

                Maximum sum such that no two elements are adjacent

*******************************************************************************/

#include <stdio.h>

using namespace std;


int FindMaxSum(int arr[], int n) 
{ 
  int incl = arr[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  
  for (i = 1; i < n; i++) 
  { 
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl; 
  
     /* current max including i */
     incl = excl + arr[i]; 
     excl = excl_new; 
  } 
  
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl); 
} 

int main()
{
    int arr[] = {1, 2, 3, 4,5}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  printf("%d n", FindMaxSum(arr, n)); 
  return 0; 
}