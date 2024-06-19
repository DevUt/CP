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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> c(n); cin>>c;

    vector<pair<int,int>> first_cost;
    for(int i=0; i<n; i++){
        if(i&1){
            if(s[i] == '0'){
                first_cost.push_back({c[i],i});
            }
        }else{
            if(s[i] == '1'){
                first_cost.push_back({c[i],i});
            }
        }
    }

    ll first_no_cnv = LLONG_MAX;
    ll first_sum = 0;

    for(auto& [cost, idx] : first_cost){
        first_sum += cost;
        if(s[idx] == '0'){
            int cnt = 0;
            if(idx > 0){
                cnt += (s[idx-1] == '1');
            }
            if(idx < n-1){
                cnt += (s[idx+1] == '1');
            }
            if(cnt < 2){
                ckmin(first_no_cnv, (ll)cost);
            }
        }else{
            int cnt = 0;
            if(idx > 0){
                cnt += (s[idx-1] == '0');
            }
            if(idx < n-1){
                cnt += (s[idx+1] == '0');
            }
            if(cnt < 2){
                ckmin(first_no_cnv, (ll)cost);
            }

        }
    }
    first_sum -= first_no_cnv;

    vector<pair<int,int>> second_cost;
    for(int i=0; i<n; i++){
        if(i&1){
            if(s[i] == '1'){
                second_cost.push_back({c[i],i});
            }
        }else{
            if(s[i] == '0'){
                second_cost.push_back({c[i],i});
            }
        }
    }
    ll second_no_cnv = LLONG_MAX;
    ll second_sum = 0;

    for(auto& [cost, idx] : second_cost){
        second_sum += cost;
        if(s[idx] == '0'){
            int cnt = 0;
            if(idx > 0){
                cnt += (s[idx-1] == '1');
            }
            if(idx < n-1){
                cnt += (s[idx+1] == '1');
            }
            if(cnt < 2){
                ckmin(second_no_cnv, (ll)cost);
            }
        }else{
            int cnt = 0;
            if(idx > 0){
                cnt += (s[idx-1] == '0');
            }
            if(idx < n-1){
                cnt += (s[idx+1] == '0');
            }
            if(cnt < 2){
                ckmin(second_no_cnv, (ll)cost);
            }

        }
    }
    second_sum -= second_no_cnv;
    cout<<min(first_sum,second_sum);
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
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
