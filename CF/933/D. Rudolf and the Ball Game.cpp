#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

vector<pair<int,char>> v;
vector<vector<char>> check;
set<int> result;
int n,m,x;

void ans(int player, int mov){
    if(v[mov].second == '0'){
        int play = player + v[mov].first;
        if(play > n)
            play -= n;
        if(mov+1 == m){
            result.insert(play);
            return;
        }
        if(!check[play][mov+1]){
            check[play][mov+1] = true;
            ans(play,mov+1);
        }
    }else if(v[mov].second == '1'){
        int play = player - v[mov].first;
        if(play <= 0){
            play += n;
        }
        if(mov+1 == m){
            result.insert(play);
            return;
        }

        if(!check[play][mov+1]){
            check[play][mov+1] = true;
            ans(play,mov+1);
        }
    }else{
        int play = player + v[mov].first;
        if(play > n)
            play -= n;
        if(mov+1 == m){
            result.insert(play);
        }
        if(mov+1 < m && (!check[play][mov+1])){
            check[play][mov+1] = true;
            ans(play,mov+1);
        }

        play = player - v[mov].first;
        if(play <= 0){
            play += n;
        }
        if(mov+1 == m){
            result.insert(play);
            return;
        }
        if(!check[play][mov+1]){
            check[play][mov+1] = true;
            ans(play,mov+1);
        }
    }

}

void solve(int test_case) {
    cin>>n>>m>>x;
    v = vector<pair<int,char>>(m);
    check  = vector<vector<char>>(n+1,vector<char>(m));

    result.clear();
    for(auto& p : v){
        cin>>p.first;
        cin>>p.second;
    }
    ans(x,0);
    cout<<result.size()<<'\n';
    for(auto& y: result){
        cout<<y<<' ';
    }
    cout<<'\n';
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
  cin >> test_case;
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
