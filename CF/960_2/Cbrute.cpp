/**
 *    author:  tourist
 *    created: 20.07.2024 10:40:24
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int64_t ans = 0;
    for (int it = 0; it < 2; it++) {
      vector<bool> was(n + 1, false);
      int mx = 0;
      for (int i = 0; i < n; i++) {
        ans += a[i];
        if (was[a[i]]) {
          mx = max(mx, a[i]);
        }
        was[a[i]] = true;
        a[i] = mx;
      }
    }
    for (int i = 0; i < n; i++) {
      ans += a[i] * int64_t(n - i);
    }
    cout << ans << '\n';
  }
  return 0;
}
