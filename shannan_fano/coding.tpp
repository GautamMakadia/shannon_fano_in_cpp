#include "coding.h"
#include "node.h"

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <numeric>
#include <algorithm>

sfcoding::sfcoding(std::string file) {
	this->file = file;
};

sfcoding_result* sfcoding::generate_codes(attributes* file_attr) {

	node* root = new node(file_attr->char_list);
	
	root->code = new std::vector<bool>();
	
	sfcoding_result* result = (sfcoding_result*) malloc(sizeof(sfcoding_result));
	
	result->encoded_codes = new std::map<symbol*, std::vector<bool>*, mapComp>();
	
	std::queue<node>* node_queue = new std::queue<node>();
	node_queue->push(*root);

	while (!node_queue->empty()) {
		node n = node_queue->front();
		
		node_queue->pop();
		
		if (n.get_word_count() == 1) {
			try {	
				symbol* char_symb = (symbol*) malloc(sizeof(symbol));
				auto it = n.begin();

				char_symb->letter = it->first;
				char_symb->freq = it->second;
				std::cout << std::endl << "last node: " << char_symb->letter << std::endl << std::endl;

				result->encoded_codes->insert({char_symb, n.code});	     
				continue;
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			
		}


		std::cout << std::endl << "spliting node: ";
		for (auto ch = n.begin(); ch < n.end(); ch++) {
			std::cout << ch->first << ", ";
		}

		std::cout << n.get_freq_sum() << std::endl ;

		split_node* chiled = split_node_from(&n);

		n.add_left_node(chiled->left_node);
		n.add_right_node(chiled->right_node);

		node_queue->push(*(n.left_node()));
		node_queue->push(*(n.right_node()));
	}

	return result;
};

split_node* sfcoding::split_node_from(node* n) {
	split_node* sp_node = (split_node*) malloc(sizeof(split_node));

	if (sp_node == nullptr) {
		std::cout << "can't allocate split node." << std::endl;
		return nullptr;
	}

	std::vector<std::pair<char, long>>* l_list = new std::vector<std::pair<char, long>>();
	std::vector<std::pair<char, long>>* r_list = new std::vector<std::pair<char, long>>();

	int freq_sum = 0;
	ulong diff = 0;
	ulong right_diff = n->get_freq_sum();
	ulong total_distance = n->get_word_count();
	int mid = (n->get_freq_sum())/2;
	ulong prev_diff = 0;

	auto it = n->begin();
	
	std::cout << "mid: " << mid << ", left_node: ";
	do  {
		freq_sum += it->second;
		prev_diff = diff;
		diff = (n->get_freq_sum()) - (freq_sum);
		right_diff = (n->get_freq_sum()) - diff; 
		l_list->push_back(*(it));

		std::cout << it->first << ", ";
		it++;
	} while (!(freq_sum > mid) && !((right_diff - diff) <= 0));

	std::cout << " freq_sum : " << freq_sum << std::endl;
	
	node* left_node = new node(l_list);

	if (left_node == nullptr) {
		std::cout << "can't allocate left node." << std::endl;
		return nullptr;
	}

	std::cout << "right_node : ";
	for (it; it < n->end(); it++) {
		r_list->push_back(*(it));
		std::cout << it->first << ", ";
	}
	std::cout << " freq_sum : " << (n->get_freq_sum() - freq_sum) << std::endl;

	node* right_node = new node(r_list);
	
	if (right_node == nullptr) {
		std::cout << "can't allocate left node." << std::endl;
		return nullptr;
	}

	n->add_left_node(left_node);
	n->add_right_node(right_node);

	n->left_node()->code = new std::vector<bool>(*(n->code));
	n->left_node()->code->push_back(0);
	
	n->right_node()->code = new std::vector<bool>(*(n->code));
	n->right_node()->code->push_back(1);
	

	sp_node->left_node = n->left_node();
	sp_node->right_node = n->right_node();

	return sp_node;
};

sfcoding_result* sfcoding::encode() {
	FileResolver fileres(this->file);
	attributes* file_attr = nullptr;
	

	try {
		file_attr = fileres.resolve_text();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		std::cout << "programm terminated during extarcting data.";
		exit(1);
		return nullptr;
	}

	sfcoding_result* result = generate_codes(file_attr);

	return result;
};