#include "fileres.h"
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <numeric>
#include <cstdio>
#include <algorithm>
	
FileResolver::FileResolver(const std::string file_path) {
	this->file_path = file_path;
};

attributes* FileResolver::resolve_text() {
	if (file_attr != nullptr) return file_attr;

	std::vector<std::pair<char, long>>* char_list = new std::vector<std::pair<char, long>>();

	std::ifstream fin (this->file_path);

	if (!fin.is_open()) {
		throw std::ifstream::failure("Could Note Open File: "+this->file_path);
	}
	
	std::filebuf* fbuf = fin.rdbuf();
	auto fileBuffer = fin.rdbuf();
	
	ulong wfsum = 0, wcount = 0;
	char c = fbuf->sbumpc();

	while (c != EOF) { // End Of File
		//std::cout << "char : " << c ;
		auto it = std::find_if(char_list->begin(), char_list->end(), [c] (const std::pair<char, long> a) {
			return (c == a.first); 
		});

		if (it != char_list->end()) {
			it->second++;
			//std::cout << " (duplicate found). freq: " << it->second << "char: " << it->first; 
		} else {
			char_list->push_back(std::pair(c, 1));
		}
		wfsum++;
		c = fbuf->sbumpc();
		//std::cout << std::endl;
	}

	fin.close();
	
	std::sort(char_list->begin(), char_list->end(), [](const std::pair<char, long> a, const std::pair<char, long> b) {
		return (a.second > b.second);
	});

	//char_list->pop_back();
	//char_list->shrink_to_fit();

	this->file_attr = (attributes*) malloc(sizeof(attributes));
	file_attr->char_list = char_list;
	file_attr->wfsum = --wfsum;
	file_attr->wcount = char_list->size();

	return file_attr;
};

