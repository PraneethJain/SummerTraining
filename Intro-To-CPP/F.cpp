#include <iostream>
#include <string>

int main()
{
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);
  std::string str{}, sub{}, res{};
  std::cin >> str;
  std::cin >> sub;

  for (const char &c : str)
  {
    res += c;
    auto res_size{res.size()};
    auto sub_size{sub.size()};
    if (res_size < sub_size)
      continue;

    if (res.substr(res_size - sub_size, res_size) == sub)
      res.resize(res_size - sub_size);
  }
  std::cout << res << '\n';
  return 0;
}
