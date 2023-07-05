#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void solve()
{
  int n{}, k{};
  std::cin >> n >> k;

  std::vector<int> A(n);
  for (int i{0}; i < n; ++i)
    std::cin >> A[i];

  int res{std::numeric_limits<int>::max()};
  for (int i{1}; i <= A[0]; ++i)
  {
    int max{std::numeric_limits<int>::min()};
    int min{std::numeric_limits<int>::max()};
    for (int j{0}; j < n; ++j)
    {
      int cur{std::min(A[j] / i, k)};
      max = std::max(max, A[j] / cur);
      min = std::min(min, A[j] / cur);
    }

    res = std::min(res, max - min);
  }

  std::cout << res << '\n';
}

int main()
{
  int t{};
  std::cin >> t;

  while (t--)
    solve();

  return 0;
}
