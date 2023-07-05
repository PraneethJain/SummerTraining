#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

int main()
{
  int n{}, q{};
  std::cin >> n >> q;

  std::vector<ll> A(n);
  for (int i{0}; i < n; ++i)
    std::cin >> A[i];

  std::vector<std::pair<ll, ll>> arr(n, {0, 0});
  ll x{}, y{};
  for (int i{0}; i < q; ++i)
  {
    std::cin >> x >> y;
    --x;
    --y;
    arr[x].first++;
    arr[y].second++;
  }

  std::vector<ll> counts(n);
  ll count{0};
  for (int i{0}; i < n; ++i)
  {
    counts[i] = count + arr[i].first;
    count += arr[i].first - arr[i].second;
  }

  std::sort(counts.begin(), counts.end());
  std::sort(A.begin(), A.end());

  ll res{0};
  for (int i{n - 1}; i >= 0; --i)
    res += counts[i] * A[i];

  std::cout << res << '\n';

  return 0;
}
