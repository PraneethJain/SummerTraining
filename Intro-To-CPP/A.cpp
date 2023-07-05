#include <iostream>
#include <set>

int main()
{
  int n{};
  std::cin >> n;
  std::set<int> s;
  int c{};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> c;
    s.insert(c);
  }

  if (s.size() == 1)
  {
    std::cout << "NO\n";
  }
  else
  {
    int i{0};
    for (const auto &z : s)
    {
      if (i == 1)
      {
        std::cout << z << '\n';
      }
      ++i;
    }
  }

  return 0;
}
