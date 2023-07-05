#include <iostream>
#include <map>
#include <vector>

using ll = long long;

int main()
{
  int n{}, k{};
  std::cin >> n >> k;
  std::vector<ll> arr(n, 0);

  for (int i{0}; i < n; ++i)
    std::cin >> arr[i];

  std::map<ll, int> m;
  ll res{0};
  int l{0}, r{0};
  while (r < n)
  {
    ++m[arr[r]];
    while (m.size() > k)
    {
      --m[arr[l]];
      !m[arr[l]] && m.erase(arr[l]);
      ++l;
    }
    res += r - l + 1;
    r++;
  }

  std::cout << res << '\n';

  return 0;
}
