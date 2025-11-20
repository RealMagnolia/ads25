#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <int> g[100010];
int c[100010];
bool used[100010];

int main(){
    cin >> n >> m;

    int ans = 0, x, y;
    for(int i = 1 ; i <= m ; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        c[x]++;
    }

    for(int i = 1 ; i <= n ; i++){
        if(!used[i]){
            queue <int> q;
            q.push(i);
            used[i] = true;
            ans++;

            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(int i = 0 ; i < g[v].size() ; i++){
                    int z = g[v][i];
                    if(!used[z]){
                        if(c[v] < c[z]) ans++;
                        used[z] = true;
                        q.push(z);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
