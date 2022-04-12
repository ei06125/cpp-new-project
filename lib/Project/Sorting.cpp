#include "Sorting.hpp"

namespace cpy::project {

  void Merge(int* A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> L(n1 + 1);
    std::vector<int> R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
      L[i] = A[p + i - 1];
    }
    for (int j = 0; j < n2; ++j) {
      R[j] = A[q + j];
    }

    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();

    for (int i = 0, j = 0, k = p - 1; k < r; ++k) {
      if (L[i] <= R[j]) {
        A[k] = L[i];
        ++i;
      } else {
        A[k] = R[j];
        ++j;
      }
    }
  }

  void MergeSort(int* A, int p, int r) {
    if (p < r) {
      int q = (p + r) / 2;
      MergeSort(A, p, q);
      MergeSort(A, q + 1, r);
      Merge(A, p, q, r);
    }
  }

  void MergeSort(std::vector<int>& A) {
    MergeSort(A.data(), 1, static_cast<int>(A.size()));
  }

} // namespace cpy::project
