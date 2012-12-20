#ifndef WORKFILE_H
#define WORKFILE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
class FenetrePrincipale;

class Document
{
public:

Document();
virtual ~Document();

void	set_country(std::string string);
void	set_number(std::string string);
void	set_id_type(std::string string);
void	set_family_number(std::string string);
void	set_kind(std::string string);
void	set_system(std::string string);

std::string	get_country();
std::string	get_number();
std::string	get_id_type();
std::string	get_family_number();
std::string	get_kind();
std::string	get_system();

private:
std::string doc_country, doc_number, id_type, family_number, kind, system;

};


class WorkFile
{
public:

WorkFile();
virtual ~WorkFile();
	FenetrePrincipale * pointer_principale_worklist;

	void grab_document_map(std::map<size_t, Document*> *);
std::map<size_t, Document*> m_map, * document_map_ptr, * document_map_ptr_2;
	void put_workfile_in_object_fuck(std::string,std::map<size_t, Document*> *,	FenetrePrincipale *);

std::uint64_t  doc_map_address;
	void add_document();
	void remouve_document();
	std::string load_workfile(std::string);
	void save_workfile();
size_t num_of_document;
size_t num_of_search_string;
int get_num_document();
Document m_doc_1;
//get_document_num(size_t);




};


#endif
