#pragma once

#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

// Convert time_point to UTC time string
inline std::string time_to_str(const std::chrono::system_clock::time_point& tp) {
    auto in_time_t = std::chrono::system_clock::to_time_t(tp);
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&in_time_t), "%Y-%m-%d %X UTC");
    return ss.str();
}