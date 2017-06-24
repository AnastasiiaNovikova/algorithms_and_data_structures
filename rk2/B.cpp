//В - Унимодальный массив

#include <iostream>

using namespace std;

void getelem (int *a, int l, int r) {
    int m = (r-l)/2 + l;
    if (a[m-1] < a[m] && a[m] < a[m+1]) getelem(a, m, r);
    if (a[m-1] > a[m] && a[m] > a[m+1]) getelem(a, l, m);
    if (a[m-1] < a[m] && a[m] > a[m+1]){
        cout<<a[m];
        return;
    };
    return;
};

int main () {
    int N;
    cin >> N;
    
    int *arr= new int[N];
    
    for (int i=0; i<N; i++) cin >> arr[i];
    getelem(arr, 0, N-1);
    
    return 0;
}

