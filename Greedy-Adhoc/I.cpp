#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;

void solve()
{
  int n{};
  std::cin >> n;

  std::vector<ll> A(n + 1);
  for (int i{0}; i < n; ++i)
    std::cin >> A[i];

  ll max{0};
  ll min{0};
  ll cur{0};
  for (int i{0}; i < n; ++i)
  {
    cur += A[i];
    max = std::max(max, cur);
    min = std::min(min, cur);
  }

  std::cout << max - min << '\n';
}

int main()
{
  int t{};
  std::cin >> t;

  while (t--)
    solve();

  return 0;
}
