#include "tshirts.h"

char size(float cms) {  // Change int to float
    char sizeName = '\0';
    if (cms <= 38.0) {
        sizeName = 'S';
    } else if (cms > 38.0 && cms <= 42.0) {
        sizeName = 'M';
    } else if (cms > 42.0) {
        sizeName = 'L';
    }
    return sizeName;
}
