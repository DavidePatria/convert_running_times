#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <array>
#include <vector>

constexpr std::size_t time_fields_t = 3;
typedef std::array<int, time_fields_t> Tempi;
// array of convertion values from the field unit (h,m,s) to seconds
constexpr std::array<int, time_fields_t> weights = {60 * 60, 60, 1};

// copy the string explicitly
Tempi extract_fields(std::string tempo_str);
int total_seconds(const Tempi &tempi);
std::vector<std::string> split_string(std::string& ingresso);

#endif
