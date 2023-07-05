#include <iostream>
#include <vector>

using ll = long long;

void solve()
{
  int n{};
  ll q{};
  std::cin >> n >> q;

  std::vector<ll> A(n);
  for (int i{0}; i < n; ++i)
    std::cin >> A[i];

  ll cur_q{0};
  std::vector<bool> res(n, false);
  for (int i{n - 1}; i >= 0; --i)
  {
    res[i] = (cur_q >= A[i]) || (q > cur_q);
    if (cur_q < A[i] && q > cur_q)
      ++cur_q;
  }

  for (int i{0}; i < n; ++i)
    std::cout << res[i];
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
