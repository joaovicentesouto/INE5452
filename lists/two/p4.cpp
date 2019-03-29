#include <iostream>
 
using namespace std;
 
int divisor(int *vector, int left_pivot, int right)
{
    int swap;
    int i = left_pivot;
 
    for(int x = left_pivot + 1; x <= right; x++)
        if(vector[x] < vector[left_pivot])
        {
            i++;
            swap = vector[x];
            vector[x] = vector[i];
            vector[i] = swap;
        }
 
    swap = vector[left_pivot];
    vector[left_pivot] = vector[i];
    vector[i] = swap;
 
    return i;
}
 
void quick_sort(int* vector, int left, int right)
{
    if(right > left)
    {
        int pivot = divisor(vector, left, right);
        quick_sort(vector, left, pivot - 1);
        quick_sort(vector, pivot + 1, right);
    }
}
 
int main ()
{
    int n = 0;
    cin >> n;
 
    int even[n];
    int odd[n];
     
    for (int x = 0; x < n; x++)
    {
        even[x] = 0;
        odd[x] = 0;
    }
 
    int even_size = 0;
    int odd_size = 0;
 
    while(n--)
    {
        int number;
        cin >> number;
 
        if (number % 2)
            odd[odd_size++] = number;
        else
            even[even_size++] = number;
    }
 
    quick_sort(even, 0, even_size - 1);
    quick_sort(odd, 0, odd_size - 1);
 
    for (int x = 0; x < even_size; x++)
        cout << even[x] << endl;
 
    for (int x = odd_size - 1; x >= 0; x--)
        cout << odd[x] << endl;
 
    return 0;
}