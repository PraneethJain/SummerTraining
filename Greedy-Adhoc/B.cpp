#include <algorithm>
#include <iostream>
#include <string>

using ll = long long;

int main()
{
  ll n{};
  std::cin >> n;

  std::string res{};
  while (n)
  {
    if (n & 1)
    {
      --n;
      res += 'A';
    }
    else
    {
      n >>= 1;
      res += 'B';
    }
  }

  std::reverse(res.begin(), res.end());
  std::cout << res << '\n';

  return 0;
}
