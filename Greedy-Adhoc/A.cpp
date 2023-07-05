#include <iostream>
#include <vector>

using ll = long long;

void solve()
{
  int n{};
  std::cin >> n;

  std::vector<ll> s(n), f(n);
  for (int i{0}; i < n; ++i)
    std::cin >> s[i];
  for (int i{0}; i < n; ++i)
    std::cin >> f[i];

  for (int i{0}; i < n; ++i)
    std::cout << f[i] - std::max(i == 0 ? 0 : f[i - 1], s[i]) << " ";

  std::cout << '\n';
}

int main()
{
  int t{};
  std::cin >> t;

  while (t--)
    solve();

  return 0;
}
