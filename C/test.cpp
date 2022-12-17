#include <bits/stdc++.h>


int main() {
  long long n = pow(10, 6);
  int sieve[n]; 
  for (int x = 2; x <= n; x++) {
    if (sieve[x]) continue;
    for (int u = 2 * x; u <= n; u += x) {
      sieve[u] = 1;
    }
  }
}