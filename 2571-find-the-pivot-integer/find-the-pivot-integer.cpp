#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args> void logger(string varname, Args &&...values) {
  cerr << varname << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}

// Vector Debugger
#ifndef ONLINE_JUDGE
#define debvec(x)                                                              \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << "\n";
#else
#define debvec(x)
#endif
template <typename T> void _print(T const &c) {
  cerr << "{ ";
  for (auto it = c.begin(); it != c.end(); it++) {
    cerr << *it << ", ";
  }
  cerr << "}";
}

/**
 * @brief-
 *
 *
 */

class Solution {
public:
  int pivotInteger(int n) {
    if (n == 1)
      return 1;

    //  Prefix sum
    int ct = 1, res = -1;
    vector<int> pf(n);
    pf[0] = ct++;
    for (int i = 1; i < n; i++, ct++) {
      pf[i] = pf[i - 1] + ct;
    }

    // Finding pivot
    int sum = pf[n - 1];
    for (int i = 1; i < n; i++) {
      if (pf[i] == sum - pf[i - 1]) {
        res = i + 1;
      }
    }

    debvec(pf);
    debug(res);

    return res;
  }
};
