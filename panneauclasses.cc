#include <gtkmm/stock.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "panneauclasses.h"


PanneauClassification::PanneauClassification()
//:(Gtk::ORIENTATION_VERTICAL,Gtk::EXPAND)

{
//this->set_hexpand(true);
//this->set_vexpand(true);
classification_data.add(m_TreeView);
classification_data.set_hexpand(true);
classification_data.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

add(classification_data);

//Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_modelclassification_data);
  m_TreeView.set_model(m_refTreeModel);
 //Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_modelclassification_data.m_col_id] = 1;
  row[m_modelclassification_data.m_classification_type] = "IPC";
  row[m_modelclassification_data.m_classification] = "B65G";
  row[m_modelclassification_data.m_selected_for_info] = true;

  row = *(m_refTreeModel->append());
  row[m_modelclassification_data.m_col_id] = 2;
  row[m_modelclassification_data.m_classification_type] = "US Class";
  row[m_modelclassification_data.m_classification] = "241/123";
  row[m_modelclassification_data.m_selected_for_info] = false;

 m_TreeView.append_column("ID", m_modelclassification_data.m_col_id);
  m_TreeView.append_column("class scheme", m_modelclassification_data.m_classification_type);
  m_TreeView.append_column("class number", m_modelclassification_data.m_classification);
  //Make all the columns reorderable:
  //This is not necessary, but it's nice to show the feature.
  //You can use TreeView::set_column_drag_function() to more
  //finely control column drag and drop.
  for(guint i = 0; i < 2; i++)
  {
    Gtk::TreeView::Column* pColumn = m_TreeView.get_column(i);
    pColumn->set_reorderable();
  }
}

PanneauClassification::~PanneauClassification()
{
}
