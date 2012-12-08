#include <string>
#include <fstream>
#include <iostream>
#include "preference.h"
#include "getnumfromstring.h"

Preference::Preference(){
//int Preference::nombre_tab()
read_pref_file();
	nombres_tab=2;
	y=0;
	a=0;

};

int Preference::type_panneau(){
	a=y       ;
y++;	
     // std::cout <<  "type1= " << y << std::endl;
	//	y=y+1;
      std::cout <<  "type+1= " << y << std::endl;
	return a;

};

Preference::~Preference()
{
}
void Preference::setworkfile(std::string workfile)
{
workfilepath=workfile;
}

std::string Preference::getworkfile()
{
return workfilepath;
};

void Preference::read_pref_file()
{
std::string line;
std::string preference_file_raw="";
std::ifstream preference_file; 
preference_file.open ("preference.txt");
if (preference_file.is_open()) 
{ 
    	while(preference_file.good())
    	{
      	getline (preference_file,line);
	preference_file_raw=preference_file_raw + line +"\n";
	}
	std::cout<<preference_file_raw<<std::endl;

	//find maximize widow bool value
	size_t maxi = preference_file_raw.find("<maximize>",0) + 10;
	size_t slash_maxi = preference_file_raw.find("</maximize>",maxi);
	std::cout << maxi << "  "<< slash_maxi<<std::endl;
	if ((maxi < slash_maxi) && ((maxi != std::string::npos) && (slash_maxi != std::string::npos)))
	{
	std::string string_maxi=preference_file_raw.substr(maxi, slash_maxi - maxi);
	std::cout<<"sssss: "<<string_maxi<<std::endl;
		if(string_maxi=="true") maximize_window = true;
		else if(string_maxi=="false") maximize_window = false;
		else {
			std::cout << "the maximize_widow's preference cannot be ascertain, using default"<< std::endl;
			maximize_window=false;
		}
	}
	else maximize_window=false;

	// find window' un-maximize positions and location
	//  x
	size_t num_pos_x =preference_file_raw.find ("<pos-x>",0)+7;
	size_t num_slash_pos_x =preference_file_raw.find ("</pos-x>",num_pos_x);
	std::cout << "pos X: "<<num_pos_x<<" "<< num_slash_pos_x <<std::endl;
	if ((num_pos_x < num_slash_pos_x) && ((num_pos_x != std::string::npos) && (num_slash_pos_x != std::string::npos)))
	{
	std::string string_pos_x=preference_file_raw.substr(num_pos_x, num_slash_pos_x - num_pos_x);
	int_pos_x = get_number_from_string_out( string_pos_x);
	std::cout << "pos X: "<<int_pos_x<<std::endl;
	}
	else int_pos_x = 205; //default 
	//  y
	size_t num_pos_y =preference_file_raw.find ("<pos-y>",0)+7;
	size_t num_slash_pos_y =preference_file_raw.find ("</pos-y>",num_pos_y);
	std::cout << "pos Y: "<<num_pos_y<<" "<< num_slash_pos_y <<std::endl;
	if ((num_pos_y < num_slash_pos_y) && ((num_pos_y != std::string::npos) && (num_slash_pos_y != std::string::npos)))
	{
	std::string string_pos_y=preference_file_raw.substr(num_pos_y, num_slash_pos_y - num_pos_y);
	int_pos_y = get_number_from_string_out( string_pos_y);
	std::cout << "pos Y: "<<int_pos_y<<std::endl;
	}
	else int_pos_y = 15; //default 
	//  height
	size_t num_height =preference_file_raw.find ("<size-x>",0)+8;
	size_t num_slash_height =preference_file_raw.find ("</size-x>",num_height);
	std::cout << "height: "<<num_height<<" "<< num_slash_height <<std::endl;
	if ((num_height < num_slash_height) && ((num_height != std::string::npos) && (num_slash_height != std::string::npos)))
	{
	std::string string_height=preference_file_raw.substr(num_height, num_slash_height - num_height);
	height = get_number_from_string_out( string_height);
	std::cout << "height: "<<height<<std::endl;
	}
	else height = 500; //default 
	//  width	
	size_t num_width =preference_file_raw.find ("<size-y>",0)+8;
	size_t num_slash_width =preference_file_raw.find ("</size-y>",num_width);
	std::cout << "width: "<<num_width<<" "<< num_slash_width <<std::endl;
	if ((num_width < num_slash_width) && ((num_width != std::string::npos) && (num_slash_width != std::string::npos)))
	{
	std::string string_width=preference_file_raw.substr(num_width, num_slash_width - num_width);
	width = get_number_from_string_out( string_width);
	std::cout << "width: "<<width<<std::endl;
	}
	else width = 900; //default 

	//workfile path
	size_t workfilepath_pos =preference_file_raw.find ("<workfile>",0)+10;
	size_t workfilepath_slash_pos=preference_file_raw.find ("</workfile>",workfilepath_pos);
	std::cout << "workfile path: "<<workfilepath_pos<<" "<< workfilepath_slash_pos <<std::endl;
	if ((workfilepath_pos < workfilepath_slash_pos) && ((workfilepath_pos != std::string::npos) && (workfilepath_slash_pos != std::string::npos)))
	{
	workfilepath=preference_file_raw.substr(workfilepath_pos, workfilepath_slash_pos - workfilepath_pos);
	}
	else workfilepath="CA_error.txt";
	std::cout <<"workfile path: "<<workfilepath<<std::endl;

	//Tab informations
	size_t gui_pos =preference_file_raw.find ("<gui-selections>",0)+15;
	size_t gui_slash_pos=preference_file_raw.find ("</gui-selections>",gui_pos);
	if ((gui_pos < gui_slash_pos) && ((gui_pos != std::string::npos) && (gui_slash_pos != std::string::npos)))
	{
	std::string 	gui_string=preference_file_raw.substr(gui_pos, gui_slash_pos - gui_pos);
	std::cout<< gui_string<<std::endl;
	int size_gui_string= gui_string.size();
	size_t iterator = 0;
	size_t tab_number =0;
	do
	{
		int pos_tab = gui_string.find("<tab-",iterator);	
		int pos_slash_tab = gui_string.find("</tab-", pos_tab);
		iterator = pos_slash_tab;
		std::cout << "iterator: "<<pos_tab<< " : gui string size "<< pos_slash_tab<< std::endl;	
		if ((pos_tab < pos_slash_tab) && ((pos_tab != std::string::npos) && (pos_slash_tab != std::string::npos)))
		{
		tab_structure_map[tab_number]=new Tab_structure;
		std::string tab_string = gui_string.substr(pos_tab,pos_slash_tab - pos_tab);
		//tab name
		size_t tab_name_pos = tab_string.find("<tab_name>",0)+10;
		size_t tab_name_slash_pos =tab_string.find("</tab_name>",tab_name_pos);		
		if ((tab_name_pos < tab_name_slash_pos) && ((tab_name_pos != std::string::npos) && (tab_name_slash_pos != std::string::npos)))
		{
		 tab_structure_map[tab_number]->tab_name =tab_string.substr(tab_name_pos,tab_name_slash_pos-tab_name_pos);
		}
		//panel 1
		//name
		size_t panel_1_pos = tab_string.find("<panel-1>",0)+9;
		size_t panel_1_slash_pos =tab_string.find("</panel-1>",panel_1_pos);		
		if ((panel_1_pos < panel_1_slash_pos) && ((panel_1_pos != std::string::npos) && (panel_1_slash_pos != std::string::npos)))
		{
		 tab_structure_map[tab_number]->panel_pref_structure.left_panel =tab_string.substr(panel_1_pos,panel_1_slash_pos-panel_1_pos);
		}		
		//width
		size_t panel_1_width_pos = tab_string.find("<panel-1-width>",0)+15;
		size_t panel_1_width_slash_pos =tab_string.find("</panel-1-width>",panel_1_width_pos);		
		if ((panel_1_width_pos < panel_1_width_slash_pos) && ((panel_1_width_pos != std::string::npos) && (panel_1_width_slash_pos != std::string::npos)))
		{
		std::string left_panel_width =tab_string.substr(panel_1_pos,panel_1_slash_pos-panel_1_pos);
		size_t left_width_num=get_number_from_string_out(left_panel_width);
		 tab_structure_map[tab_number]->panel_pref_structure.left_panel_width =left_width_num;
		}		

		//panel 2
		//name
		size_t panel_2_pos = tab_string.find("<panel-2>",0)+9;
		size_t panel_2_slash_pos =tab_string.find("</panel-2>",panel_2_pos);		
		if ((panel_2_pos < panel_2_slash_pos) && ((panel_2_pos != std::string::npos) && (panel_2_slash_pos != std::string::npos)))
		{
		 tab_structure_map[tab_number]->panel_pref_structure.right_panel =tab_string.substr(panel_2_pos,panel_2_slash_pos-panel_2_pos);
		}
		//width
		size_t panel_2_width_pos = tab_string.find("<panel-2-width>",0)+15;
		size_t panel_2_width_slash_pos =tab_string.find("</panel-2-width>",panel_2_width_pos);		
		if ((panel_2_width_pos < panel_2_width_slash_pos) && ((panel_2_width_pos != std::string::npos) && (panel_2_width_slash_pos != std::string::npos)))
		{
		std::string right_panel_width =tab_string.substr(panel_2_width_pos,panel_2_width_slash_pos-panel_2_width_pos);
		size_t right_width_num=get_number_from_string_out(right_panel_width);
		 tab_structure_map[tab_number]->panel_pref_structure.right_panel_width =right_width_num;
		}
		//vertical division position
		size_t panel_division_pos = tab_string.find("<panel-division-pos>",0)+20;
		size_t panel_division_slash_pos =tab_string.find("</panel-division-pos>",panel_division_pos);		
		if ((panel_division_pos < panel_division_slash_pos) && ((panel_division_pos != std::string::npos) && (panel_division_slash_pos != std::string::npos)))
		{
		std::string panel_division =tab_string.substr(panel_division_pos,panel_division_slash_pos-panel_division_pos);
		size_t division_num=get_number_from_string_out(panel_division);
		 tab_structure_map[tab_number]->panel_pref_structure.division_position =division_num;
		}
		number_of_tab=tab_number +1;
		}tab_number++;
	} 
	while( (iterator != -1) ||(iterator != std::string::npos));
	} 
	

}
else{
std::cout << "preference file not loading, using defaults"<<std::endl;
maximize_window=false;
}
};

void Preference::write_pref_file()
{
};
