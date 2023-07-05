#include <iostream>
#include <queue>

using ll = long long;

int main()
{
  int n{};
  std::cin >> n;
  std::priority_queue<ll> q{};
  ll res{0};
  ll cur{};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> cur;
    q.push(-cur);
    if (cur > -q.top())
    {
      res += cur + q.top();
      q.pop();
      q.push(-cur);
    }
  }

  std::cout << res << '\n';

  return 0;
}
