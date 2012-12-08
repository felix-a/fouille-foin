#include "panneau.h"
#include "requeteweb.h"
//#include "fenetreprincipale.h"
#include <gtkmm/stock.h>
#include <iostream>
#include <sstream>
#include "preference.h"
#include "fenetreprincipale.h"
#include "panneautexte.h"
#include "panneauimage.h"
#include "searchhistory.h"

Panneau::Panneau()
: m_VBox3(Gtk::ORIENTATION_HORIZONTAL),
m_VBox2(Gtk::ORIENTATION_VERTICAL),
m_VBox1(Gtk::ORIENTATION_HORIZONTAL), 
//preference(),
//: m_button_1("button 1"),
  m_button_2("button 2")
//  m_button_quit("Quit")
{
  /* Create a new scrolled window, with scrollbars only if needed */
 //set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	//char name[20];
//	FenetrePrincipale::preference preferencePointer;
 //type = *preferencePointer->type_panneau();
   //   std::cout <<  "typehumm= " << preferencePointer << std::endl;
  //   Glib::ustring  name =  Gtk::Widget::get_name();
      
    //  Glib::ustring name = row[m_Columns.m_col_name];

   //   std::cout <<  "name= " << name << std::endl;
  //Create the Tree model:
  m_refTreeModel = Gtk::TreeStore::create(m_Columns);
 // m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_Combo.set_model(m_refTreeModel);

  //Fill the ComboBox's Tree Model:
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_name] = "Requêtes";

 // Gtk::TreeModel::Row childrow = *(m_refTreeModel->append(row.children()));
 // childrow[m_Columns.m_col_id] = 11;
 // childrow[m_Columns.m_col_name] = "Billy Bob Junior";

 // childrow = *(m_refTreeModel->append(row.children()));
 // childrow[m_Columns.m_col_id] = 12;
 // childrow[m_Columns.m_col_name] = "Sue Bob";
  

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_name] = "Images";


  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 3;
  row[m_Columns.m_col_name] = "Texte";
select_panneau = 1;
      std::cout <<  "select_panneau= " << select_panneau << std::endl;

	if (select_panneau == 0)  m_Combo.set_active(0);
  	if (select_panneau == 1)  m_Combo.set_active(1);
  	if (select_panneau == 2)  m_Combo.set_active(2);
  // childrow = *(m_refTreeModel->append(row.children()));
  // childrow[m_Columns.m_col_id] = 31;
  // childrow[m_Columns.m_col_name] = "Xavier McRoberts";
  

  //Add the model columns to the Combo (which is a kind of view),
  //rendering them in the default way:
//  m_Combo.pack_start(m_Columns.m_col_id);
  m_Combo.pack_start(m_Columns.m_col_name);

  //Add the ComboBox to the window.

  //Connect signal handler:
  m_Combo.signal_changed().connect( sigc::mem_fun(*this, &Panneau::on_combo_changed) );

 
add(m_Frame);
  m_Frame.set_size_request(400, 10);

 // m_Frame.set_label("Gtk::Frame Widget                ");
  m_Frame.set_label_align(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
  m_Frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
//  m_Frame.add(m_Combo);
  m_Frame.add(m_VBox2);

  m_VBox2.pack_start(m_VBox1, Gtk::PACK_SHRINK);
//  m_VBox2.pack_start(m_VBox3);
  m_VBox1.pack_start(m_Combo, Gtk::PACK_SHRINK);
//set_border_width(0);

  /* Set the frames label */

 

  /* Align the label at the right of the frame */

  /* Set the style of the frame */

//m_BoitePaneau.add(m_VBox3);

//add(m_VBox3);

// m_ScrolledWindow.add(m_TextView);

  //Only show the scrollbars when they are necessary:
//  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

//  m_VBox3.pack_start(m_ScrolledWindow);

	m_button_2.signal_clicked().connect( sigc::mem_fun(*this,
              &Panneau::on_button_clicked) );

  m_VBox2.pack_start(m_button_2, Gtk::PACK_SHRINK); // remplacer par "Enter"
//m_BoîtePaneau.add(m_button_2);
m_VBox2.pack_start(m_panneauimage);
m_VBox2.pack_start(m_panneautexte);
 


 // show_all_children();
}

Panneau::~Panneau()
{
}
bool Panneau::is_text_entry()
{
 Gtk::TreeModel::iterator iter = m_Combo.get_active();
Gtk::TreeModel::Row row = *iter;
int id = row[m_Columns.m_col_id];
//int interator_combo=m_Combo.get_active();
std::cout<< "m_combo "<< id  <<std::endl;
if (id == 1) return true;
else return false;
}

int Panneau::which_text_entry()
{
 Gtk::TreeModel::iterator iter = m_Combo.get_active();
Gtk::TreeModel::Row row = *iter;
int id = row[m_Columns.m_col_id];
return id;
}
void Panneau::on_button_clicked()
{
//std::string allo="humm";
// size_t bon=requeteweb(allo);
}

void Panneau::on_combo_changed()
{
  Gtk::TreeModel::iterator iter = m_Combo.get_active();
    Gtk::TreeModel::Row row = *iter;
    if(row)
    {
      //Get the data for the selected row, using our knowledge of the tree
      //model:
      int id = row[m_Columns.m_col_id];
      Glib::ustring name = row[m_Columns.m_col_name];
if (id == 1){
 m_panneautexte.show();
 m_panneauimage.hide();
}
if (id == 2) {
m_panneauimage.show();
m_panneautexte.hide();
}


      std::cout << " ID=" << id << ", name=" << name << std::endl;
    }
    else
     std::cout << "invalid iter" << std::endl;





}
void  Panneau::set_pannel_type(int type)
{
 m_Combo.set_active(type);
std::cout <<"type tel me: " << type<<std::endl;
//if (type == 0) m_VBox2.pack_start(m_panneautexte);
//if (type == 1) m_VBox2.pack_start(m_panneauimage);
if (type == 1) m_panneautexte.hide();
if (type == 0) m_panneauimage.hide();

}
void Panneau::reload_image()
{
m_panneauimage.reload();

}
bool Panneau::is_button_focus()
{
//Glib::RefPtr< Gdk::Window > parent = get_parent_window ();
//Gtk::Widget* parent = get_window();

bool tata= m_panneautexte.has_the_focus();  
//std::cout << "laksjdlfksdjlkf"<< tata <<std::endl;
return tata;
}
void Panneau::set_text(GdkEventKey *keyval, TextBuffer *text_buffer_l1)
{
 m_panneautexte.use_key(keyval,text_buffer_l1);
std::string dudes=text_buffer_l1->get_buffer();
std::cout << "DDSSFASDFSDFSD: "<< char(keyval->keyval) << dudes <<std::endl;
}
void Panneau::refresh_text_panel( TextBuffer *text_buffer_l1)
{
m_panneautexte.set_text_in_text_view(text_buffer_l1);
}
std::string Panneau::construct_requete_history(std::string request,   Searchhistory *m_searchhistory_ptr)
{
std::string request_b = m_panneautexte.construct_request_histroy_pn(request, m_searchhistory_ptr);
return request_b;
}

