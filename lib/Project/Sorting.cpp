#include "StandardLibrary.hpp"

#include "Sorting.hpp"

namespace cpy::project {

  void Merge(int* A, int p, int q, int r) {
    auto n1 = static_cast<unsigned long>(q - p + 1);
    auto n2 = static_cast<unsigned long>(r - q);
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    for (unsigned long i = 0; i < n1; i++)
      L[i] = A[static_cast<unsigned long>(p) + i - 1];
    for (unsigned long j = 0; j < n2; j++)
      R[j] = A[static_cast<unsigned long>(q) + j];
    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = p - 1; k < r; k++) {
      if (L[i] <= R[j]) {
        A[k] = L[i];
        i = i + 1;
      } else {
        A[k] = R[j];
        j = j + 1;
      }
    };
    delete[] L;
    delete[] R;
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
