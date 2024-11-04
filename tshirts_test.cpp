#include "tshirts.h"
#include <assert.h>
#include <iostream>

int main() {
    // Basic test cases
    assert(size(37) == 'S' && "Expected size to be 'S' for cms < 38");
    assert(size(40) == 'M' && "Expected size to be 'M' for 38 < cms < 42");
    assert(size(43) == 'L' && "Expected size to be 'L' for cms > 42");

    // **Boundary cases that should fail** (Expected failures)
    assert(size(38) == 'M' && "Expected size to be 'M' for cms = 38 (intentional failure)");
    assert(size(42) == 'L' && "Expected size to be 'L' for cms = 42 (intentional failure)");

    // Values just outside of typical ranges
    assert(size(38.1) == 'M' && "Expected size to be 'M' for cms = 38.1"); // Should pass
    assert(size(41.9) == 'M' && "Expected size to be 'M' for cms just under 42"); // Should pass

    // Extreme values that should not have defined sizes (Expected failures)
    assert(size(-5) == 'S' && "Expected failure: undefined for negative cms (intentional failure)");
    assert(size(1000) == 'S' && "Expected failure: undefined for very large cms (intentional failure)");

    std::cout << "All tests complete (some intentionally failed to test edge cases).\n";
    return 0;
}
