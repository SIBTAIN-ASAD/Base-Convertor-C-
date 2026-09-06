#define main converter_menu_main
#include "../code.cpp"
#undef main
#include <cassert>

int main()
{
    assert(toBaseNumber(0, 16) == "0");
    assert(toBaseNumber(255, 16) == "FF");
    assert(toDecimal("ff", 16) == 255);
    assert(hexaToOcta("0") == "0");
    assert(hexaToOcta("0000") == "0");
    assert(hexaToOcta("A") == "12");
    assert(hexaToOcta("F") == "17");
    assert(hexaToOcta("ff") == "377");
    assert(hexaToOcta(string(200, 'F')) == "3" + string(266, '7'));
    for (int base : {2, 3, 4, 5, 6, 7, 8, 9, 10, 16})
    {
        for (int value = 0; value <= 10000; value += 37)
        {
            assert(toDecimal(toBaseNumber(value, base), base) == value);
            assert(hexaToOcta(toBaseNumber(value, 16)) == toBaseNumber(value, 8));
        }
        int maximum = numeric_limits<int>::max();
        assert(toDecimal(toBaseNumber(maximum, base), base) == maximum);
    }
    for (const string& invalid : {"", "-1", "/", "G", "1.0", " 1"})
        assert(!isValid(invalid, 16));
    assert(!isValid("2", 2));
    assert(!isValid("1", 1));
    bool overflow = false;
    try { toDecimal(to_string(static_cast<long long>(numeric_limits<int>::max()) + 1), 10); }
    catch (const overflow_error&) { overflow = true; }
    assert(overflow);
    cout << "All conversion tests passed\n";
}
