/*
Write a program to Validate an IPv4 Address.
According to Wikipedia, IPv4 addresses are canonically represented in
dot-decimal notation, which consists of four decimal numbers, each ranging from
0 to 255, separated by dots, e.g., 172.16.254.1

Following are steps to check whether a given string is a valid IPv4 address or
not:
*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define DELIM "."

bool isValidIP_token(string token) {
  int tlen = token.length();
  if (tlen > 3)
    return false;
  for (auto &i : token) {
    if ((i >= '0' && i <= '9') == false)
      return false;
  }
  if (token.find('0') == 0 && tlen > 1)
    return false;
  int tnum = stoi(token);
  return (tnum >= 0 && tnum <= 255);
}

bool isValidIP(string &ip_str) {
  int len = ip_str.length();
  if (len < 7)
    return false;
  int dots = 0;
  for (auto &i : ip_str) {
    if (i == '.')
      dots++;
  }
  if (dots != 3)
    return false;
  string token;
  stringstream ss(ip_str);
  vector<string> tokens;
  while (getline(ss, token, '.')) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  for (auto &i : tokens) {
    if (!isValidIP_token(i))
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string ip1 = "128.0.0.1";
  string ip2 = "125.A.100.1";
  string ip3 = "125.512.100.1";
  string ip4 = "125.254.100.001";
  cout << "\n--------------------------\n";
  isValidIP(ip1) ? cout << "Valid IP\n" : cout << "Invalid IP\n";
  isValidIP(ip2) ? cout << "Valid IP\n" : cout << "Invalid IP\n";
  isValidIP(ip3) ? cout << "Valid IP\n" : cout << "Invalid IP\n";
  isValidIP(ip4) ? cout << "Valid IP\n" : cout << "Invalid IP\n";
  cout << "\n--------------------------\n";
  return 0;
}
