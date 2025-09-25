#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, sum = 0;
    cin >> n >> m;

    vector <int> p;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        sum += a;
        p.push_back(sum);
    }

    while(m--){
        int mis; cin >> mis;
        int l = 0, r = n-1, ans = -1;
        while(l <= r){
            int h = l + (r - l)/2;
            if(p[h] >= mis) {
                r = h - 1;
                ans = h;
            }
            else l = h + 1;
        }

        cout << ans + 1 << endl;
    }

    return 0;
}