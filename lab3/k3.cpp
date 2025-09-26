#include <iostream>
#include <vector>
using namespace std;
int main() {


    int n, k;
    cin >> n >> k;
    int numbers[n], pref[n+1];

    pref[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        numbers[i] =  t;
        pref[i] = pref[i-1] + numbers[i];

    }


    
    int left = 1, right = n;
    while (left + 1 < right)
    {
        int mid = left + (right-left)/2;
        bool ok = false;

        for (int i = 1; i <= n - mid + 1; i++)
        {
            if(pref[i+mid-1] - pref[i] >= k) ok = true; 
        }

        if(ok) right = mid;
        else left = mid;
    }
    cout << left;
    


    return 0;
}