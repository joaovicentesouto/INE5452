#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

template<typename T, typename L> void fib(uint16_t &vec[10000000000000000])
{
    vec[T] = (vec[T-1] + vec[T-2]) % 1000;
    
    if (T < L)
        fib<T+1, L>(vec);
}
 
int main ()
{
    uint16_t vec[10000000000000000];
    size_t T, times = 2;
    size_t fib[3] = {0, 1, 0};

    fib<2, 10000000000000000>(vec);

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