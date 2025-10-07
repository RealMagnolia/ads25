#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
    public:
    vector <long long> a;

    long long parent(long long i) {return (i-1)/2;}
    long long left(long long i) {return 2*i+1;}
    long long right(long long i) {return 2*i+2;}
    long long getMax() {return a[0];}

    void insert(long long k){
        a.push_back(k);
        long long ind = a.size()-1;

        while(ind > 0 && a[ind] > a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(long long i){
        if(left(i) > a.size()-1) return;
        long long j = left(i);

        if(right(i) < a.size() && a[right(i)] > a[left(i)]) j = right(i);
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractMax(){
        long long root = getMax();
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0) heapify(0);
        return root;
    }

    long long tickets(long long x, long long sum){
        while(x--){
            long long max1 = extractMax();
            long long diff = max1-1;
            sum+=max1;
            insert(diff);
        }
        return sum;
    }
};

int main(){
    maxHeap *heap = new maxHeap;
    long long n, x;
    cin >> n >> x;

    for(long long i = 0 ; i < n ; i++){
        long long a; cin >> a;
        heap->insert(a);
    }
    long long sum = 0;
    cout << heap->tickets(x, sum);
    return 0;
}
