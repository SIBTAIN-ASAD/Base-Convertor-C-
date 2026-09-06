# Number base converter

An interactive C++ program for converting non-negative integers between bases
2 through 10 and hexadecimal (base 16). Hexadecimal input accepts either case;
output uses uppercase A–F.

## Build and run

Use a C++17 compiler such as GCC or Clang:

```sh
c++ -std=c++17 -Wall -Wextra -Werror code.cpp -o converter
./converter
```

Enter the source base, target base, then the number. For example, source `10`,
target `16`, number `255` produces `FF`. Choose an unsupported base and confirm
with `Y` to exit. End-of-input also exits cleanly.

General conversions support values up to the platform's `int` maximum and report
larger inputs without overflowing. The hexadecimal-to-octal path converts through
binary strings, so it supports numbers beyond that integer limit, subject to
available memory. Negative and fractional inputs are not supported.

## Tests

```sh
c++ -std=c++17 -Wall -Wextra -Werror -pedantic \
  -fsanitize=address,undefined tests/conversion_test.cpp -o conversion-test
./conversion-test
python3 tests/test_cli.py
```

The C++ tests cover round trips in every supported base, integer limits, zero,
hexadecimal digits, malformed input, and a 200-digit hexadecimal input. The Python
standard-library tests compile the program and exercise complete menu sessions,
including overflow errors and EOF. Set `CXX` to choose the compiler for those tests.
