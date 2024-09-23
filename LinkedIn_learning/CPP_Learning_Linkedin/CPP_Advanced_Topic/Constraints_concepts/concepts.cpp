// constraints.cpp by Bill Weinman [bw.org]
// updated 2022-08-23
// #include <concepts>
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto &&...args) {
  fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

// clang-format off

// template <typename T>
// concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename T>
concept Numeric = requires(T a){
    a+1;a*1;
};


template <Numeric T>
// requires std::integral<T> || std::floating_point<T>

T arg42(const T &arg) {
  return arg + 42;
}
// clang-format on
int main() {
  auto n = 7.9;
  print("The answer is [{}]\n", arg42(n));
}
