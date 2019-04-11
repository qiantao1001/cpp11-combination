
# combination algorithm implemented by c++11

> Get all combinations of Cij.

*Powered By [cpp-template-workspace](https://github.com/qiantao1001/cpp-template-workspace)*

- following [《Google C++ Style Guide》](https://google.github.io/styleguide/cppguide.html)
- using [googletest](https://github.com/google/googletest) as test framework
- using [CMake](https://cmake.org/) as build system

## Example Of Usage
```c++
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
```

## Build And Run Demo
```bash
$ cd cpp11-combination
$ mkdir build
$ cd build/
$ cmake ..

# run demo
$ cd build/
$ ./combination
```

## Contact
If you would like to contribute or have found bugs, visit the [project page on GitHub](https://github.com/qiantao1001/cpp11-combination) and use the [issues tracker](https://github.com/qiantao1001/cpp11-combination/issues) there.

For questions and suggestions, success or failure stories, and any other kind of feedback, please feel free to contact the author (the email address can be found in the sources).

## License
This is [Open Source](http://www.opensource.org/docs/definition.html) software. It may be used for any purpose, including commercial purposes, at absolutly no cost. It is distributed under the terms of the [MIT license](http://www.opensource.org/licenses/mit-license.html).
