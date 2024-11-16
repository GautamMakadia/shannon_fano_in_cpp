#ifndef SFCODING_H
#define SFCODING_H

#include "fileres.h"
#include "node.h"
#include "string"
#include <vector>
#include <map>
#include <iterator>
#include <utility>
#include <numeric>

typedef struct symbol {
	char letter;
	long freq;
} symbol;

typedef struct mapComp {
	bool operator() (const symbol* a, const symbol* b) const {
		return (a->freq >= b->freq);
	}
} mapComp;

typedef struct sfcoding_result {
	std::map<symbol*, std::vector<bool>*, mapComp>* encoded_codes;
} sfcoding_result;


class sfcoding {
	private:
		std::string file;
		sfcoding_result* results = nullptr;
		split_node* split_node_from (node* n);


	public:
		sfcoding() {};
		sfcoding(std::string);
		sfcoding_result* encode();
		sfcoding_result* generate_codes(attributes* file_attr);
};


#include "coding.tpp"

#endif
