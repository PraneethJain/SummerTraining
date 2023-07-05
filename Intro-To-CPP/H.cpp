#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using ll = long long;

int main()
{
  int n{}, k{};
  std::cin >> k >> n;

  std::vector<ll> A(k);
  for (int i{0}; i < k; ++i)
    std::cin >> A[i];
  std::inclusive_scan(A.begin(), A.end(), A.begin());

  std::vector<ll> B(n);
  for (int i{0}; i < n; ++i)
    std::cin >> B[i];

  std::vector<std::set<ll>> results;
  for (const auto &b : B)
  {
    std::set<ll> cur;
    for (const auto &a : A)
      cur.insert(b - a);
    results.push_back(cur);
  }

  std::set<ll> s =
    std::reduce(results.begin(), results.end(), results[0], [](const std::set<ll> &a, const std::set<ll> &b) {
      std::set<ll> res;
      std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(res, res.begin()));
      return res;
    });

  std::cout << s.size() << '\n';

  return 0;
}
