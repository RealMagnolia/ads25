#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int g[100][100];
queue <int> q;

int bfs(int n, int s, int t){
    vector <bool> v(n, false);
    vector <int> d(n, -1);

    v[s] = true;
    d[s] = 0;
    q.push(s);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == t) return d[x];

        for(int i = 0 ; i < n ; i++){
            if(g[x][i] == 1 && !v[i]){
                v[i] = true;
                d[i] = d[x] + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> g[i][j];
        }
    }
    int s, t;
    cin >> s >> t;

    cout << bfs(n, s-1, t-1);
    return 0;
}