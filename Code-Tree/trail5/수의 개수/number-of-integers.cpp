#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int lbound(int num){
    int left = 0, right = n - 1;
    int min_idx = n;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] >= num){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int ubound(int num){
    int left = 0, right = n - 1;
    int min_idx = n;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] > num){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int get_count(int num){
    int lb_val = lbound(num);
    int ub_val = ubound(num);
    return ub_val - lb_val;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int val = get_count(x);
        cout << val << "\n";
    }

    return 0;
}
