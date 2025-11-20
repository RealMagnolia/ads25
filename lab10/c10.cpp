#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    int mx = b*2 + 5;

    vector <int> d(mx, -1);
    vector <int> p(mx, -1);
    queue <int> q;

    if(a > b){
        cout << a - b << endl;
        for(int i = a - 1 ; i >= b ; i--) cout << i << " ";
        return 0;
    }

    d[a] = 0;
    q.push(a);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == b) break;

        int u1 = x*2, u2 = x - 1;
        if(u1 < mx && d[u1] == -1) {
            p[u1] = x;
            d[u1] = d[x] + 1;
            q.push(u1);
        }

        if(u2 >= 0 && d[u2] == -1){
            p[u2] = x;
            d[u2] = d[x] + 1;
            q.push(u2);
        }
    }

    vector <int> result;
    int t = b;
    while(t != -1){
        result.push_back(t);
        t = p[t];
    }
    reverse(result.begin(), result.end());
    cout << result.size()-1 << endl;

    for(int i = 1 ; i < result.size() ; i++){
        cout << result[i] << " ";
    }
    return 0;
}