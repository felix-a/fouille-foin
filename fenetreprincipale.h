#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include "workfile.h"
#include "messageslist.h"
#include "messagetext.h"
#include "panneau.h"
#include "preference.h"
#include "requeteweb.h"
#include "searchhistory.h"
#include <gtkmm.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

int get_number_from_string(std::string);
void	extract_doc_from_results();
void   write_buffer_to_file();
//std::map<size_t, Document*>  document_map;
 //void put_workfile_in_object(std::string);

//WebResponseString web_response_string;
struct Note_book_structure
{
Panneau panneau1, panneau2;

};
class PagePosition
{
public:
PagePosition();
virtual ~PagePosition();
void zero_page();
void add_a_page();
int get_page();
int page;
};

class FenetrePrincipale : public Gtk::Window
{
public:
  Preference preference, *preferencePointer;
PagePosition page_pos;

  FenetrePrincipale();
  virtual ~FenetrePrincipale();
//	void set_path(std::string);

//	std::string reponse_du_web;
   Panneau m_Panneau, m_Panneau2, m_Panneau3, m_Panneau4;
   Searchhistory m_searchhistory, *m_searchhistory_ptr;
	WorkFile m_workfile1;
std::map<size_t, Document*>  document_map;
 void put_workfile_in_object(std::string);
 int get_number_from_string(std::string);
    bool key_pressed(GdkEventKey *event);
TextBuffer text_buffer, *text_buf_ptr;
std::string web_html_response, *web_html_response_ptr;
void extract_doc_from_results_V2();
std::map<size_t, Gtk::Box*>  notebook_map;
//std::map<size_t, Gtk::Box*>::iterator it;
std::map<size_t,Note_book_structure*> note_book_strure_map;
std::map<size_t,Gtk::Paned*> paned_map; 
  void worklist_element_changed(int);
void signal_handler_child_widget(int);
void worklist_element_changedhumm();
protected:
  //Signal handlers:
int select_panneau; 
  void on_button_open_clicked();
  void on_button_new_clicked();
  void on_button_save_clicked();
  void on_notebook_switch_page(Gtk::Widget* page, guint page_num);


int get_number_from_string_V2(std::string);



//Tree model columns:
  class Tirroirs : public Gtk::TreeModel::ColumnRecord
  {
  public:

    Tirroirs()
    { add(m_col_id); add(m_col_name); }

    Gtk::TreeModelColumn<int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
  };

  Tirroirs tirroir_worklist;
//Preference preference;
  //Child widgets:
  Gtk::ComboBox worklist_combo;
  Glib::RefPtr<Gtk::TreeStore> worklisttreeModel;
  //Child widgets:
	Gtk::Box m_Box1, m_Box2, m_Box3, m_Box_worklist_drawer;
  Gtk::Notebook m_Notebook;
  Gtk::Label m_Label1, m_Label2;
 Gtk::Button m_Button_open,m_Button_save,m_Button_new;
  Gtk::Paned m_VPaned, m_VPaned2, *VPaned_ptr;
  Gtk::Entry m_worklist_entry;
	

  MessagesList m_MessagesList;
  MessageText m_MessageText;

};

// FenetrePrincipale window;
//class reponce_web
//{
//public:
//reponce_web();
//virtual ~reponce_web();

//std::string reponce_du_web; 

//};

#endif
