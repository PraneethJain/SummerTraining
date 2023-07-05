#include <iostream>
#include <set>

using ll = long long;

int main()
{
  int q{};
  std::cin >> q;

  int y{};
  ll x{};
  std::set<ll> s;
  for (int i{0}; i < q; ++i)
  {
    std::cin >> y >> x;
    if (y == 1)
    {
      s.insert(x);
    }
    else if (y == 2)
    {
      s.erase(x);
    }
    else
    {
      if (s.count(x) == 0)
      {
        std::cout << "No\n";
      }
      else
      {
        std::cout << "Yes\n";
      }
    }
  }
}
