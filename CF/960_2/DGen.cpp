#include <bits/stdc++.h>
#include <random>

using ull = unsigned long long;
using ll = long long;
using ldb = long double;

using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template <typename T, typename P> T cceil(const T &a, const P &b) {
  ll x = a, y = b;
  return (x + y - 1) / y;
}
template <typename T, typename P> T cfloor(const T &a, const P &b) {
  ll n = a, d = b;
  return n >= 0 ? n / d : -1 - (-1 - n) / d;
}

mt19937 initialize_rng(){ // Note this is not the static version
  random_device rnd_device;
  static mt19937 rng {rnd_device()};
  return rng;
}

vector<int> generate_random_vector(size_t size, int start, int finish){
  vector<int> ret(size);
  mt19937 rng = initialize_rng();
  uniform_int_distribution<int> dist {start, finish};
  auto gen = [&](){
    return dist(rng);
  };
  generate(all(ret),gen);
  return ret;
}

int generate_random_num(int start, int finish){
  mt19937 rng = initialize_rng();
  uniform_int_distribution<int>  dist{start, finish};
  return dist(rng);
}

void solve(int test_case) {
  int n = generate_random_num(1, 10);
  vector<int> a = generate_random_vector(n, 0, n);

  cout<<n<<'\n';
  for(auto& x: a)
    cout<<x<<' ';
  cout<<'\n';
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
  initialize_rng();
  int test_case = 1;
  cout<<test_case<<'\n';
  for (int i = 1; i <= test_case; i++) {
    solve(i);
  }
}
