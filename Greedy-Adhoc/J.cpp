#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using ll = long long;

void solve()
{
  int n{};
  std::cin >> n;
  std::vector<std::vector<ll>> A(n, std::vector<ll>(n));
  for (int i{0}; i < n; ++i)
    for (int j{0}; j < n; ++j)
      std::cin >> A[i][j];

  auto valid = [&](int next_x, int next_y) { return next_x >= 0 && next_x < n && next_y >= 0 && next_y < n; };

  std::vector<std::vector<bool>> marked(n, std::vector<bool>(n, false));
  std::vector<std::vector<bool>> seen(n, std::vector<bool>(n, false));
  std::vector<std::pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  std::stack<std::pair<int, int>> s{};
  s.emplace(0, 0);
  ll res{0};
  while (!s.empty())
  {
    auto [x, y] = s.top();
    s.pop();
    if (seen[x][y])
      continue;
    seen[x][y] = true;

    bool all_unmarked{true};
    for (const auto &dir : directions)
    {
      auto [dx, dy] = dir;
      if (valid(x + dx, y + dy))
      {
        if (marked[x + dx][y + dy])
          all_unmarked = false;

        if (!seen[x + dx][y + dy])
        {
          s.emplace(x + dx, y + dy);
        }
      }
    }
    if (all_unmarked)
    {
      res ^= A[x][y];
      for (const auto &dir : directions)
      {
        auto [dx, dy] = dir;
        if (valid(x + dx, y + dy))
        {
          marked[x + dx][y + dy] = true;
        }
      }
    }
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
