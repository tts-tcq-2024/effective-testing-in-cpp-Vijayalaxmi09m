// misaligned.cpp
#include <iostream>
#include <cassert>
#include <string>

// Color definitions
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Function to format a color entry
std::string formatColorEntry(int index, const char* major, const char* minor) {
    return std::to_string(index) + " | " + std::string(major) + " | " + std::string(minor);
}

// Function to print the color map
int printColorMap() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

int main() {
    // The main function can be used for manual testing if needed
    printColorMap();
    return 0;
}
