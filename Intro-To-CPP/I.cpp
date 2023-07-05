#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void solve()
{
  int n{};
  std::cin >> n;
  std::vector<int> A(2 * n);
  for (int i{0}; i < 2 * n; ++i)
    std::cin >> A[i];

  std::sort(A.begin(), A.end());
  int max{A.back()};
  auto last = std::prev(A.end());
  for (auto it{A.begin()}; it != last; ++it)
  {
    int original_x{*it + max};
    int x{*it + max};
    std::vector<std::pair<int, int>> res;
    std::multiset<int> s{A.begin(), A.end()};
    while (!s.empty())
    {
      auto highest{std::prev(s.end())};
      int a{*highest};
      s.erase(highest);
      int b{x - a};
      auto cur{s.find(b)};
      if (cur == s.end())
        break;
      s.erase(cur);
      res.emplace_back(a, b);
      x = a;
    }

    if (!s.empty())
      continue;

    std::cout << "YES\n" << original_x << '\n';
    for (const auto &p : res)
      std::cout << p.first << ' ' << p.second << '\n';
    return;
  }
  std::cout << "NO\n";
}

int main()
{
  int t{};
  std::cin >> t;

  for (int i{0}; i < t; ++i)
    solve();

  return 0;
}
