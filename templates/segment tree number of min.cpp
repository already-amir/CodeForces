
#include <iostream>
#include <vector>

#define migmig 

#define ll long long

using namespace std;
vector<ll> A;
vector<pair<ll, int>>ST;

void build(ll node, ll L, ll R)
{

    if (L == R) {
        ST[node].first = A[L];
        ST[node].second = 1;
    }
    else {

        ll mid = (L + R) / 2;

        build(2 * node, L, mid);

        build(2 * node + 1, mid + 1, R);
        if (ST[2 * node].first < ST[2 * node + 1].first) {
            ST[node].first = ST[2 * node].first;
            ST[node].second = ST[2 * node].second;
        }
        else if (ST[2 * node].first == ST[2 * node + 1].first) {
            ST[node].first = ST[2 * node].first;
            ST[node].second = ST[2 * node].second + ST[2 * node + 1].second;
        }
        else {
            ST[node].first = ST[2 * node + 1].first;
            ST[node].second = ST[2 * node + 1].second;
        }
        
    }
}

void update(ll node, ll L, ll R, ll idx, ll val)
{

    if (L == R) {
        A[idx] = val;
        ST[node].first = val;
        ST[node].second = 1;
    }
    else {

        ll mid = (L + R) / 2;

        if (L <= idx and idx <= mid) {
            update(2 * node, L, mid, idx, val);
        }
        else {
            update(2 * node + 1, mid + 1, R, idx, val);
        }
        

        if (ST[2 * node].first < ST[2 * node + 1].first) {
            ST[node].first = ST[2 * node].first;
            ST[node].second = ST[2 * node].second;
        }
        else if (ST[2 * node].first == ST[2 * node + 1].first) {
            ST[node].first = ST[2 * node].first;
            ST[node].second = ST[2 * node].second + ST[2 * node + 1].second;
        }
        else {
            ST[node].first = ST[2 * node + 1].first;
            ST[node].second = ST[2 * node + 1].second;
        }
    }
}

pair<ll,int> query(ll node, ll tl, ll tr, ll l, ll r)
{


    if (r < tl or tr < l) {
        return { INT_MAX,0 };
    }


    if (l <= tl and tr <= r) {
        return ST[node];
    }

    ll tm = (tl + tr) / 2;
    pair<ll,int> left = query(2 * node, tl, tm, l, r);
    pair<ll, int> right = query(2 * node + 1, tm + 1, tr, l, r);

    if (left.first < right.first) {
        return left;
    }
    if (left.first == right.first) {
        return { left.first,left.second + right.second };
    }
    else {
        return right;
    }
    
}



int main()
{
    
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
        cin >> p >> l >> r;
        if (p == 1) {
            update(1, 0, n - 1, l, r);
        }
        else {
            pair<ll, int>a = query(1, 0, n - 1, l, r - 1);
            cout << a.first<<" "<< a.second<< endl;
        }

    }
}
