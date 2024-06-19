#include <bits/stdc++.h>
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
    vector<int> v(n);

    set<int> onepos, zeropos;
    for(int pos = 0; auto& x : s){
        if(x == '1')
            onepos.insert(pos);
        else
         zeropos.insert(pos);
        pos++;
    }

    int turn;

    int ans = 0;
    int last_pos = -1;
    bool terminate = true;

    auto run = [&](set<int>& positionset){
        auto itr = positionset.upper_bound(last_pos);
        if(itr != positionset.end()){
            if(terminate){
                terminate = false;
                ans++;
            }
            last_pos = *itr;
            v[last_pos] = ans;
            positionset.erase(itr);
        }else{
            terminate = true;
            last_pos = -1;
        }

    };
    while(onepos.size() && zeropos.size()){
        if(last_pos == -1){
            if(*(onepos.begin()) < *(zeropos.begin())){
                turn = 1;
            }else{
                turn = 0;
            }
        }
        if(turn){
            run(onepos);
        }else{
            run(zeropos);
        }
        turn = !turn;
    }
    if(turn){
        run(onepos);
    }else{
        run(zeropos);
    }
    ans += (onepos.size() + zeropos.size());
    int maxidx = *max_element(all(v));

    for(auto& x : v){
        if(x == 0){
            x = ++maxidx;
        }
    }
    cout<<ans<<'\n'<<v<<'\n';
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
