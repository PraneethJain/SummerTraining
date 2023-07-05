#include <iostream>
#include <vector>

using ll = long long;

void solve()
{
  int n{};
  std::cin >> n;

  std::vector<ll> positives;
  std::vector<ll> negatives;
  bool possible{false};
  ll cur{};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> cur;
    if (cur >= 0)
      positives.push_back(cur);
    else
      negatives.push_back(cur);

    if (cur != 0)
      possible = true;
  }

  if (!possible)
  {
    std::cout << "No" << '\n';
    return;
  }

  std::cout << "Yes" << '\n';
  ll cur_sum{0};
  for (int i{0}; i < n; ++i)
  {
    if (cur_sum > 0)
    {
      std::cout << negatives.back() << ' ';
      cur_sum += negatives.back();
      negatives.pop_back();
    }
    else
    {
      std::cout << positives.back() << ' ';
      cur_sum += positives.back();
      positives.pop_back();
    }
  }
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
