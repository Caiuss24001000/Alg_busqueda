// C program for Fibonacci Search
#include <stdio.h>
 
// Utility function to find minimum of two elements
int min(int x, int y) { return (x <= y) ? x : y; }
 
/* Returns index of x if present,  else returns -1 */
int fibMonaccianSearch(int arr[], int x, int n)
{
    /* Initialize fibonacci numbers */
    int fibNum1 = 0; // (m-2)'th Fibonacci No.
    int fibNum2 = 1; // (m-1)'th Fibonacci No.
    int fibNum3 = fibNum1 + fibNum2; // m'th Fibonacci
 
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibNum3 < n) {
        fibNum1 = fibNum2;
        fibNum2 = fibNum3;
        fibNum3 = fibNum2 + fibNum1;
    }
 
    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibNum3 > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibNum1, n - 1);
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (arr[i] < x) {
            fibNum3 = fibNum2;
            fibNum2 = fibNum1;
            fibNum1 = fibNum3 - fibNum2;
            offset = i;
        }
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (arr[i] > x) {
            fibNum3 = fibNum1;
            fibNum2 = fibNum2 - fibNum1;
            fibNum1 = fibNum3 - fibNum2;
        }
 
        /* element found. return index */
        else
            return i;
    }
 
    /* comparing the last element with x */
    if (fibNum2 && arr[offset + 1] == x)
        return offset + 1;
 
    /*element not found. return -1 */
    return -1;
}
 
/* driver function */
int main(void)
{
    int arr[] = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 235;
      int ind = fibMonaccianSearch(arr, x, n);
  if(ind>=0)
    printf("Found at index: %d",ind);
  else
    printf("%d isn't present in the array",x);
    return 0;
}