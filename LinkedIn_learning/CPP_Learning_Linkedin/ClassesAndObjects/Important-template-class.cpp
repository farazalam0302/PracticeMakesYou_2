#include <bits/stdc++.h>
using namespace std;
#include <exception>
#include <fmt/format.h>
#include <memory>

namespace alam {
template <typename T> class Stack {
  static const int default_size{10};
  static const int max_size{1000};
  int S_size{};
  int S_top{};
  unique_ptr<T[]> S_ptr{};

public:
  explicit Stack(int s = default_size);
  ~Stack() {
    if (S_ptr) {
      S_ptr.release();
    }
  }

  T &push(const T &);
  T &pop();

  bool is_empty() const { return S_top < 0; }
  bool is_full() const { return S_top >= S_size - 1; }

  int top() const { return S_top; }
  int size() const { return S_size; }
};

template <typename T> Stack<T>::Stack(int s) {
  if (s < 1 || s > max_size) {
    cout << "Invalid Stack Size\n";
    exit(-1);
  } else {
    S_size = s;
    S_ptr.reset(new T[S_size]);
    S_top = -1;
  }
}

template <typename T> T &Stack<T>::push(const T &k) {
  if (is_full()) {
    cout << "Stack Overflown!!\n";
    exit(-1);
  }
  return S_ptr[++S_top] = k;
}

template <typename T> T &Stack<T>::pop() {
  if (is_empty()) {
    cout << "Stack Underflown!!\n";
    exit(-1);
  }
  return S_ptr[S_top--];
}

} // namespace alam

int main(int argc, char const *argv[]) {
  alam::Stack<int> is(5);
  alam::Stack<string> ss(5);

  cout << format("Initially int_stack size = {} intStack_top = {}\n", is.size(),
                 is.top());
  for (size_t i = 1; i < 5; i++) {
    is.push(i);
  }

  cout << format(
      "After Pushing 5 ints.\n int_stack size = {} intStack_top = {}\n",
      is.size(), is.top());

  while (!is.is_empty()) {
    cout << format("Popped Element = {}\n", is.pop());
  }

  cout << format(
      "After Popping 5 ints.\n int_stack size = {} intStack_top = {}\n",
      is.size(), is.top());

  cout << format("Initially string_stack size = {} intStack_top = {}\n",
                 ss.size(), ss.top());
  for (auto &i : {"a", "b", "c", "d", "e"}) {
    ss.push(i);
  }

  cout << format(
      "After Pushing 5 strings.\n string_stack size = {} intStack_top = {}\n",
      ss.size(), ss.top());

  while (!ss.is_empty()) {
    cout << format("Popped Element = {}\n", ss.pop());
  }

  cout << format(
      "After Popping 5 string.\n string_stack size = {} intStack_top = {}\n",
      ss.size(), ss.top());

  return 0;
}

#if 0
namespace bw {

// simple exception class
class S_err : public std::exception {
  const char *msg;

public:
  S_err() = delete; // no default constructor
  explicit S_err(const char *s) noexcept : msg(s) {}
  const char *what() const noexcept { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T> class Stack {
  static const int default_size{10};
  static const int max_size{1000};
  int S_size{};
  int S_top{};
  std::unique_ptr<T[]> S_ptr{};

public:
  explicit Stack(int s = default_size);
  ~Stack() {
    if (S_ptr)
      S_ptr.release();
  }
  T &push(const T &);
  T &pop();
  bool is_empty() const { return S_top < 0; }
  bool is_full() const { return S_top >= S_size - 1; }
  int top() const { return S_top; }
  int size() const { return S_size; }
};

// Stack<T> constructor
template <typename T> Stack<T>::Stack(int s) {
  if (s > max_size || s < 1)
    throw S_err("invalid stack size");
  else
    S_size = s;
  S_ptr.reset(new T[S_size]);
  S_top = -1;
}

template <typename T> T &Stack<T>::push(const T &i) {
  if (is_full())
    throw S_err("stack full");
  return S_ptr[++S_top] = i;
}

template <typename T> T &Stack<T>::pop() {
  if (is_empty())
    throw S_err("stack empty");
  return S_ptr[S_top--];
}

} // namespace bw

int main() {
  bw::Stack<int> si{5};
  bw::Stack<std::string> ss{5};

  try {
    cout << format("si size: {}\n", si.size());
    cout << format("si top: {}\n", si.top());

    for (int i : {1, 2, 3, 4, 5}) {
      si.push(i);
    }

    cout << format("si top after pushes: {}\n", si.top());
    cout << format("si is {}full\n", si.is_full() ? "" : "not ");

    while (!si.is_empty()) {
      cout << format("popped {}\n", si.pop());
    }

    cout << format("ss size: {}\n", ss.size());
    cout << format("ss top: {}\n", ss.top());

    for (const char *s : {"one", "two", "three", "four", "five"}) {
      ss.push(s);
    }

    cout << format("ss top after pushes: {}\n", ss.top());
    cout << format("ss is {}full\n", ss.is_full() ? "" : "not ");

    while (!ss.is_empty()) {
      cout << format("popped {}\n", ss.pop());
    }
  } catch (bw::S_err &e) {
    std::cout << format("Stack error: {}\n", e.what());
    return 1;
  }
}
#endif