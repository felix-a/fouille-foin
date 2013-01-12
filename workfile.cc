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
document_map_ptr_2 = 0;
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
void WorkFile::grab_document_map(std::map<size_t, Document*> * document_map_ptr)
{
doc_map_address=reinterpret_cast<std::uint64_t>(document_map_ptr);
document_map_ptr_2=document_map_ptr;
std::cout << "document map pointer " <<document_map_ptr_2 <<" or "<<doc_map_address <<std::endl;
m_map=(*document_map_ptr_2);
}
void WorkFile::put_workfile_in_object_fuck(std::string work_file_data,std::map<size_t, Document*> * document_map_ptr, 	FenetrePrincipale * pointer_principale_workfile)
{

//extract in between <documents-list> and </documents-list>
	size_t pos_docement_start = work_file_data.find("<documents-list>",0) + 16;
	size_t pos_docement_end = work_file_data.find("</documents-list>",0) -1;
	std::string document_string = work_file_data.substr(pos_docement_start,pos_docement_end - pos_docement_start);
  	std::cout << "Switched to tab with index " << document_string<< std::endl;
	size_t num_of_doc=0;
	size_t lenght_of_doc_string = document_string.size();
	bool end_of_doc_string=false;
	int start=0, end=0,start1=0, end1=0;
	std::string each_doc_string;
	while(end_of_doc_string==false) 
	{
	start=document_string.find("<ops:publication-reference",start1);
	end=document_string.find("</ops:publication-reference>",start1);
	std::cout <<start<<" " <<end<<std::endl;

	each_doc_string=document_string.substr(start,end - start);
	std::cout <<"cict next line"<<std::endl;
//  std::cout << "document map pointer" << doc_map_address <<std::endl;
//document_map_ptr=reinterpret_cast<std::map<size_t, Document*> *>(doc_map_address);
//	docmap_for_worklist=;
//  std::cout << "document map pointer" << document_map_ptr <<std::endl;
	std::cout <<"cict"<<std::endl; 
	(*document_map_ptr)[num_of_doc] = new Document;
	std::cout <<"cict"<<std::endl;
		
	size_t system_pos = each_doc_string.find("system=",0);
	size_t family_id_pos = each_doc_string.find("family-id",0);
	(*document_map_ptr)[num_of_doc]->set_system(each_doc_string.substr(system_pos+8,family_id_pos -system_pos-10));
	size_t end_line_family = each_doc_string.find(">\n",family_id_pos);
	(*document_map_ptr)[num_of_doc]->set_family_number(each_doc_string.substr(family_id_pos+11,end_line_family -family_id_pos-12));
	size_t document_id_type_pos = each_doc_string.find("document-id-type=",0);
	size_t end_line_document_id_type = each_doc_string.find(">\n",document_id_type_pos);
	(*document_map_ptr)[num_of_doc]->set_id_type(each_doc_string.substr(document_id_type_pos+18,end_line_document_id_type -document_id_type_pos-19));
	size_t country_in = each_doc_string.find("<country>",0);
	size_t country_out = each_doc_string.find("</country>",0);
	(*document_map_ptr)[num_of_doc]->set_country(each_doc_string.substr(country_in+9,country_out-country_in-9));
	size_t doc_num_in = each_doc_string.find ("<doc-number>",0);
	size_t doc_num_out = each_doc_string.find ("</doc-number>",0);
	(*document_map_ptr)[num_of_doc]->set_number(each_doc_string.substr(doc_num_in+12,doc_num_out-doc_num_in-12));
	size_t kind_in = each_doc_string.find("<kind>",0);
	size_t kind_out = each_doc_string.find("</kind>",0);
		(*document_map_ptr)[num_of_doc]->set_kind(each_doc_string.substr(kind_in+6,kind_out-kind_in-6));
	 start1=end+28;
	end1=end;
//  	std::cout << "Start " << start<< " end "<< end<< " length string "<<lenght_of_doc_string<< " "<<num_of_doc<< std::endl;

	/*std::cout << "country: "<< document_map[num_of_doc]->get_country() << std::endl;
	std::cout << "number: "<< document_map[num_of_doc]->get_number() << std::endl;
	std::cout << "kind: "<< document_map[num_of_doc]->get_kind() << std::endl;
	std::cout << "system: "<< document_map[num_of_doc]->get_system() << std::endl;
	std::cout << "family: "<< document_map[num_of_doc]->get_family_number() << std::endl;
	std::cout << "id type: "<< document_map[num_of_doc]->get_id_type() << std::endl;*/
	num_of_doc=num_of_doc+1;
	 if (end1 >= ( lenght_of_doc_string -30)) end_of_doc_string=true;
	}//while(end_of_doc_string=false);
	 
	size_t size_worklist = (*document_map_ptr).size();
std::cout << "size worklist: "<< size_worklist<< std::endl;
 	for (size_t i=0;i<size_worklist;i++)
	{
		std::string worklist_entry=(*document_map_ptr)[i]->get_country()+(*document_map_ptr)[i]->get_number() + (*document_map_ptr)[i]->get_kind();
std::cout << "worklist_entry: "<< worklist_entry << std::endl;
std::cout << "worklist_entry: "<< pointer_principale_workfile<< std::endl;
       		Gtk::TreeModel::Row worklist_row = *(pointer_principale_workfile->worklisttreeModel->append());
 		worklist_row[pointer_principale_workfile->tirroir_worklist.m_col_id] = i+1;
		worklist_row[pointer_principale_workfile->tirroir_worklist.m_col_name] = worklist_entry;//document_map[i]->get_country()+document_map[i]->get_number() + document_map[i]->get_kind();
	}
std::cout << "Bien ici ca va! Numero un"<< std::endl;
	//pointer_principale_workfile->worklist_combo.pack_start(pointer_principale_workfile->tirroir_worklist.m_col_id);
std::cout << "Bien ici ca va!"<< std::endl;
	pointer_principale_workfile->worklist_combo.set_active(1);
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
