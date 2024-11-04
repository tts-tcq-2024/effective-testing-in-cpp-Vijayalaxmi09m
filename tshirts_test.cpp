#include "tshirts.h"
#include <assert.h>
#include <iostream>

int main() {
    // Basic test cases
    assert(size(37) == 'S' && "Expected size to be 'S' for cms < 38");
    assert(size(40) == 'M' && "Expected size to be 'M' for 38 < cms < 42");
    assert(size(43) == 'L' && "Expected size to be 'L' for cms > 42");

    // Boundary and edge cases
    assert(size(38) == 'S' && "Expected size to be 'S' for cms = 38"); // This should fail since 38 is not handled
    assert(size(42) == 'M' && "Expected size to be 'M' for cms = 42"); // This should fail because 42 is not returned as 'M'

    // Values just outside of typical ranges
    assert(size(38.1) == 'M' && "Expected size to be 'M' for cms = 38.1"); // Expected to fail if 38.1 does not map to 'M'
    assert(size(41.9) == 'M' && "Expected size to be 'M' for cms just under 42"); // Testing just under 42 boundary

    // Extreme values
    assert(size(100) == 'L' && "Expected size to be 'L' for a large cms value (100)");
    assert(size(-5) == '\0' && "Expected size to be undefined for negative cms values");

    // Additional edge cases
    assert(size(0) == '\0' && "Expected size to be undefined for zero cms");
    assert(size(42.1) == 'L' && "Expected size to be 'L' for cms just over 42"); // Test right above the 'M' range

    // Sanity check for large value
    assert(size(1000) == 'L' && "Expected size to be 'L' for extremely large cms values");

    std::cout << "All tests complete (some may fail to expose edge cases).\n";
    return 0;
}
