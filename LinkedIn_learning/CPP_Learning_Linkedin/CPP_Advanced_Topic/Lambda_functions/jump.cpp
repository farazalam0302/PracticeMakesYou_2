

#include <functional>
#include <iostream>
#include <map>
#include <string>

const char prompt(const char *pstr) {
  auto char_upper = [](char x) -> char {
    if (x >= 'a' && x <= 'z') {
      x = x - 'a' + 'A';
    }
    return x;
  };
  std::string r{};
  std::cout << pstr << " > ";
  getline(std::cin, r, '\n');
  if (r.size() < 1)
    return '\0';
  else if (r.size() > 1)
    return '\0';
  else
    return char_upper(r.at(0));
}

bool jump(const char select) {
  //   using jumpfunc = void (*)();
  using jumpfunc = std::function<void()>;
  const std::map<char, jumpfunc> jumpMap{
      {'A', [] { std::cout << "function A \n"; }},
      {'B', [] { std::cout << "function B \n"; }},
      {'C', [] { std::cout << "function C \n"; }},
      {'D', [] { std::cout << "function D \n"; }},
  };

  const auto it = jumpMap.find(select);
  if (it != jumpMap.end()) {
    it->second();
    return true;
  } else {
    std::cout << "Invalid Input!!" << std::endl;
    return false;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  const char *promptstr{"What to do? (A/B/C/D/X)"};
  for (auto key = prompt(promptstr); key != 'X'; key = prompt(promptstr)) {
    if (key) {
      jump(key);
    }
  }
  std::cout << "Bye\n";

  return 0;
}

#if 0
//  jump.cpp by Bill Weinman [bw.org]
//  as of 2022-08-29
#include <format>
#include <iostream>
#include <map>
#include <string>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto &&...args) {
  fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

const char prompt(const char *p) {
  auto char_upper = [](char c) -> char {
    if (c >= 'a' && c <= 'z')
      return c - ('a' - 'A');
    else
      return c;
  };

  std::string r{};
  print("{} > ", p);
  getline(std::cin, r, '\n');

  if (r.size() < 1)
    return '\0';
  else if (r.size() > 1) {
    print("Response too long\n");
    return '\0';
  } else
    return char_upper(r.at(0));
}

bool jump(const char select) {
  // alternately, this works too --
  // using jumpfunc = std::function<void()>;
  // std::function requires the <functional> header
  using jumpfunc = void (*)();

  const std::map<char, jumpfunc> jumpmap{
      {'A', [] { print("func A\n"); }},
      {'B', [] { print("func B\n"); }},
      {'C', [] { print("func C\n"); }},
      {'D', [] { print("func D\n"); }},
  };

  const auto it = jumpmap.find(select);
  if (it != jumpmap.end())
    it->second();
  else {
    print("Invalid response\n");
    return false;
  }
  return true;
}

int main() {
  const char *pstr{"What to do? (A/B/C/D/X)"};
  for (auto key = prompt(pstr); key != 'X'; key = prompt(pstr)) {
    if (key)
      jump(key);
  }
  print("Bye!\n");
}
#endif