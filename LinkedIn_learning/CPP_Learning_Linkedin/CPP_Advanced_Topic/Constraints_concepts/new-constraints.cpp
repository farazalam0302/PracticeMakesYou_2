// constraints.cpp by Bill Weinman [bw.org]
// updated 2022-08-23
#include <concepts>
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto &&...args) {
  fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// clang-format off
// template <Numeric T>
// requires Numeric<T>
// T arg42(const T &arg)

auto arg42(const Numeric auto& arg) // breif template
{ return arg + 42; }

// clang-format on

int main() {
  auto n = 7.7;
  print("The result is [{}]\n", arg42(n));
}
