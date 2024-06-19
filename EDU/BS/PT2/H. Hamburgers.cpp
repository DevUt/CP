#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <limits>
#include <numeric>
// #pragma GCC target("fpmath=387")
// Use some pragma optimizations
#pragma GCC target(                                                            \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("tree-vectorize") // DO NOT USE ON USACO
// #pragma GCC optimize("Ofast")
// #define SLOWIO
// Shotern long variable names
#define ull unsigned long long
#define ll long long
#define ldb long double
#define MOD 1000000007
// Operations on bits
#define popcnt(x) __builtin_popcount(x)
#define popcntll(x) __builtin_popcountll(x)
#define trailz(x) __builtin_ctz(x)
#define trailzll(x) __builtin_ctzll(x)
#define leadz(x) __builtin_clz(x) // REMEMBER THE X SHOULD BE UNSIGNED
#define leadzll(x) __builtin_clzll(x)
#define oddparity(x) __builtin_parity(x)

// The namespaces
using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define uniq(x) x.erase(unique(all(x)), x.end());
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
  for (auto &i : v)
    os << i << ' ';
  return os;
}
template <typename T, size_t sz>
istream &operator>>(istream &is, array<T, sz> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, array<T, sz> v) {
  for (auto &i : v)
    os << i << ' ';
  return os;
}

template <class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;

template <typename I> struct _reversed_struct {
  I &v_;
  explicit _reversed_struct(I &v) : v_{v} {}
  typename I::reverse_iterator begin() const { return v_.rbegin(); }
  typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I> _reversed_struct<I> reversed(I &v) {
  return _reversed_struct<I>(v);
}
template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }
template <typename T, typename P> T cceil(const T &a, const P &b) {
  ll x = a, y = b;
  return (x + y - 1) / y;
}
template <typename T, typename P> T cfloor(const T &a, const P &b) {
  ll n = a, d = b;
  return n >= 0 ? n / d : -1 - (-1 - n) / d;
}

void solve(int test_case) {
    string receipe; cin>>receipe;
    ll rb = count(all(receipe),'B');
    ll rs = count(all(receipe),'S');
    ll rc = count(all(receipe), 'C');
    ll nb,ns,nc; cin>>nb>>ns>>nc;
    ll pb,ps,pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;

    auto check = [&](ll burgers) {
        if(burgers < 0)
                return true;
        ll withoutBuying = numeric_limits<ll>::max();
        if(rs)
            ckmin(withoutBuying, ns/rs);
        if(rb)
            ckmin(withoutBuying, nb/rb);
        if(rc)
            ckmin(withoutBuying, nc/rc);
        ll copyr = r;
        if(withoutBuying >= burgers)
            return true;
        ll more = burgers - withoutBuying;
        ll moreBread = more*rb;
        copyr -= max(0ll,moreBread-(nb-rb*withoutBuying))*pb;
        ll moreSausage = more*rs;
        copyr -= max(0ll, moreSausage-(ns - rs*withoutBuying))*ps;
        ll moreCheese = more*rc;
        copyr -= max(0ll, moreCheese - (nc -rc*withoutBuying))*pc;
        return copyr >= 0;
    };

    ll l =-1,h=1e13;

    while(l+1 < h){
        ll mid = std::midpoint(l,h);
        if(check(mid))
            l = mid;
        else
            h = mid;
    }
    cout<<l;
  // cout<<"Case #"<<test_case<<": ";
}

int32_t main() {
#ifndef SLOWIO
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif
  // DON"T DO THE STRING STREAM STUFF

#ifndef UTKARSH_LOCAL
// freopen("problemname.in", "r", stdin);
// // the following line creates/overwrites the output file
// freopen("problemname.out", "w", stdout);
#endif
  int test_case = 1;
  //cin >> test_case;
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
