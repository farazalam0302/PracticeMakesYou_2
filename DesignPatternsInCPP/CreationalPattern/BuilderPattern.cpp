#include <bits/stdc++.h>
using namespace std;

struct HtmlElement // utilty class for Html elemenmt
{
  string name, text;
  vector<HtmlElement> elements;
  const size_t indentSize = 2;
  HtmlElement() {}
  HtmlElement(const string &name, const string &text)
      : name(name), text(text) {}
  string str(int indent = 0) const {

    ostringstream oss;
    string i(indentSize * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0) {
      oss << string(indentSize * (indent + 1), ' ') << text << endl;
    }
    for (const auto &e : elements) {
      oss << e.str(indent + 1);
    }
    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }
};

struct HtmlBuilder // It acts as an API to build objects

{
  HtmlElement root;
  HtmlBuilder(string root_name) { root.name = root_name; }
  void addChild(string childName, string childText) {
    HtmlElement e{childName, childText};
    root.elements.emplace_back(e);
  }
  string str() const { return root.str(); }
};

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

  HtmlBuilder builder{"ul"};
  builder.addChild("li", "Hello");
  builder.addChild("li", "World");
  cout << builder.str() << endl;

  return 0;
}
