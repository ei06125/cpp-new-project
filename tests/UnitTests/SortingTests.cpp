#include "StandardLibrary.hpp"

#include "ProjectLib.hpp"

#include <gtest/gtest.h>

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

TEST(SortingTestSuite, MergeSort_Vector) {
  auto data = GetData();
  auto copy = data;
  cpy::project::MergeSort(data);
  std::sort(copy.begin(), copy.end());
  EXPECT_EQ(data, copy);
}
