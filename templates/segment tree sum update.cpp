
#include <iostream>
#include <vector>

#define migmig 

#define ll long long

using namespace std;
vector<ll> A, ST;

void build(ll node, ll L, ll R)
{

    if (L == R) {
        ST[node] = A[L];
    }
    else {

        ll mid = (L + R) / 2;

        build(2 * node, L, mid);

        build(2 * node + 1, mid + 1, R);

        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}

void update(ll node, ll L, ll R, ll idx, ll val)
{

    if (L == R) {
        A[idx] = val;
        ST[node] = val;
    }
    else {

        ll mid = (L + R) / 2;

        if (L <= idx and idx <= mid) {
            update(2 * node, L, mid, idx, val);
        }
        else {
            update(2 * node + 1, mid + 1, R, idx, val);
        }
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}

ll query(ll node, ll tl, ll tr, ll l, ll r)
{


    if (r < tl or tr < l) {
        return 0;
    }
       

    if (l <= tl and tr <= r) {
        return ST[node];
    }
     
    ll tm = (tl + tr) / 2;
    ll left = query(2 * node, tl, tm, l, r);
    ll right = query(2 * node + 1, tm + 1, tr, l, r);
    return left + right;
}



int main()
{
    //https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
    ll n, k;
    cin >> n >> k;
    ST.resize(4 * n);
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    build(1, 0, n - 1);

  
    while (k--) {
        ll p, l, r;
        cin >> p >> l>> r;
        if (p == 1) {
            update(1, 0, n - 1, l, r);
        }
        else {
            cout << query(1, 0, n - 1, l, r-1) << endl;
        }
        
    }
}
