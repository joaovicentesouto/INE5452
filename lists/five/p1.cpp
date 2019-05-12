#include <iostream>
#include <vector>
 
using namespace std;
 
int main ()
{
    size_t T, times = 2;
    size_t fib[3] = {0, 1, 0};

    int m = 0;
    int n = 1;
    int l = 2;
     
    cin >> T;
 
    while (T--)
    {
        size_t K;
 
        cin >> K;
 
        while (times <= K)
        {
            fib[l] = ((fib[m] + fib[n]) % 1000);

            m = (m + 1) % 3;
            n = (n + 1) % 3;
            l = (l + 1) % 3;
            times++;
        }
 
        if (fib[n] < 100)
            cout << "0";
        
        if (fib[n] < 10)
            cout << "0";
        
        cout << fib[n] << endl;
    }
 
    return 0;
}