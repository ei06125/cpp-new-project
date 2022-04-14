#include "StandardLibrary.hpp"

#include "doctest/doctest.h"

#include "ProjectLib.hpp"

/// ###########################################################################
/// @section Helper
/// ###########################################################################

constexpr std::size_t cxMaxSize = 10;

static std::vector<int> GetData() {
  static std::vector<int> result;
  if (result.empty()) {
    std::default_random_engine dre;
    result.resize(cxMaxSize);
    std::iota(result.begin(), result.end(), 1);
    std::shuffle(result.begin(), result.end(), dre);
  }
  return result;
}

/// ###########################################################################
/// @section MergeSort
/// ###########################################################################

SCENARIO("Sorting a shuffled vector") {
  GIVEN("d = data()\
    \n\t And c = d (copy)") {

    auto d = GetData();
    auto c = d;

    WHEN("MergeSort(d) && std::sort(c)") {
      cpy::project::MergeSort(d);
      std::sort(c.begin(), c.end());

      THEN("d is equal to c and both are sorted") {
        CHECK(c == d);
      }
    }
  }
}
