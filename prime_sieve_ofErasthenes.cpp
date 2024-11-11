#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a) {
  int index = 0;
  //   cout << endl;
  //   for (auto &i : a) {
  //     cout << (index++) << ", ";
  //   }
  cout << endl;
  for (auto &i : a) {
    cout << (index++) << " -> " << i << "\n";
  }
  cout << endl;
}

void sieveOfErasthenes(vector<int> &primes, int n) {
  vector<int> isPrime(n + 1, true);
  isPrime[0] = 0;
  isPrime[1] = 0;
  for (size_t i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (size_t j = i * i; j <= n; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  for (size_t i = 2; i < n; i++) {
    if (isPrime[i])
      primes.push_back(i);
  }
  printArray(isPrime);
}

int main(int argc, char const *argv[]) {
  int n = 1000;
  vector<int> primes;
  sieveOfErasthenes(primes, n);
  //   printArray(primes);
  return 0;
}
