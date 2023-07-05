#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

void print_vec(std::vector<std::pair<int, int>> v)
{
  for (const auto &x : v)
    std::cout << x.first << ' ' << x.second << '\n';
  std::cout << '\n';
}

int main()
{
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int N{};
  std::cin >> N;

  int d{};
  std::string name{};
  int delta{};
  std::set<std::tuple<int, std::string, int>> s;
  for (int i{0}; i < N; ++i)
  {
    std::cin >> d;
    std::cin >> name;
    std::cin >> delta;

    s.insert({d, name, delta});
  }

  std::vector<int> cur(3, 7);
  std::vector<std::vector<int>> days;

  for (const auto &x : s)
  {
    if (std::get<1>(x) == "Bessie")
    {
      cur = {cur[0] + std::get<2>(x), cur[1], cur[2]};
    }
    else if (std::get<1>(x) == "Elsie")
    {
      cur = {cur[0], cur[1] + std::get<2>(x), cur[2]};
    }
    else
    {
      cur = {cur[0], cur[1], cur[2] + std::get<2>(x)};
    }
    days.push_back(cur);
  }

  std::set<int> top;
  int res{0};
  for (const auto &day : days)
  {
    std::set<int> curTop;
    int max{*std::max_element(day.begin(), day.end())};
    if (day[0] == max)
    {
      curTop.insert(0);
    }
    if (day[1] == max)
    {
      curTop.insert(1);
    }
    if (day[2] == max)
    {
      curTop.insert(2);
    }

    if (curTop != top)
    {
      ++res;
      top = curTop;
    }
  }

  std::cout << res << '\n';

  return 0;
}
