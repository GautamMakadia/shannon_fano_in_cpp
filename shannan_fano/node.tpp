#include "node.h"
#include <vector>
#include <numeric>
#include <utility>


node::node (std::vector<std::pair<char, long>>* char_list) {
	this->char_list = char_list;
	this->word_count = this->char_list->size();
	set_freq_sum();
};

node::node() {};

void node::set_freq_sum () {
	ulong sum = 0;

	for (auto it = this->char_list->begin(); it < this->char_list->end(); it++) {
		sum += it->second;
	}	

	this->word_freq_sum  = sum;
}

ulong node::get_freq_sum () {
	return this->word_freq_sum;
}

long node::get_word_count() {
	return this->word_count;
}

void node::add_left_node(node* n) {
	if (this->right == n) return; 

	this->left = n;
}

void node::add_right_node(node* n) {
	if (this->left != n)
		this->right = n;
}

node* node::left_node() {
	return (this->left);
}

node* node::right_node() {
	return (this->right);
}

std::vector<std::pair<char, long>>::iterator node::begin() {
	return (this->char_list->begin());
};

std::vector<std::pair<char, long>>::iterator node::end() {
	return (this->char_list->end());
};


