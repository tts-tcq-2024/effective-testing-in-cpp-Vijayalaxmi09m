// misaligned_test.cpp
#include "misaligned.h"
#include <assert.h>
#include <iostream>

void testFormatColorEntry() {
    // Basic test cases
    assert(formatColorEntry(0, "White", "Blue") == "0 | White | Blue");
    assert(formatColorEntry(24, "Violet", "Slate") == "24 | Violet | Slate");
    assert(formatColorEntry(5, "Red", "Blue") == "5 | Red | Blue");

    // Additional test cases
    // Testing with maximum index
    assert(formatColorEntry(24, "Black", "Brown") == "24 | Black | Brown");
    // Testing with lower boundary
    assert(formatColorEntry(1, "Red", "Orange") == "1 | Red | Orange");
    // Testing with invalid values (negative index)
    assert(formatColorEntry(-1, "White", "Blue") == "-1 | White | Blue"); // Edge case for negative index
    // Testing with large positive index
    assert(formatColorEntry(100, "Green", "Slate") == "100 | Green | Slate"); // Edge case for large index
}

void testPrintColorMap() {
    // Capture output for verification (you might need to redirect cout to a string stream)
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf()); // Redirect cout to buffer

    int result = printColorMap();

    // Restore original cout
    std::cout.rdbuf(prev);

    // Check the expected output and that the function works
    assert(result == 25); // Check if printColorMap returns 25 as expected

    // Validate the output format
    std::string expectedOutput;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            expectedOutput += std::to_string(i * 5 + j) + " | " + 
                              std::string(majorColor[i]) + " | " + 
                              std::string(minorColor[j]) + "\n";
        }
    }

    // Compare the buffer content with the expected output
    assert(buffer.str() == expectedOutput && "Output does not match expected color map format.");
}

int main() {
    testFormatColorEntry();
    testPrintColorMap();

    std::cout << "Misaligned tests complete.\n";
    return 0;
}
