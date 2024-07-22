/**
 *    author:  tourist
 *    created: 20.07.2024 10:45:58
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += int(a[i] > 0);
    }
    int beg = 0;
    while (beg < n) {
      if (a[beg] == 0 || a[beg] > 2) {
        beg += 1;
        continue;
      }
      int end = beg + 1;
      while (end < n && (a[end] == 3 || a[end] == 4)) {
        end += 1;
      }
      if (end < n && (a[end] == 1 || a[end] == 2) && (end - beg) % 2 == 1) {
        ans -= 1;
        beg = end + 1;
      } else {
        beg += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

