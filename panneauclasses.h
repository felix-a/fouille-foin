#ifndef PANNEAUCLASSES_H
#define PANNEAUCLASSES_H


#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>

class PanneauClassification : public Gtk::Box
{
public:
PanneauClassification();
virtual ~PanneauClassification();



 //modele pour classification_data:

  class ModelClassification_Data : public Gtk::TreeModel::ColumnRecord
  {
  public:

     ModelClassification_Data()
    { add(m_col_id); add(m_classification_type); add(m_classification); add(m_selected_for_info);}

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_classification_type;
    Gtk::TreeModelColumn<Glib::ustring> m_classification;
    Gtk::TreeModelColumn<bool> m_selected_for_info;
  };

  ModelClassification_Data m_modelclassification_data;

  //elements de du panneau:

	Gtk::ScrolledWindow classification_data, classification_info;  
	Gtk::TreeView m_TreeView;

  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;




};

#endif
