#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;

void solve()
{
  int n{}, m{};
  std::cin >> n >> m;
  std::vector<ll> A(n);
  std::cin >> A[0];
  std::set<int> indices{0};
  ll latest{A[0]};
  for (int i{1}; i < n; ++i)
  {
    std::cin >> A[i];
    if (A[i] < latest)
    {
      indices.insert(i);
      latest = A[i];
    }
  }

  int k{};
  ll d{};
  for (int i{0}; i < m; ++i)
  {
    std::cin >> k >> d;
    A[k - 1] -= d;
    auto up{indices.upper_bound(k - 1)};

    auto cur{--up};
    if (A[*cur] > A[k - 1])
      indices.insert(k - 1);

    auto it{indices.upper_bound(k - 1)};
    while ((it = indices.upper_bound(k - 1)) != indices.end() && A[*it] >= A[k - 1])
      indices.erase(it);

    std::cout << indices.size() << ' ';
  }
  std::cout << '\n';
}

int main()
{
  int t{};
  std::cin >> t;
  for (int i{0}; i < t; ++i)
  {
    solve();
  }

  return 0;
}
