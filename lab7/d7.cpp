#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct st{
    string sn, n;
    double gpa;
};

bool sort(st n1, st n2){
    if(n1.gpa != n2.gpa) return n1.gpa < n2.gpa;
    if(n1.sn != n2.sn) return n1.sn < n2.sn;
    else return n1.n < n2.n;
}

void merge(vector <st> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector <st> L(n1), R(n2);
    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2 ; j++) R[j] = a[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(sort(L[i], R[j])){
            a[k] = L[i];
            i++;
        } else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = L[i];
        i++; k++;
    }
    while (j < n2){
        a[k] = R[j];
        j++; k++;
    }
    
}

void mergeS(vector <st> &a, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;

        mergeS(a, l, m);
        mergeS(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main(){
    vector <st> a;
    long long n; cin >> n;

    for(int i = 0 ; i < n ; i++){
        string sn, n;
        int m; cin >> sn >> n >> m;

        long long creds = 0;
        double gpas = 0;
        for(int j = 1 ; j <= m ; j++){
            string s; int x;
            cin >> s >> x;
            if(s == "A+") gpas += (4.0 * x);
            if(s == "A") gpas += (3.75 * x);
            if(s == "B+") gpas += (3.5 * x);
            if(s == "B") gpas += (3.0 * x);
            if(s == "C+") gpas += (2.5 * x);
            if(s == "C") gpas += (2.0 * x);
            if(s == "D+") gpas += (1.5 * x);
            if(s == "D") gpas += (1.0 * x);
            if(s == "F") gpas += (0 * x);
            creds += x;
        } double gpa = gpas/(double)creds;

        st fio;
        fio.n = n; fio.sn = sn; fio.gpa = gpa;
        a.push_back(fio);
    }

    mergeS(a, 0, a.size()-1);
    cout << fixed << setprecision(3);
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i].sn << " " << a[i].n << " " << a[i].gpa << endl;
    }

    return 0;
}