#include <iostream>
#include <queue>

using ll = long long;

int main()
{
  int n{};
  std::cin >> n;

  std::priority_queue<ll> q;
  ll cur{};
  ll sum{0};
  ll res{0};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> cur;
    sum += cur;
    ++res;

    q.push(-cur);

    while (!q.empty() && sum < 0)
    {
      sum += q.top();
      q.pop();
      --res;
    }
  }

  std::cout << res << '\n';

  return 0;
}
