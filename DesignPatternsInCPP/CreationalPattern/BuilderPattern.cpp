#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << endl;

  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "\n<ul>";
  for (auto w : words) {
    oss << "\n<li>" << w << "</li>";
  }
  oss << "\n<ul>\n";

  cout << oss.str() << endl;
  return 0;
}
