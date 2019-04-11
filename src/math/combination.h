/* Copyright [2019] <thomas: mrqiantao@163.com> */
#ifndef SRC_MATH_COMBINATION_H_
#define SRC_MATH_COMBINATION_H_
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

namespace alg {
namespace combination {
template <typename T>
using ElementContainer = std::vector<T>;

template <typename T>
using CombinationList = std::vector<std::vector<T>>;

template <typename T>
std::string ToString(const ElementContainer<T> &element_container) {
  std::stringstream ss;
  ss << "[";
  for (auto element : element_container) {
    ss << element << " ";
  }
  ss << "\b]";
  return ss.str();
}

template <typename T>
CombinationList<T> GetCombination(const ElementContainer<T> &from_container,
                                   int size) {
  CombinationList<T> cl;
  if (size <= 0 || size > from_container.size()) {
    return cl;
  }
  if (1 == size) {
    for (const auto &element : from_container) {
      ElementContainer<T> c;
      c.emplace_back(element);
      cl.emplace_back(c);
    }
    return cl;
  }
  auto front_element = from_container.front();
  ElementContainer<T> remain_elements;
  std::copy(std::next(from_container.begin()), from_container.end(),
            std::back_inserter(remain_elements));
  auto &&combination_with_front = GetCombination(remain_elements, size - 1);
  for (auto &&cwf : combination_with_front) {
    cwf.insert(cwf.begin(), front_element);
  }
  std::copy(combination_with_front.begin(), combination_with_front.end(),
            std::back_inserter(cl));
  auto &&combination_without_front = GetCombination(remain_elements, size);
  std::copy(combination_without_front.begin(), combination_without_front.end(),
            std::back_inserter(cl));
  return cl;
}
}  // namespace combination
}  // namespace alg
#endif  // SRC_MATH_COMBINATION_H_
