#include "helper.cpp"
#include "helper.h"
#include <iostream>
#include <iterator>

template<typename Container>
void print_container(const Container& container)
{
    // Use auto to automatically deduce the type of the iterator
    for (auto iter = std::begin(container); iter != std::end(container); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {

	std::string prova_split = "3:00:00";
	auto risultato_split = split_string(prova_split);
	print_container(risultato_split);
	
	return 0;
}
