/* Copyright [2019] <thomas: mrqiantao@163.com> */
#include <iostream>
#include "math/combination.h"

namespace {
constexpr int kSelectSize = 5;
constexpr int kMinNumber = 1;
constexpr int kMaxNumber = 9;
}

class Number {
 public:
  explicit Number(int number) : number_(number) {}

  inline int Value() const { return number_; }

  friend std::stringstream &operator<<(std::stringstream &out,
                                       const Number &number) {
    out << number.Value();
    return out;
  }

 private:
  int number_;
};

int main(int argc, char const *argv[]) {
  ::alg::combination::ElementContainer<Number> elements;
  // generate the test data
  for (int i = kMinNumber; i <= kMaxNumber; i++) {
    elements.emplace_back(i);
  }
  // get all combinations
  auto &&combination_list =
      ::alg::combination::GetCombination(elements, kSelectSize);
  // print all combinations
  for (auto &&iec : combination_list) {
    std::cout << alg::combination::ToString(iec) << std::endl;
  }
  // print size of all combinations
  std::cout << "combination size: " << combination_list.size() << std::endl;
  return 0;
}
