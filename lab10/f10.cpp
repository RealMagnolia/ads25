#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <int> g[100010];
bool used[100010];

int main(){
    cin >> n >> m;

    int x, y;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> x >> y;

    queue <int> q;
    q.push(x);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0 ; i < g[v].size() ; i++){
            int z = g[v][i];
            if(!used[z]) {
                used[z] = true;
                q.push(z);
            }
        }
    }

    if(used[y]) cout << "YES";
    else cout << "NO";
    return 0;
}