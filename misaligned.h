// misaligned.h
#ifndef MISALIGNED_H
#define MISALIGNED_H

#include <string>

// External color arrays for major and minor color names
extern const char* majorColor[];
extern const char* minorColor[];

// Function to format a color entry for display
std::string formatColorEntry(int index, const char* major, const char* minor);

// Function to print the color map and return the number of entries
int printColorMap();

#endif // MISALIGNED_H
