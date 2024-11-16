#include "shannan_fano/coding.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <utility>
#include <fstream>
#include <string>


int main() {
	std::string file_path;
	std::cout << "Enter the text file path: ";
	std::cin >> file_path;

	sfcoding* encoder = new sfcoding(file_path);

	sfcoding_result* result = encoder->encode();

	int bit_count = 0;

	if (result->encoded_codes) {
		std::cout << "Codes are genrated." << std::endl;

		for (auto ec : *(result->encoded_codes)) {
			std::cout << "char: " << ec.first->letter << " | freq: " << ec.first->freq << " | codes: ";
			int char_bit = 0;
			for (auto bit: *(ec.second)) {
				std::cout << bit;
				char_bit++;
			};
			
			std::cout << " | total-bits: " << ((ec.first->freq) * char_bit);
			bit_count += ((ec.first->freq) * char_bit);
			std::cout << std::endl;
		}
	}

	std::cout << "Size of compressd text data " << bit_count << std::endl;
	std::cout << "Program Executed Sucessfully." << std::endl;
	
	return 0;
}
