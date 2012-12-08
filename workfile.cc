#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "workfile.h"
#include "fenetreprincipale.h"

WorkFile::WorkFile()
{
num_of_document=0;
num_of_search_string=0;
}

WorkFile::~WorkFile()
{
}
void WorkFile::add_document()
{
}
void WorkFile::remouve_document()
{
}
void WorkFile::save_workfile()
{
}
std::string WorkFile::load_workfile(std::string path_and_file)
{
	char *memblock;
	//std::string path_and_file = preference.getworkfile();
	std::ifstream work_file_txt ;//(path_and_file,std::ios::in|std::ios::binary|std::ios::ate);
        work_file_txt.open(path_and_file,std::ios::in|std::ios::binary|std::ios::ate);
//	if (work_file_txt.open(path_and_file,std::ios::in|std::ios::binary|std::ios::ate))
//	{
    std::ifstream::pos_type size = work_file_txt.tellg();
    memblock = new char [size];
    work_file_txt.seekg (0, std::ios::beg);
    work_file_txt.read (memblock, size);
    work_file_txt.close();

	std::string workfileinfo=memblock;
    std::cout << "the complete file content is in memory"<< std::endl;

    std::cout << workfileinfo<< std::endl;	
    delete[] memblock;
  //}
  //else std::cout << "Unable to open file"<< std::endl;
  return workfileinfo;
	work_file_txt.close();

}
int WorkFile::get_num_document()
{
return num_of_document;

}

Document::Document()
{
//doc_contry="CA";
//doc_number="2345678";
//id_type="docdb";
//family_number="4332122", 
//kind="A1";
}
Document::~Document()
{
}
void Document::set_system(std::string string)
{
system=string;
}
void Document::set_country(std::string string)
{
doc_country=string;
}
void Document::set_number(std::string string)
{
doc_number=string;
}
void Document::set_id_type(std::string string)
{
id_type=string;
}
void Document::set_family_number(std::string string)
{
family_number=string;
}
void Document::set_kind(std::string string)
{
kind=string;
}
std::string	Document::get_system()
{
return system;
}

std::string	Document::get_country()
{
return doc_country;
}
std::string	Document::get_number()
{
return doc_number;
}
std::string	Document::get_id_type()
{
return id_type;
}
std::string	Document::get_family_number()
{
return family_number;
}
std::string	Document::get_kind()
{
return kind;
}
