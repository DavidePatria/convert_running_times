#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <tuple>

#include "helper.h"


int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "a time and a distance are needed" << std::endl;
    return 1;
  };

  // time passed as argment from command line
  std::string tempo_arg = argv[2];

  Tempi campi = extract_fields(tempo_arg);

  int tempo_in_s = total_seconds(campi);

  double to_hour = tempo_in_s / 3600.0;

  double km_h = std::stod(argv[1]) / to_hour;
  std::cout << km_h << std::setprecision(2) << " km/h" << std::endl;

  double sec_km = tempo_in_s / std::stod(argv[1]);

  int round_sec = static_cast<int>(std::round(sec_km));
  int minutes = std::floor(sec_km / 60);
  int seconds = round_sec % 60;

  // string to prepend "0" to in case
  std::string sec_formatted;

  if (seconds < 10) {
    std::string sec_formatted = "0" + std::to_string(seconds);
  } else {
    sec_formatted = std::to_string(seconds);
  }

  std::cout << minutes << ":" << sec_formatted << " min/km" << std::endl;

  return 0;
}

