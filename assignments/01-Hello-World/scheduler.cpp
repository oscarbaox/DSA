#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using MeetingTimes = std::unordered_map<int, std::array<double, 2>>;

double timeStringToDecimal(const std::string &timeStr) {
    int hours = 0;
    int minutes = 0;

    // Reads two integers separated by a colon
    if (std::sscanf(timeStr.c_str(), "%d:%d", &hours, &minutes) == 2) {
        return hours + (minutes / 60.0);
    }
    return 0.0; // Fallback or handle invalid input
}

int firstAlgorithm(const MeetingTimes &meeting_times) {

    for (size_t i = 1; i < meeting_times.size() + 1; i++) {
        for (size_t j = i + 1; j < meeting_times.size() + 1; j++) {
            // Double interation to compare all pairs of meetings
            double s1 = meeting_times.at(i)[0], e1 = meeting_times.at(i)[1];
            double s2 = meeting_times.at(j)[0], e2 = meeting_times.at(j)[1];

            if (s1 < e2 && s2 < e1) {
                std::cout << "CONFLICT FOUND" << std::endl;
                std::cout << s1 << '-' << e1 << "; " << s2 << '-' << e2 << std::endl;
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}

int main(int argc, const char **argv) {
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

    // Using the first algorithm
    // if (!firstAlgorithm(meeting_times)) {
    //     return EXIT_FAILURE;
    // }

    // Second algorithm
    std::vector<std::array<double, 2>> times_vector;
    times_vector.reserve(meeting_times.size());

    // Discarding the id and flattening this into a vector cuz idk why i used a map to start with
    for (const auto &[idx, times] : meeting_times) {
        times_vector.push_back(times);
    }

    std::sort(times_vector.begin(), times_vector.end());

    for (size_t i = 0; i < times_vector.size() - 1; i++) {
        if (times_vector[i][1] > times_vector[i + 1][0]) {
            std::cout << "CONFLICT FOUND2" << std::endl;
            std::cout << "End: " << times_vector[i][1] << ", Start: " << times_vector[i + 1][0]
                      << '\n';
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
