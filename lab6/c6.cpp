#include <iostream>
#include <vector>
using namespace std;

void quick(vector <int> &a, int l, int r){
    int p = a[(l+r)/2];
    int i = l, j = r;

    while(i < j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main(){
    vector <int> a;
    int n; cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        a.push_back(x);
    } quick(a, 0, n-1);

    vector <pair <int, int>> abs;
    abs.push_back(make_pair(a[0], a[1]));

    for(int i = 1 ; i < n-1 ; i++){
        int f = a[i] , s = a[i+1];
        if(abs.size() == 0) abs.push_back(make_pair(f, s));

        while(!abs.empty()){
            if(abs[abs.size()-1].second - abs[abs.size()-1].first > s-f) abs.pop_back();
            if(abs[abs.size()-1].second - abs[abs.size()-1].first == s-f){
                abs.push_back(make_pair(f, s));
                break;
            }
            if(abs[abs.size()-1].second - abs[abs.size()-1].first < s-f) break;
        }

        if(abs.size() == 0) abs.push_back(make_pair(f, s));
    }

    for(int i = 0 ; i < abs.size() ; i++){
        cout << abs[i].first << " " << abs[i].second << " ";
    }
    return 0;
}