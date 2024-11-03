#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to generate all possible sums of subsets from a portion of the array
vector<int> generateSubsets(const vector<int> &arr, int start, int end) {
  vector<int> subsetSums;
  int n = end - start;
  // Iterate over all subsets
  for (int i = 0; i < (1 << n); ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        sum += arr[start + j];
      }
    }
    subsetSums.push_back(sum);
  }
  return subsetSums;
}

int maximizeCPU(const vector<int> &requirements, int processingCapacity) {
  int n = requirements.size();

  // Split the array into two halves
  vector<int> leftSubsets = generateSubsets(requirements, 0, n / 2);
  vector<int> rightSubsets = generateSubsets(requirements, n / 2, n);

  // Sort the right subsets so we can perform binary search
  sort(rightSubsets.begin(), rightSubsets.end());

  int maxSum = 0;

  // For each sum in the left subset, find the largest possible sum in the right
  // subset that fits within the capacity
  for (int leftSum : leftSubsets) {
    if (leftSum <= processingCapacity) {
      // Use binary search to find the best fit in the right subset
      int remainingCapacity = processingCapacity - leftSum;
      auto it = upper_bound(rightSubsets.begin(), rightSubsets.end(),
                            remainingCapacity);

      if (it != rightSubsets.begin()) {
        --it;
        int rightSum = *it;
        maxSum = max(maxSum, leftSum + rightSum);
      } else {
        maxSum = max(maxSum, leftSum);
      }
    }
  }

  return maxSum;
}

int main() {
  int n;
  cin >> n;
  vector<int> requirements(n);

  for (int i = 0; i < n; ++i) {
    cin >> requirements[i];
  }

  int processingCapacity;
  cin >> processingCapacity;

  int result = maximizeCPU(requirements, processingCapacity);
  cout << result << endl;

  return 0;
}