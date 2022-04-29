#include "StandardLibrary.hpp"

/**
 * @brief A test for the Doxygen Utility
 *
 */
class DoxygenClass {
  /**
   * @brief a random value
   *
   */
  int value;

 public:
  /**
   * @brief Get the Value object
   *
   * @return int
   */
  int GetValue() { return value; }
};

int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
