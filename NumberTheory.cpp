#include <bits/stdc++.h>
using namespace std;
struct NumberTheory {
  long long bigmod(long long a, long long b) {
    long long res = 1LL;
    while (b > 0) {
      if (b & 1) {
        res *= a;
      }
      a *= a, b >>= 1;
    }
    return res;
    // works in O(log(b))
  }
  long long gcd(long long a, long long b) { // faster gcd function for removing mod
    if (a == 0 || b == 0) {
      return a | b; // if one of a or b is 0, the gcd will be the other one
    }
    int cnt2 = __builtin_ctzll(a, b); // counts the number of 2s in the prime factorization of gcd(a, b)
    a >>= __builtin_ctzll(a); // removes all the 2 factors from a
    do {
      b >>= __builtin_ctzll(b);
      if (a > b) {
        swap(a, b);
      }
      b -= a;
    } while (b);
    return a << cnt2; // adds the 2 factors of the gcd
    // the main idea is 
      // gcd(2a, 2b) = 2 * gcd(a, b)
      // gcd(2a, b) = gcd(a, b)
      // gcd(a, b) = gcd(a, b - a)
    
  }
  long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
    // works in O(log(min(a, b)))
  }
  long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
      x = 0, y = 1; // base case
      return a;
    }
    // a % b = a - floor(a / b) * b
    // ax + by = g, we want to find x, y
    // we know, b * x1 + (a % b) * y1 = g
    // => b * x1 + a * y1 - (a / b) * y1 * b
    // => a * y1 + b * (x1 - (a / b) * y1)
    // => x = y1, y = x1 - (a / b) * y1
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
  }
  int mxVal;
  bitset<1000005> mark;
  void sieve() {
    for (int i = 4; i <= mxVal; i += 2) {
      mark[i] = 1;
    }
    mark[0] = mark[1] = 1;
    for (int i = 3; i * i <= mxVal; i += 2) {
      if (mark[i] == 1) {
        continue;
      }
      for (int j = i * i; j <= mxVal; j += i + i) {
        mark[j] = 1;
      }
    }
  }
}
int main() {
   
}
