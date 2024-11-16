#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iterator>
#include <utility>
#include <numeric>


class node { 		
	private:
		std::vector<std::pair<char, long>>* char_list = nullptr;
		node* left;
		node* right;

		ulong word_freq_sum = 0;
		long word_count = 0;
		
		void set_freq_sum();	


	public:

		node(std::vector<std::pair<char, long>>*);
		node();
		std::vector<bool>* code = nullptr;

		/**
		 * sum of frequency of char
		 */
		ulong get_freq_sum ();
		/**
		 * number of char in list
		 */
		long get_word_count ();
		
		void add_left_node(node*);
		void add_right_node(node*);

		node* left_node();
		node* right_node();

		std::vector<std::pair<char, long>>::iterator begin();
		std::vector<std::pair<char, long>>::iterator end();

};

typedef struct split_node {
	node* left_node;
	node* right_node;
} split_node;

#include "node.tpp"

#endif
