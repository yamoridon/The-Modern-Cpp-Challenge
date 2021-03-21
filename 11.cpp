#include <iostream>
#include <string>
#include <utility>
#include <vector>

auto to_roman(unsigned int value) -> std::string {
  std::vector<std::pair<unsigned int, char const*>> const roman{
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};
  std::string result;
  for (auto const& [num, str] : roman) {
    while (value >= num) {
      result += str;
      value -= num;
    }
  }
  return result;
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  for (int i = 1; i <= 100; ++i) {
    std::cout << i << "\t" << to_roman(i) << std::endl;
  }

  int number = 0;
  std::cout << "number:";
  std::cin >> number;
  std::cout << to_roman(number) << std::endl;
}
