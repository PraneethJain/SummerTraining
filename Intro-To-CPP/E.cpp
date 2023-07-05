#include <iostream>
#include <list>
#include <numeric>

int main()
{
  int n{};
  std::cin >> n;

  std::list<int> children(n);
  std::iota(children.begin(), children.end(), 1);

  auto it = children.begin();
  while (!children.empty())
  {
    ++it;
    if (it == children.end())
      it = children.begin();

    std::cout << *it << ' ';
    it = children.erase(it);
    if (it == children.end())
      it = children.begin();
  }

  std::cout << '\n';

  return 0;
}
