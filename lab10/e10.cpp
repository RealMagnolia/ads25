#include <iostream>
using namespace std;

int g[1000][1000];
int n, q;

int main(){
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> g[i][j];
        }
    }

    for(int i = 0 ; i < q ; i++){
        int e1, e2, e3;
        cin >> e1 >> e2 >> e3;

        e1--; e2--; e3--;
        if(g[e1][e2] == 1 && g[e1][e3] == 1 && g[e2][e3] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}