#include "test_framework/generic_test.h"
long long Gcd(long long x, long long y) {
  long long t = y;
  x = x < y ? t = x, y : x;
  y = x == y ? t : y;

  while (y != 0) {
    t = y;
    y = x % y;
    x = t;
  }

  return x;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "euclidean_gcd.cc", "gcd.tsv", &Gcd,
                         DefaultComparator{}, param_names);
}
