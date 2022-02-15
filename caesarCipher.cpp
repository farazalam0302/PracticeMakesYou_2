#include <bits/stdc++.h>
using namespace std;

string caesarCipher(string& text) {
  string output = "";
  int n = text.length();
  for (int i = 0; i < n; ++i) {
    if (!(isalpha(text[i])) && !isspace(text[i])) {
      cout << "invalid character = " << text[i]
           << " entered Only alphanumerals needed!!\n\n";
      return "";
    }
    char t;
    if (!isspace(text[i])) {
      if (islower(text[i])) {
        if (text[i] < 'x')
          t = (char)((text[i] + 3));
        else {
          if (text[i] == 'x')
            t = 'a';
          else if (text[i] == 'y')
            t = 'b';
          else if (text[i] == 'z')
            t = 'c';
        }
      } else {
        if (text[i] < 'X')
          t = (char)((text[i] + 3));
        else {
          if (text[i] == 'X')
            t = 'A';
          else if (text[i] == 'Y')
            t = 'B';
          else if (text[i] == 'Z')
            t = 'C';
        }
      }
    } else {
      t = ' ';
    }
    output = output + t;
  }
  return output;
}

string caesarDeCipher(string& text) {
  string output = "";
  int n = text.length();
  for (int i = 0; i < n; ++i) {
    if (!(isalpha(text[i])) && !isspace(text[i])) {
      cout << "invalid character = " << text[i]
           << " entered Only alphanumerals needed!!\n\n";
      return "";
    }
    char t;
    if (!isspace(text[i])) {
      if (islower(text[i])) {
        if (text[i] > 'c')
          t = (char)((text[i] - 3));
        else {
          if (text[i] == 'a')
            t = 'x';
          else if (text[i] == 'b')
            t = 'y';
          else if (text[i] == 'c')
            t = 'z';
        }
      } else {
        if (text[i] > 'C')
          t = (char)((text[i] - 3));
        else {
          if (text[i] == 'A')
            t = 'X';
          else if (text[i] == 'B')
            t = 'Y';
          else if (text[i] == 'C')
            t = 'Z';
        }
      }
    } else {
      t = ' ';
    }
    output = output + t;
  }
  return output;
}

int main() {
  string text = "love one another";
  string cipher = caesarCipher(text);
  if (!cipher.empty()) cout << "cipher = " << cipher << endl;
  string decipher = caesarDeCipher(cipher);
  if (!decipher.empty()) cout << "decipher = " << decipher << endl;
  return 0;
}
