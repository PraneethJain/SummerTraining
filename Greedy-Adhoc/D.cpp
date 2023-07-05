#include <iostream>
#include <string>
#include <vector>

void solve()
{
  int n{};
  std::cin >> n;
  std::string s{};
  std::cin >> s;

  int count{0};
  std::vector<int> ones, zeros;
  std::vector<int> res(n);
  for (int i{0}; i < n; ++i)
  {
    char c = s[i];
    if ((c == '0' && ones.empty()) || (c == '1' && zeros.empty()))
    {
      ++count;
      if (c == '0')
        zeros.push_back(count);
      else
        ones.push_back(count);
      res[i] = count;
    }
    else
    {
      if (c == '0')
      {
        res[i] = ones.back();
        zeros.push_back(res[i]);
        ones.pop_back();
      }
      else
      {
        res[i] = zeros.back();
        ones.push_back(res[i]);
        zeros.pop_back();
      }
    }
  }

  std::cout << count << '\n';
  for (int i{0}; i < n; ++i)
    std::cout << res[i] << ' ';
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
