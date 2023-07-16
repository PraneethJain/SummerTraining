#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

int main()
{
  int n{};
  std::cin >> n;
  ll t{};
  std::cin >> t;

  std::vector<ll> A(n);
  for (int i{0}; i < n; ++i)
    std::cin >> A[i];

  ll sum{0};
  ll res{0};
  int till{0};
  for (int i{0}; i < n; ++i)
  {
    while (sum + A[till] <= t && till < n)
      sum += A[till++];
    res = std::max(res, static_cast<ll>(till - i));
    sum -= A[i];
  }

  std::cout << res << '\n';

  return 0;
}
