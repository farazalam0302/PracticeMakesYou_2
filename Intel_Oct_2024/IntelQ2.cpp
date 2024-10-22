// // Compute Fact (N) print ; no float and range 1 <= n <= 100
// // 158 digits  9.332622e+157
#include <bits/stdc++.h>
using namespace std;
#define DIGITS 200
void factorialUsingArray(int n) {
  int answer[DIGITS]; // = {0};
  answer[0] = 1;
  int answer_size = 1;
  for (int x = 2; x <= n; x++) {
    int carry = 0;
    for (int i = 0; i < answer_size; i++) {
      int prod = answer[i] * x + carry;
      answer[i] = prod % 10;
      carry = prod / 10;
    }
    while (carry) {
      answer[answer_size] = carry % 10;
      carry = carry / 10;
      answer_size++;
    }
  }
  // cout << "\nfactorialUsingArray(" << n << ") = \n";
  for (int i = answer_size - 1; i >= 0; i--) {
    cout << answer[i];
  }
  cout << "\n";
}

void factorialUsingVector(int n) {
  vector<int> answer;
  answer.push_back(1);
  // int answer_size = 1;
  for (int x = 2; x <= n; x++) {
    int carry = 0;
    for (int i = 0; i < answer.size(); i++) {
      int prod = answer[i] * x + carry;
      int psum = prod % 10;
      answer[i] = psum;
      carry = prod / 10;
    }
    while (carry) {
      int psum = carry % 10;
      answer.push_back(psum);
      carry = carry / 10;
      // answer_size++;
    }
  }
  // cout << "\nfactorialUsingVector(" << n << ") = \n";
  for (int i = answer.size() - 1; i >= 0; i--) {
    cout << answer[i];
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  factorialUsingArray(100);
  factorialUsingVector(600);
  // cout << "result = " << r << endl;
  return 0;
}
// C++ program to compute factorial of big numbers
#if 0
#include <iostream>
using namespace std;
// Maximum number of digits in output
#define MAX 500
// int multiply(int x, int res[], int res_size);
// This function finds factorial of large numbers
// and prints them
void factorial(int n) {
  int res[MAX];
  res[0] = 1;
  int res_size = 1;
  for (int x = 2; x <= n; x++) {
    int carry = 0; // Initialize carry
    for (int i = 0; i < res_size; i++) {
      int prod = res[i] * x + carry;
      res[i] = prod % 10;
      carry = prod / 10;
    }
    while (carry) {
      res[res_size] = carry % 10;
      carry = carry / 10;
      res_size++;
    }
  }
  cout << "Factorial of given number is \n";
  for (int i = res_size - 1; i >= 0; i--)
    cout << res[i];
}

// Driver program
int main() {
  factorial(100);
  return 0;
}

#endif

#if 0
int multiply(int x, int res[], int res_size) {
  int carry = 0; // Initialize carry
  // One by one multiply n with individual digits of res[]
  for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;
    // Store last digit of 'prod' in res[]
    res[i] = prod % 10;
    // Put rest in carry
    carry = prod / 10;
  }
  // Put carry in res and increase result size
  while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
  }
  return res_size;
}
#endif