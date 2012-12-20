#ifndef PREFERENCE_H
#define PREFERENCE_H
#include <map>
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>

struct Panel_pref_structure
{
std::string left_panel, right_panel;
size_t left_panel_width, right_panel_width, division_position;

};
struct Tab_structure
{
std::string tab_name;
Panel_pref_structure panel_pref_structure;
};


class Preference
{

public: 
Preference();
virtual ~Preference();
//	void setworkfiledummy(std::string);
	void setworkfile(std::string);
	std::string getworkfile();
	int nombre_tab();
	int type_panneau();
	void read_pref_file();
	void write_pref_file();
	bool maximize_window;
	int height, width, int_pos_y, int_pos_x;
	std::map<size_t, Tab_structure*>  tab_structure_map;
	size_t number_of_tab;

private:
	std::string workfile;
	int a;
	int y;
	int nombres_tab;
	int numero_panneau;
	int index;

};
#endif
