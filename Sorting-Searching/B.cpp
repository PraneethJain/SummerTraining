#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
  int n{};
  std::cin >> n;

  std::vector<int> W(2 * n);
  for (int i{0}; i < 2 * n; ++i)
    std::cin >> W[i];

  int res{std::numeric_limits<int>::max()};
  std::sort(W.begin(), W.end());
  for (int i{0}; i < 2 * n; ++i)
  {
    for (int j{i + 1}; j < 2 * n; ++j)
    {
      int k{0};
      bool ready{false};
      int ans{0};
      int a{}, b{};
      while (k < 2 * n)
      {
        if (k == i || k == j)
        {
          ++k;
          continue;
        }

        if (ready)
        {
          b = W[k];
          ans += std::abs(b - a);
          ready = false;
        }
        else
        {
          a = W[k];
          ready = true;
        }
        ++k;
      }
      res = std::min(res, ans);
    }
  }

  std::cout << res << '\n';

  return 0;
}
