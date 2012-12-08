
#include <iostream>
#include "searchhistory.h"

Searchhistory::Searchhistory()
{
total_num_string=0;
string_number_V=0;

}

size_t Searchhistory::add_seach_string(std::string laststring){


total_num_string++;
 

 search_string_map[string_number_V]=new SearchString;

search_string_map[string_number_V]->add_search_string(laststring);
//search_string_map[string_number]->get_search_string();
std::cout <<"the string number " << string_number_V << "is :" << search_string_map[string_number_V]->get_search_string()<<std::endl;
string_number_V = string_number_V+1;
std::cout <<"the string number " << string_number_V << "::"<< total_num_string<<std::endl;
/*
switch(total_num_string){
	case 1:
	search_string_1=laststring;
	break;

	case 2:
	search_string_2=laststring;
	break;

	case 3:
	search_string_3=laststring;
	break;

	case 4:
	search_string_4=laststring;
	break;

	case 5:
	search_string_5=laststring;
	break;

	case 6:
	search_string_6=laststring;
	break;

	case 7:
	search_string_7=laststring;
	break;

	case 8:
	search_string_8=laststring;
	break;

	case 9:
	search_string_9=laststring;
	break;

	case 10:
	search_string_10=laststring;
	break;

}
*/

return total_num_string;



};

std::string Searchhistory::get_search_string(size_t string_num){

/*
switch(string_num){
	case 1:
	return search_string_1;
	break;

	case 2:
	return search_string_2;
	break;

	case 3:
	return search_string_3;
	break;

	case 4:
	return search_string_4;
	break;

	case 5:
	return search_string_5;
	break;

	case 6:
	return search_string_6;
	break;

	case 7:
	return search_string_7;
	break;

	case 8:
	return search_string_8;
	break;

	case 9:
	return search_string_9;
	break;

	case 10:
	return search_string_10;
	break;
}
*/

std::string stringb=search_string_map[string_num-1]->get_search_string();

std::cout<<stringb<<std::endl;
return stringb;

};

size_t Searchhistory::get_number_of_search_strings(){
return total_num_string;
};

Searchhistory::~Searchhistory()
{

}
SearchString::SearchString()
{
searchstring="";
}
SearchString::~SearchString()
{

}
void SearchString::add_search_string(std::string string)
{
searchstring=string;
std::cout << "hi ha "<< std::endl;
}
std::string SearchString::get_search_string()
{
return searchstring;
}

