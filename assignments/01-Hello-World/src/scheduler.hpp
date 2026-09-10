#pragma once

#include <array>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using MeetingTimes = std::unordered_map<int, std::array<double, 2>>;

double timeStringToDecimal(const std::string &timeStr);

int firstAlgorithm(const MeetingTimes &meeting_times);

int secondAlgorithm(const MeetingTimes &meeting_times);
