#include <iostream>
#include <map>
#include <string>

using ll = long long;

int main()
{
  int q{};
  std::cin >> q;

  int x{}, y{};
  std::string n;
  std::map<std::string, ll> m;
  for (int i{0}; i < q; ++i)
  {
    std::cin >> x;
    std::cin >> n;

    if (x == 1)
    {
      std::cin >> y;
      m[n] += y;
    }
    else if (x == 2)
    {
      m[n] = 0;
    }
    else
    {
      if (m.count(n) == 0)
      {
        std::cout << "0\n";
      }
      else
      {
        std::cout << m[n] << '\n';
      }
    }
  }

  return 0;
}
