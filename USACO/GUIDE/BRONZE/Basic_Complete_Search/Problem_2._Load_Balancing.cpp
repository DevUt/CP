#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
  int n;
  cin >> n;
  struct point {
    int x, y;
    int id;
  };
  vector<point> cow(n);
  for (size_t i = 0; i < n; i++) {
    cin >> cow[i].x >> cow[i].y;
    cow[i].id = i;
  }

  vector<point> cowx = cow, cowy = cow;
  sort(all(cowx),
       [](const struct point &a, const struct point &b) { return a.x < b.x; });
  sort(all(cowy),
       [](const struct point &a, const struct point &b) { return a.y < b.y; });

  size_t ans = INT_MAX;

  for (int i = 0; i < n; i++) {
    vector<point> above, below;
    for(int j=0; j<n; j++){
        if(cowx[j].y <= cowy[i].y)
            below.push_back(cowx[j]);
        else
         above.push_back(cowx[j]);
    }

    size_t aboveIdx = 0;
    size_t belowIdx = 0;

    while(aboveIdx < above.size() || belowIdx < below.size()){
        int xBorder = INT_MAX;
        if(aboveIdx < above.size())
            ckmin(xBorder, above[aboveIdx].x);
        if(belowIdx < below.size())
            ckmin(xBorder, below[belowIdx].x);

        while(belowIdx < below.size() && below[belowIdx].x  == xBorder)
            belowIdx++;
        while(aboveIdx < above.size() && above[aboveIdx].x == xBorder)
            aboveIdx++;

        ckmin(ans,max({aboveIdx, above.size()-aboveIdx,belowIdx, below.size()-belowIdx}));
    }
  }
  cout << ans;
  // cout<<"Case #"<<test_case<<": ";
}

int32_t main() {
#ifndef SLOWIO
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif
  // DON"T DO THE STRING STREAM STUFF

#ifndef UTKARSH_LOCAL
  freopen("balancing.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("balancing.out", "w", stdout);
#endif
  int test_case = 1;
  // cin >> test_case;
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
