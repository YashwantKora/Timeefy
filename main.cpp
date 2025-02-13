#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    using namespace std::chrono;

    std::tm startTime{};
    startTime.tm_year = 2025 - 1900; 
    startTime.tm_mon = 1;            
    startTime.tm_mday = 14;
    startTime.tm_hour = 0;
    startTime.tm_min = 0;
    startTime.tm_sec = 0;

    std::time_t startTime_t = std::mktime(&startTime);
    system_clock::time_point start_point = system_clock::from_time_t(startTime_t);

    system_clock::time_point currentTime = system_clock::now();

    seconds diff = duration_cast<seconds>(currentTime - start_point);

    int days = diff.count() / 86400;      
    diff -= seconds(days * 86400);
    int hours = diff.count() / 3600;      
    diff -= seconds(hours * 3600);
    int minutes = diff.count() / 60;      
    int seconds_count = diff.count() % 60;

    std::cout << "It's Been:\n";
    std::cout << days << " days, "
              << hours << " hours, "
              << minutes << " minutes, "
              << seconds_count << " seconds" << std::endl;

    return 0;
}
