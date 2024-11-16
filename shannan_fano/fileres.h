#ifndef FILERES_H
#define FILERES_H

#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

typedef struct attributes {
	std::vector<std::pair<char, long>>* char_list;
	ulong wfsum;
	long wcount;
} attributes;

class FileResolver {

	private:
		std::string file_path;
		attributes* file_attr = nullptr;	
	
	public:
		FileResolver (const std::string file_path);
		attributes* resolve_text ();
};

#include "fileres.tpp"
#endif
