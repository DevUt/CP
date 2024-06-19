#include <bits/stdc++.h>
#pragma GCC target(                                                            \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("tree-vectorize")


#define popcnt(x) __builtin_popcount(x) // Count number of 1's in bit representation
#define popcntll(x) __builtin_popcountll(x) // As above but for long long
#define trailz(x) __builtin_ctz(x) // Count traling zeros
#define trailzll(x) __builtin_ctzll(x) // As above but for long long
#define leadz(x) __builtin_clz(x) // Count leading Zeros, "NUMBER SHOULD BE UNSIGNED"
#define leadzll(x) __builtin_clzll(x) // As above but for long long
#define oddparity(x) __builtin_parity(x) // Returns true(1) if the number has odd parity(odd number of set bits)
#define findFirstSet(x) __builtin_ffs(x) // Index of the least significant bits of x) + 1.


// Type definitions
#define ull unsigned long long
#define ll long long
#define ldb long double

using namespace std;

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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define uniq(x) x.erase(unique(all(x)), x.end());

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); } // TYPE MUST BE SAME
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }
template <typename T, typename P> T cceil(const T &a, const P &b) {
  ll x = a, y = b;
  return (x + y - 1) / y;
}
template <typename T, typename P> T cfloor(const T &a, const P &b) {
  ll n = a, d = b;
  return n >= 0 ? n / d : -1 - (-1 - n) / d;
}

void solve(int testcase){
}

int main(){
#ifndef SLOWIO
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif
#ifndef PARTH_LOCAL
// freopen("problemname.in", "r", stdin);
// // the following line creates/overwrites the output file
// freopen("problemname.out", "w", stdout);
#endif

  int testcase = 1;
  cin>>testcase;
  for(int i=1; i<=testcase; i++){
      solve(i);
  }
}


