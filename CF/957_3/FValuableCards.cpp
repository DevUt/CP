#include <bits/stdc++.h>
// #pragma GCC target("fpmath=387")
// Use some pragma optimizations
#pragma GCC target(                                                            \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("tree-vectorize") // DO NOT USE ON USACO
// #pragma GCC optimize("Ofast")
// #define SLOWIO
// Shotern long variable names
using ull = unsigned long long;
using ll = long long;
using ldb = long double;
#define MOD 1000000007
// Operations on bits
#define popcnt(x) __builtin_popcount(x)
#define popcntll(x) __builtin_popcountll(x)
#define trailz(x) __builtin_ctz(x)
#define trailzll(x) __builtin_ctzll(x)
#define leadz(x) __builtin_clz(x) // REMEMBER THE X SHOULD BE UNSIGNED
#define leadzll(x) __builtin_clzll(x)
#define oddparity(x) __builtin_parity(x)
#define findFirstSet(x) __builtin_ffs(x) // index of the least significant bits of x) + 1.

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
  int n,x; cin>>n>>x;
  map<int,bool> new_dp;
  map<int,bool> old_dp;
  vector<int> v(n); cin>>v;
  vector<int> fac;

  for(int i=1; i*i<= x+1; i++){
    if(x%i == 0){
      fac.push_back(i);
      fac.push_back(x/i);
    }
  }

  fac.push_back(x);
  sort(all(fac));

  uniq(fac);
  int l=0;
  bool start = false;
  int cnt = 1;
  for(int i=0; i<n; i++){
    if(start){
      cnt++;
      start = false;
    }
    for(auto f : fac){
      if(i == l){
        new_dp[f] = (f == v[l]);
      }else{
        new_dp[f]  = old_dp[f] || (f == v[i]);
        if(f%v[i] == 0){
          new_dp[f] = new_dp[f] || old_dp[f/v[i]];
        }
      }
    }
    if(new_dp[x] == true){
      l = i;
      start = true;
      i--;
    }
    old_dp = new_dp;
    new_dp = map<int,bool>();
  }
  cout<<cnt<<'\n';
  // cout<<"Case #"<<test_case<<": ";
}

signed main() {
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
  cin >> test_case;
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
