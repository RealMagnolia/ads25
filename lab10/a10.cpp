#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int ms = 1000;
int g[ms][ms]; 
int d[ms][ms];
bool v[ms][ms];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    cin >> n >> m;

    queue <pair <int, int>> q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> g[i][j];
            d[i][j] = -1;

            if(g[i][j] == 2){
                q.push({i, j});
                d[i][j] = 0;
                v[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!check(nx, ny)) continue;

            if(!v[nx][ny] && g[nx][ny] == 1){
                v[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int mx = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(g[i][j] == 1 && d[i][j] == -1){
                cout << -1;
                return 0;
            }
            mx = max(mx, d[i][j]);
        }
    }
    cout << mx;
    return 0;
}