// lambda-hello.cpp by Bill Weinman [bw.org]
// updated 2022-09-09
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto &&...args) {
  fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
  auto x = [] { return ("Hello, earthlings\n"); };
  print("{}\n", x());

  // lambda with trailing list of return type
  auto y = []() -> const char * {
    return ("Hello, from parametrized lambda earthlings\n");
  };
  print("{}\n", y());

  auto z = [](auto p) { return (p); };
  print("{}\n", z("Hi from Z function"));
  const char *g = "hi faraz from captureList";
  auto a = [g] { return (g); };
  print("{}\n", a());
}

/*
// clang-format off
Genralized Lambda Syntax

[capture-list] (parameters)
    mutable (optional)
    constexpr (optional)
    noexcept (optional)
    -> return type (optional)
    {
    // body  ------------
    }
// clang-format on

*/