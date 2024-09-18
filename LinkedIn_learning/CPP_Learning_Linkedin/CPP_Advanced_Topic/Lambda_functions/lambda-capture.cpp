// lambda-capture.cpp by Bill Weinman [bw.org]
// updated 2022-09-09
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto &&...args) {
  fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
  const char *greeting{"Hello"};
  const char *folks{"Folks"};
  auto x = [greeting, folks] {
    return std::format("from x {}, {}", greeting, folks);
  };
  print("{}\n", x());

  // capture by refrences

  auto y = [&greeting, &folks] {
    return std::format("from y {}, {}", greeting, folks);
  };
  print("{}\n", y());

  // capture all by refs in scope
  auto z = [&] { return std::format("from z {}, {}", greeting, folks); };
  print("{}\n", z());

  // capture all by refs in scope
  //   auto a = [] { return std::format("from a {}, {}", greeting, folks); };
  //   print("{}\n", a());
}
