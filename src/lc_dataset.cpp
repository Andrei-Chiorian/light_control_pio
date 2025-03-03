#include <lc_dataset.h>

// Sun info array

const int months[12][32][4] = {
    // This array contains the sunrise and sunset times for each day of the month,
    // the brightness of the LED and the duration of the sunrises and sunsets.
    // ?Check the array that corresponds to January for more information
    {
        // january
        {8, 38, 17, 58}, // sunrise_hour, sunrise_minute, sunset_hour, sunset_minute
        {8, 38, 17, 59},
        {8, 38, 18, 0},
        {8, 38, 18, 1},
        {8, 38, 18, 1}, // 5th
        {8, 38, 18, 2},
        {8, 38, 18, 3},
        {8, 38, 18, 4},
        {8, 38, 18, 5},
        {8, 38, 18, 6}, // 10th
        {8, 37, 18, 7},
        {8, 37, 18, 9},
        {8, 37, 18, 10},
        {8, 37, 18, 11},
        {8, 36, 18, 12}, // 15th
        {8, 36, 18, 13},
        {8, 35, 18, 14},
        {8, 35, 18, 15},
        {8, 34, 18, 16},
        {8, 34, 18, 18}, // 20th
        {8, 33, 18, 19},
        {8, 32, 18, 20},
        {8, 32, 18, 21},
        {8, 31, 18, 22},
        {8, 30, 18, 23}, // 25th
        {8, 30, 18, 25},
        {8, 29, 18, 26}, //
        {8, 28, 18, 27},
        {8, 27, 18, 28},
        {8, 26, 18, 29},
        {8, 25, 18, 31},     // 31st
        {180, 1800, 2700, 0} // index 31 of array contains max brightness "max_i" in january - sunrise duration in seconds in january - sunset duration in seconds in january
    },
    {// february
        {8, 24, 18, 32},
        {8, 23, 18, 33},
        {8, 22, 18, 34},
        {8, 21, 18, 36},
        {8, 20, 18, 37},
        {8, 19, 18, 38},
        {8, 18, 18, 39},
        {8, 17, 18, 40},
        {8, 16, 18, 42},
        {8, 15, 18, 43},
        {8, 13, 18, 44},
        {8, 12, 18, 45},
        {8, 11, 18, 46},
        {8, 10, 18, 48},
        {8, 8, 18, 49},
        {8, 7, 18, 50},
        {8, 6, 18, 51},
        {8, 5, 18, 52},
        {8, 3, 18, 54},
        {8, 2, 18, 55},
        {8, 0, 18, 56},
        {7, 59, 18, 57},
        {7, 58, 18, 58},
        {7, 56, 18, 59},
        {7, 55, 19, 1}, //
        {7, 53, 19, 2},
        {7, 52, 19, 3},
        {7, 50, 19, 4},
        {7, 49, 19, 5},
        {0, 0, 0, 0}, // this type of index is for filling the rest of the month if its not 31 days (index 30) so february max days 29 we got 2 empty indexes
        {0, 0, 0, 0},
        {190, 1800, 2700, 0}},
    {// march
        {7, 49, 19, 5},
        {7, 47, 19, 6},
        {7, 46, 19, 7},
        {7, 44, 19, 8},
        {7, 43, 19, 9},
        {7, 41, 19, 11},
        {7, 39, 19, 12},
        {7, 38, 19, 13},
        {7, 36, 19, 14},
        {7, 35, 19, 15},
        {7, 33, 19, 16},
        {7, 32, 19, 17},
        {7, 30, 19, 18},
        {7, 28, 19, 19},
        {7, 27, 19, 20},
        {7, 25, 19, 21},
        {7, 23, 19, 22},
        {7, 22, 19, 23},
        {7, 20, 19, 24},
        {7, 19, 19, 26},
        {7, 17, 19, 27},
        {7, 15, 19, 28},
        {7, 14, 19, 29},
        {7, 12, 19, 30},
        {7, 10, 19, 31},
        {7, 9, 19, 32},
        {7, 7, 19, 33},
        {7, 5, 19, 34},
        {7, 4, 19, 35},
        {7, 2, 19, 36},
        {7, 1, 19, 37},
        {200, 2100, 2400, 0}},
    {// april
        {6, 59, 19, 38},
        {6, 57, 19, 39},
        {6, 56, 19, 40},
        {6, 54, 19, 41},
        {6, 52, 19, 42},
        {6, 51, 19, 43},
        {6, 49, 19, 44},
        {6, 48, 19, 45},
        {6, 46, 19, 46},
        {6, 45, 19, 47},
        {6, 43, 19, 48},
        {6, 41, 19, 49},
        {6, 40, 19, 50},
        {6, 38, 19, 51},
        {6, 37, 19, 52},
        {6, 35, 19, 53},
        {6, 34, 19, 54},
        {6, 32, 19, 55},
        {6, 31, 19, 57},
        {6, 29, 19, 58},
        {6, 28, 19, 59},
        {6, 27, 20, 0},
        {6, 25, 20, 1},
        {6, 24, 20, 2},
        {6, 22, 20, 3},
        {6, 21, 20, 4},
        {6, 20, 20, 5},
        {6, 18, 20, 6},
        {6, 17, 20, 7},
        {6, 16, 20, 8},
        {0, 0, 0, 0},
        {200, 2400, 2100, 0}},
    {// may
        {6, 15, 20, 9},
        {6, 13, 20, 10},
        {6, 12, 20, 11},
        {6, 11, 20, 12},
        {6, 10, 20, 13},
        {6, 9, 20, 14},
        {6, 7, 20, 15},
        {6, 6, 20, 16},
        {6, 5, 20, 17},
        {6, 4, 20, 18},
        {6, 3, 20, 19},
        {6, 2, 20, 20},
        {6, 1, 20, 21},
        {6, 0, 20, 22},
        {5, 59, 20, 23},
        {5, 58, 20, 24},
        {5, 57, 20, 25},
        {5, 56, 20, 26},
        {5, 56, 20, 27},
        {5, 55, 20, 27},
        {5, 54, 20, 28},
        {5, 53, 20, 29},
        {5, 53, 20, 30},
        {5, 52, 20, 31},
        {5, 51, 20, 32},
        {5, 51, 20, 33},
        {5, 50, 20, 33},
        {5, 49, 20, 34},
        {5, 49, 20, 35},
        {5, 48, 20, 36},
        {5, 48, 20, 37},
        {210, 2700, 1800, 0}},
    {// june
        {5, 47, 20, 37},
        {5, 47, 20, 38},
        {5, 47, 20, 39},
        {5, 46, 20, 39},
        {5, 46, 20, 40},
        {5, 46, 20, 41},
        {5, 46, 20, 41},
        {5, 45, 20, 42},
        {5, 45, 20, 42},
        {5, 45, 20, 43},
        {5, 45, 20, 43},
        {5, 45, 20, 44},
        {5, 45, 20, 44},
        {5, 45, 20, 45},
        {5, 45, 20, 45},
        {5, 45, 20, 45},
        {5, 45, 20, 46},
        {5, 45, 20, 46},
        {5, 45, 20, 46},
        {5, 45, 20, 47},
        {5, 46, 20, 47},
        {5, 46, 20, 47},
        {5, 46, 20, 47},
        {5, 46, 20, 47},
        {5, 47, 20, 47},
        {5, 47, 20, 47},
        {5, 47, 20, 47},
        {5, 48, 20, 47},
        {5, 48, 20, 47},
        {5, 49, 20, 47},
        {0, 0, 0, 0},
        {220, 3000, 1800, 0}},
    {// july
        {5, 49, 20, 47},
        {5, 50, 20, 47},
        {5, 50, 20, 47},
        {5, 51, 20, 47},
        {5, 51, 20, 46},
        {5, 52, 20, 46},
        {5, 53, 20, 46},
        {5, 53, 20, 45},
        {5, 54, 20, 45},
        {5, 55, 20, 45},
        {5, 55, 20, 44},
        {5, 56, 20, 44},
        {5, 57, 20, 43},
        {5, 57, 20, 43},
        {5, 58, 20, 42},
        {5, 59, 20, 41},
        {6, 0, 20, 41},
        {6, 1, 20, 40},
        {6, 1, 20, 39},
        {6, 2, 20, 39},
        {6, 3, 20, 38},
        {6, 4, 20, 37},
        {6, 5, 20, 36},
        {6, 6, 20, 35},
        {6, 7, 20, 35},
        {6, 7, 20, 34},
        {6, 8, 20, 33},
        {6, 9, 20, 32},
        {6, 10, 20, 31},
        {6, 11, 20, 30},
        {6, 12, 20, 29},
        {220, 3000, 1800, 0}},
    {// august
        {6, 13, 20, 28},
        {6, 14, 20, 27},
        {6, 15, 20, 25},
        {6, 16, 20, 24},
        {6, 17, 20, 23},
        {6, 18, 20, 22},
        {6, 19, 20, 21},
        {6, 20, 20, 20},
        {6, 21, 20, 18},
        {6, 22, 20, 17},
        {6, 23, 20, 16},
        {6, 24, 20, 14},
        {6, 25, 20, 13},
        {6, 25, 20, 12},
        {6, 26, 20, 10},
        {6, 27, 20, 9},
        {6, 28, 20, 8},
        {6, 29, 20, 6},
        {6, 30, 20, 5},
        {6, 31, 20, 3},
        {6, 32, 20, 2},
        {6, 33, 20, 0},
        {6, 34, 19, 59},
        {6, 35, 19, 57},
        {6, 36, 19, 56},
        {6, 37, 19, 54},
        {6, 38, 19, 53},
        {6, 39, 19, 51},
        {6, 40, 19, 50},
        {6, 41, 19, 48},
        {6, 42, 19, 47},
        {220, 2700, 1800, 0}},
    {// september
        {6, 43, 19, 45},
        {6, 44, 19, 43},
        {6, 45, 19, 42},
        {6, 46, 19, 40},
        {6, 47, 19, 38},
        {6, 48, 19, 37},
        {6, 49, 19, 35},
        {6, 50, 19, 34},
        {6, 50, 19, 32},
        {6, 51, 19, 30},
        {6, 52, 19, 29},
        {6, 53, 19, 27},
        {6, 54, 19, 25},
        {6, 55, 19, 24},
        {6, 56, 19, 22},
        {6, 57, 19, 20},
        {6, 58, 19, 19},
        {6, 59, 19, 17},
        {7, 0, 19, 15},
        {7, 1, 19, 14},
        {7, 2, 19, 12},
        {7, 3, 19, 10},
        {7, 4, 19, 9},
        {7, 5, 19, 7},
        {7, 6, 19, 5},
        {7, 7, 19, 4},
        {7, 8, 19, 2},
        {7, 9, 19, 0},
        {7, 10, 18, 59},
        {7, 11, 18, 57},
        {0, 0, 0, 0},
        {210, 2400, 2100, 0}},
    {// october
        {7, 12, 18, 55},
        {7, 13, 18, 54},
        {7, 14, 18, 52},
        {7, 15, 18, 50},
        {7, 16, 18, 49},
        {7, 17, 18, 47},
        {7, 18, 18, 46},
        {7, 19, 18, 44},
        {7, 20, 18, 42},
        {7, 21, 18, 41},
        {7, 22, 18, 39},
        {7, 23, 18, 38},
        {7, 24, 18, 36},
        {7, 25, 18, 35},
        {7, 26, 18, 33},
        {7, 27, 18, 32},
        {7, 28, 18, 30},
        {7, 29, 18, 29},
        {7, 31, 18, 27},
        {7, 32, 18, 26},
        {7, 33, 18, 24},
        {7, 34, 18, 23},
        {7, 35, 18, 22},
        {7, 36, 18, 20},
        {7, 37, 18, 19},
        {7, 38, 18, 18},
        {7, 39, 18, 16},
        {7, 41, 18, 15},
        {7, 42, 18, 14},
        {7, 43, 18, 13},
        {7, 44, 18, 11},
        {200, 2100, 2400, 0}},
    {// november
        {7, 45, 18, 10},
        {7, 46, 18, 9},
        {7, 47, 18, 8},
        {7, 49, 18, 7},
        {7, 50, 18, 6},
        {7, 51, 18, 5},
        {7, 52, 18, 3},
        {7, 53, 18, 2},
        {7, 54, 18, 1},
        {7, 56, 18, 0},
        {7, 57, 18, 0},
        {7, 58, 17, 59},
        {7, 59, 17, 58},
        {8, 0, 17, 57},
        {8, 1, 17, 56},
        {8, 3, 17, 55},
        {8, 4, 17, 55},
        {8, 5, 17, 54},
        {8, 6, 17, 53},
        {8, 7, 17, 52},
        {8, 8, 17, 52},
        {8, 9, 17, 51},
        {8, 10, 17, 51},
        {8, 12, 17, 50},
        {8, 13, 17, 50},
        {8, 14, 17, 49},
        {8, 15, 17, 49},
        {8, 16, 17, 48},
        {8, 17, 17, 48},
        {8, 18, 17, 48},
        {0, 0, 0, 0},
        {190, 1800, 2700, 0}},
    {// december
        {8, 19, 17, 48},
        {8, 20, 17, 47},
        {8, 21, 17, 47},
        {8, 22, 17, 47},
        {8, 23, 17, 47},
        {8, 24, 17, 47},
        {8, 25, 17, 47},
        {8, 26, 17, 47},
        {8, 26, 17, 47},
        {8, 27, 17, 47},
        {8, 28, 17, 47},
        {8, 29, 17, 47},
        {8, 30, 17, 47},
        {8, 30, 17, 48},
        {8, 31, 17, 48},
        {8, 32, 17, 48},
        {8, 32, 17, 49},
        {8, 33, 17, 49},
        {8, 34, 17, 49},
        {8, 34, 17, 50},
        {8, 35, 17, 50},
        {8, 35, 17, 51},
        {8, 36, 17, 51},
        {8, 36, 17, 52},
        {8, 36, 17, 53},
        {8, 37, 17, 53},
        {8, 37, 17, 54},
        {8, 37, 17, 55},
        {8, 38, 17, 55},
        {8, 38, 17, 56},
        {8, 38, 17, 57},
        {180, 1800, 3000, 0}}};
