#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <map>

class SearchString 
{
public:
SearchString();
virtual ~SearchString();
void add_search_string(std::string);
std::string get_search_string();
std::string searchstring;

};

class Searchhistory
{
public:
Searchhistory();
virtual ~Searchhistory();

 std::map<size_t, SearchString*>  search_string_map;


	size_t	add_seach_string(std::string);
	std::string get_search_string(size_t);
	size_t get_number_of_search_strings();
private:
std::string laststring, search_string_1, search_string_2, search_string_3, search_string_4, search_string_5, search_string_6, search_string_7, search_string_8, search_string_9, search_string_10;
size_t total_num_string;
size_t string_number_V;

};


#endif

