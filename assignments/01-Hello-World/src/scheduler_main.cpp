#include "scheduler.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Open the text file for reading
    std::ifstream f("../meeting_times.txt");

    // Check if the file was opened successfully
    if (!f.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::string s; // each line of text
    int counter = 1;

    // An abomination of a thing, what the f is this, in Python this would have been a dict, over
    // Instead, we have to do an unordered map that contains an int as a key and a janky array
    // that could have been a [] that specifies the type and length. This is horrible
    std::unordered_map<int, std::array<double, 2>> meeting_times;

    while (std::getline(f, s)) {
        // Separating the two times
        size_t pos = s.find('-');
        std::string first, second; // Start and end time
        if (pos != std::string::npos) {
            first = s.substr(0, pos);
            second = s.substr(pos + 1);
        }

        meeting_times[counter] = {timeStringToDecimal(first), timeStringToDecimal(second)};
        counter += 1;
    }

    return secondAlgorithm(meeting_times);
}
