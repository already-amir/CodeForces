
#include <iostream>
#include <vector>

#define migmig 

using namespace std;

vector<int>arr(1000);
vector<int>seg(4000);


void build(int index, int low, int high) {
    if (low == high) {
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int query(int index, int low, int high, int l, int r) {

    if (low >= l && high <= r) {
        return seg[index];
    }
    else if (high<l || low>r) {
        return 0;
    }
    else {
        int mid = (low + high) / 2;
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return left + right;

    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l, r;
        cout << query(0, 0, n - 1, l, r)<<endl;
    }
}
