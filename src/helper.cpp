#include "helper.h"
#include <algorithm>
#include <array>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

Tempi extract_fields(std::string tempo_str) {

  Tempi campi{0, 0, 0};

  auto res = split_string(tempo_str);

  if (res.size() > 3) {
    throw std::exception();
  };

  // since the vector might not be full as in of dimension 3 then reading from
  // the back is the best way, and it is already zeroed anyway
  Tempi::reverse_iterator it2 = campi.rbegin();
  // iterating for all the elements in res, since res.size() <= campi.size(), so
  // we might leave zeroed fields
  for (auto it1 = res.rbegin(); it1 != res.rend(); it1++, it2++) {
    *it2 = std::stoi(*it1);
  }

  std::cout << std::endl;
  return campi;
}

int operator*(Tempi tempi, std::array<int, 3>) {
  int somma{0};
  for (int psi = 0; psi < time_fields_t; psi++) {
    somma += tempi[psi] * weights[psi];
  }
  return somma;
}

int total_seconds(const Tempi &times) {
  // each field, from the first, mulitplied by the conversion number to seconds
  // and summed
  return times * weights;
};

std::vector<std::string> split_string(std::string &input) {

  std::vector<std::string> pieces;
  std::string::iterator begin = input.begin();
  // not to be initialized as it is anyway set before usage
  std::size_t end;

  std::size_t pos{time_fields_t};

  for (std::string::iterator it = input.begin(); it != input.end() + 1;
       it++) {
    // to include the final part, which is not postfixed by a ':', the string
    // end is used
    if (*it == ':' || it == input.end()) {
      // where the sought character is found wrt the beginnning, as an index
      std::size_t found = std::distance(input.begin(), it);
      // where the beginning of the substring is wrt the beginnind, as an index
      std::size_t beginning = std::distance(input.begin(), begin);
      // cut the string from after last ':' to before next one or before end
      auto single_piece = input.substr(beginning, found - beginning);
      pieces.push_back(single_piece);

      // std::cout << pezzo << '\n';

      // move the beginning of next string to the place after the found char
      begin = it + 1;
    };
  };

  std::cout << std::endl;

  return pieces;
}
