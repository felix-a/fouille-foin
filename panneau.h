#ifndef PANNEAU_H
#define PANNEAU_H

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include "preference.h"
#include "panneautexte.h"
#include "panneauimage.h"
//#include "fenetreprincipale.h"
//#include "main.h"

class Panneau : public Gtk::Box {
public:
  Panneau();
  virtual ~Panneau();
//	Preference *preferencePointer;
 int select_panneau;
int type;
 void set_pannel_type(int);
	void reload_image();
	bool is_button_focus();
	void set_text(GdkEventKey*, TextBuffer*);
	void refresh_text_panel( TextBuffer*);
std::string construct_requete_history(std::string ,   Searchhistory*);
	PanneauImage m_panneauimage;
	PanneauTexte m_panneautexte;
	bool is_text_entry();
	int which_text_entry();
protected:

//Signal handlers:
 
  void fill_buffers();
 // void on_button_clicked();
  void on_combo_changed();
 


  Gtk::Frame m_Frame;

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); }

    Gtk::TreeModelColumn<int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
  };

  ModelColumns m_Columns;
//Preference preference;
  //Child widgets:
  Gtk::ComboBox m_Combo;
  Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;
 Gtk::Grid m_BoitePanneau;
  Gtk::Box m_VBox1, m_VBox2, m_VBox3;

//  Gtk::ScrolledWindow m_ScrolledWindow;
//  Gtk::TextView m_TextView;
  
//  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1;

// Gtk::Button m_button_2;//, m_button_2, m_button_quit;
 // Glib::RefPtr<Gtk::ListStore> m_refListStore; //The Tree Model.
 // Gtk::TreeView m_TreeView; //The Tree View.



};

#endif
