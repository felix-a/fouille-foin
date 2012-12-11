#include "fenetreprincipale.h"
//#include "panneau.h"
#include "/usr/include/gtk-3.0/gdk/gdkkeysyms.h"
//#include "main.h"

#include <iostream>
#include <Magick++.h>

extern WebResponseString  web_response_string;
extern WebResponseImage   web_response_image_obj;

FenetrePrincipale::FenetrePrincipale()
:m_Box1(Gtk::ORIENTATION_VERTICAL),
  m_Box2(Gtk::ORIENTATION_VERTICAL),
  m_Box_worklist_drawer(Gtk::ORIENTATION_HORIZONTAL),
  m_Label1("Contents of tab 1"),
  m_Label2("Contents of tab 2"),
  m_VPaned(Gtk::ORIENTATION_HORIZONTAL),
//	preference(),
  m_Button_open("Open"),
  m_Button_save("Save"),
  m_Button_new("New")
{
maximize();
unmaximize();
preference.read_pref_file();
text_buffer.initiate_buffer();
text_buf_ptr=&text_buffer;
web_html_response_ptr=&web_html_response;
m_searchhistory_ptr=&m_searchhistory;
web_response_string.set_string_from_web("number-of-pages=  28  desc");
page_pos.zero_page();
//m_Panneau.set_name("name");
//m_Panneau2.set_name("name2");
set_title ("Fouille Foin");
//set_border_width(10);
set_default_size(1100, 500);
preferencePointer=&preference;
web_response_string.set_string_from_web("ddddde");
// 	int type = preference.type_panneau();
//      std::cout <<  "type= " << type << std::endl;
 // put the box into the main window.
//add(m_topmenu);
add(m_Box1);
m_Notebook.set_border_width(5);
m_Box1.pack_start(m_topmenu);
m_Box1.pack_start(m_Notebook);
m_topmenu.grab_worklist_combo();
m_topmenu.grab_documentmap();

m_Button_open.signal_clicked().connect( sigc::mem_fun(*this, &FenetrePrincipale::on_button_open_clicked) );
m_Button_save.signal_clicked().connect( sigc::mem_fun(*this, &FenetrePrincipale::on_button_save_clicked) );
m_Button_new.signal_clicked().connect( sigc::mem_fun(*this, &FenetrePrincipale::on_button_new_clicked) );

worklisttreeModel = Gtk::TreeStore::create(tirroir_worklist);
worklist_combo.set_model(worklisttreeModel);
/*	Gtk::TreeModel::Row worklist_row = *(worklisttreeModel->append());
 worklist_row[tirroir_worklist.m_col_id] = 1;
  worklist_row[tirroir_worklist.m_col_name] = "Requêtes";
    worklist_row = *(worklisttreeModel->append());
  worklist_row[tirroir_worklist.m_col_id] = 2;
  worklist_row[tirroir_worklist.m_col_name] = "êtes";
  */    
worklist_combo.pack_start(tirroir_worklist.m_col_name);

worklist_combo.signal_changed().connect( sigc::mem_fun(*this, &FenetrePrincipale::worklist_element_changedhumm) );
//	worklist_combo.set_active(1);
//m_Button.signal_clicked().connect(sigc::bind<Glib::ustring>(
  //            sigc::mem_fun(*this, &ExampleWindow::on_button_clicked), "Close"));

  /* Add a vpaned widget to our toplevel window */
//add(m_Button);
//  add(m_VPaned);
m_worklist_entry.set_max_length(15);
m_worklist_entry.set_text("select worklist");
m_Box1.pack_end(m_Box_worklist_drawer,Gtk::PACK_SHRINK);
m_Box_worklist_drawer.pack_start(m_worklist_entry, Gtk::PACK_SHRINK);
m_Box_worklist_drawer.pack_start(m_Button_open, Gtk::PACK_SHRINK);
m_Box_worklist_drawer.pack_start(m_Button_save, Gtk::PACK_SHRINK);
m_Box_worklist_drawer.pack_start(m_Button_new, Gtk::PACK_SHRINK);
m_Box_worklist_drawer.pack_start(worklist_combo);

//worklist_combo.set_active(0);

//Add the Notebook pages:
size_t num_notebook_page=preference.number_of_tab;
for(int i=1;i<=num_notebook_page;i++){
	notebook_map[i-1]=new Gtk::Box;
	std::string name_b = preference.tab_structure_map[i-1]->tab_name;
	m_Notebook.append_page(*notebook_map[i-1],name_b);
//				m_VPanedz = new ;
	paned_map[i-1]= new Gtk::Paned;
	notebook_map[i-1]->pack_start(*paned_map[i-1]);
	note_book_strure_map[i-1] =new Note_book_structure;

    std::cout <<  "FPselect_panneau= " <<    note_book_strure_map[i-1]->panneau1.get_name() << std::endl;
    std::cout <<  "FPselect_panneau= " <<    note_book_strure_map[i-1]->panneau2.get_name() << std::endl;
	paned_map[i-1]->pack1(note_book_strure_map[i-1]->panneau1, true, true);	
	paned_map[i-1]->pack2(note_book_strure_map[i-1]->panneau2, true, true);
//		note_book_strure_map[i-1]->panneau1.set_pannel_type(0);
//		note_book_strure_map[i-1]->panneau2.set_pannel_type(0);


}

//m_Notebook.append_page(m_Box2, "Recherche");
//m_Notebook.append_page(m_Box3, "Visualisation");

m_Notebook.signal_switch_page().connect(sigc::mem_fun(*this,&FenetrePrincipale::on_notebook_switch_page) );
//m_Box2.pack_start(m_VPaned);
//m_Box3.pack_start(m_VPaned2);
  /* Now add the contents of the two halves of the window */


//select_panneau=1;
//std::cout <<  "FPselect_panneau= " <<  m_Panneau.get_name()  << std::endl;
//m_VPaned.pack1(m_Panneau,true,true);

 // m_VPaned.set_position(10);
//select_panneau=2;
//std::cout <<  "FPselect_panneau= " <<     m_Panneau2.get_name() << std::endl;
//m_VPaned.pack2(m_Panneau2,true,true);
//std::cout <<  "FPselect_panneau= " <<     m_Panneau3.get_name() << std::endl;
//m_VPaned2.pack1(m_Panneau3,true,true);
//std::cout <<  "FPselect_panneau= " <<     m_Panneau4.get_name() << std::endl;
//m_VPaned2.pack2(m_Panneau4,true,true);


signal_key_press_event().connect(sigc::mem_fun(*this,&FenetrePrincipale::key_pressed),false);


show_all_children();

for(int i=1;i<=num_notebook_page;i++){
	note_book_strure_map[i-1]->panneau1.set_pannel_type(0);
	note_book_strure_map[i-1]->panneau2.set_pannel_type(1);

}

//m_Panneau.set_pannel_type(preference.type_panneau());
//m_Panneau2.set_pannel_type(preference.type_panneau());     
//m_Panneau3.set_pannel_type(preference.type_panneau());
//m_Panneau4.set_pannel_type(preference.type_panneau());     


}

FenetrePrincipale::~FenetrePrincipale()
{
}

bool FenetrePrincipale::key_pressed(GdkEventKey *event)
{
size_t m_notebook_index = m_Notebook.get_current_page();
//note_book_strure_map[m_Notebook.get_current_page()]->panneau1.is_entry_text()

if (event->keyval == GDK_KEY_Escape) m_Notebook.grab_focus();

else if ((note_book_strure_map[m_Notebook.get_current_page()]->panneau1.is_text_entry()||note_book_strure_map[m_Notebook.get_current_page()]->panneau2.is_text_entry())&&(note_book_strure_map[m_Notebook.get_current_page()]->panneau1.is_button_focus()||note_book_strure_map[m_Notebook.get_current_page()]->panneau2.is_button_focus()))//(m_Panneau.is_button_focus())
{
int wich_entry_left=0;
int wich_entry_right=0;
	if (note_book_strure_map[m_Notebook.get_current_page()]->panneau1.is_text_entry())
	{
	 wich_entry_left = note_book_strure_map[m_Notebook.get_current_page()]->panneau1.which_text_entry();
	}
	else if (note_book_strure_map[m_Notebook.get_current_page()]->panneau2.is_text_entry())
	{
	 wich_entry_right = note_book_strure_map[m_Notebook.get_current_page()]->panneau2.which_text_entry();
	}
	bool left_or_right=true;
	if (note_book_strure_map[m_Notebook.get_current_page()]->panneau1.is_button_focus()) left_or_right= true ;
	else /*if (note_book_strure_map[m_Notebook.get_current_page()]->panneau2.is_button_focus())*/ left_or_right= false;

	guint key = event->keyval;
	if (left_or_right) note_book_strure_map[m_Notebook.get_current_page()]->panneau1.set_text(event, text_buf_ptr);
	else note_book_strure_map[m_Notebook.get_current_page()]->panneau2.set_text(event, text_buf_ptr);
	//m_Panneau.set_text(event, text_buf_ptr);
	std::cout << "bien oui: the focus " << std::endl;
	if((event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter))
	{
		Glib::ustring oldbuffer=text_buf_ptr->m_refTextBuffer->get_text();
		std::string test = oldbuffer;
		size_t n_place= test.rfind("/?:");
		size_t string_n_letters=test.size();
		size_t length=string_n_letters-n_place-4;
		std::string requete= " " + test.substr(n_place +4, length) + " ";
		//std::cout << ":"<< requete <<":"<< std::endl;

		std::string dot_dot = requete.substr(1,2);
		//std::cout << "requete:" << dot_dot << "::"<<std::endl;  
		if (dot_dot==".."){
			if(requete.substr(0,5) ==" ..dv"||requete.substr(0,5)==" ..DV"){
			//std::cout << "dv or DV: " << requete <<std::endl;  
			Glib::ustring newbuffer = oldbuffer  + "\n sending document to viewer\n/?: " ;
			text_buf_ptr->m_refTextBuffer->set_text(newbuffer);
			if (left_or_right) note_book_strure_map[m_Notebook.get_current_page()]->panneau1.refresh_text_panel(text_buf_ptr);
			else note_book_strure_map[m_Notebook.get_current_page()]->panneau2.refresh_text_panel(text_buf_ptr);
			//m_Panneau.refresh_text_panel(text_buf_ptr);
			extract_doc_from_results_V2(); 
	
			}
		}
		else{
			std::string newbuffer=oldbuffer + "\n" + "proccesing request, please wait"+"\n" ;
			text_buf_ptr->m_refTextBuffer->set_text(newbuffer);
			if (left_or_right)
				{
				note_book_strure_map[m_Notebook.get_current_page()]->panneau1.refresh_text_panel(text_buf_ptr);
				requete =note_book_strure_map[m_Notebook.get_current_page()]->panneau1.construct_requete_history(requete,m_searchhistory_ptr);
				}
			else 
				{
				note_book_strure_map[m_Notebook.get_current_page()]->panneau2.refresh_text_panel(text_buf_ptr);
				requete =note_book_strure_map[m_Notebook.get_current_page()]->panneau2.construct_requete_history(requete,m_searchhistory_ptr);
				}
			//m_Panneau.refresh_text_panel(text_buf_ptr);
			//requete = m_Panneau.construct_requete_history(requete,m_searchhistory_ptr);
			size_t search_number=m_searchhistory.add_seach_string(requete);
			size_t result=requeteweb_2(requete,1,web_html_response_ptr);  //ici
			std::string reponse_webe = /*"<?xml version=1.0 encoding=UTF-8?><?xml-stylesheet type= text/xsl href=/2.6.2/style/exchange.xsl?><ops:world-patent-data xmlns:ops=http://ops.epo.org xmlns=http://www.epo.org/exchange xmlns:ccd=http://www.epo.org/ccd xmlns:xlink=http://www.w3.org/1999/xlink>    <ops:meta name=elapsed-time value=88/>     <ops:biblio-search total-result-count=0>         <ops:query syntax=CQL> (((((sugar and cane) and process))) and juce) and juice</ops:query>        <ops:range begin= 1  end=25/>        <ops:search-result/>    </ops:biblio-search> </ops:world-patent-data> ";*/ web_response_string.get_string_from_web();
			//std::cout << reponse_webe << "::"<< std::endl;
			int pos_result = reponse_webe.find("total-result-count=",1) + 19;
			int pos_result_end_line = reponse_webe.find(">",pos_result);
			std::cout << pos_result_end_line <<" :: "<<pos_result <<std::endl;
			std::string num_result_brut=reponse_webe.substr(pos_result,pos_result_end_line-pos_result-1);
			size_t num_result= get_number_from_string_V2(num_result_brut);
			newbuffer = oldbuffer  + "\n recherche #" + std::to_string(search_number) + " resultats: " + std::to_string(num_result) + "\n/?: " ;
			text_buf_ptr->m_refTextBuffer->set_text(newbuffer);
			if (left_or_right) note_book_strure_map[m_Notebook.get_current_page()]->panneau1.refresh_text_panel(text_buf_ptr);
			else note_book_strure_map[m_Notebook.get_current_page()]->panneau2.refresh_text_panel(text_buf_ptr);
			//m_Panneau.refresh_text_panel(text_buf_ptr);
		}

	}
}
else
{
	if (event->keyval == GDK_KEY_n)
	{
		int selected_element = worklist_combo.get_active_row_number();
		bool has_entry = worklist_combo.get_has_entry();
		std::cout <<"a des entrée: "<< has_entry << std::endl;
		if (selected_element >=0)
		{
			selected_element = worklist_combo.get_active_row_number();
			worklist_combo.set_active(selected_element+1);		 
			worklist_element_changed(1);

		}	
	}
	else if (event->keyval == GDK_KEY_b)
	{
		int selected_element = worklist_combo.get_active_row_number();
		std::cout <<"element selectionné: "<< selected_element << std::endl;
		if (selected_element >=0)
		{
			worklist_element_changed(2);		
		
		}	

	}
}
//bool humm = m_Panneau.is_button_focus();

//std::cout << "bien oui: "<< humm << std::endl;
//std::cout << "bien oui: "<< event<< std::endl;

return true;
}

void FenetrePrincipale::on_button_open_clicked()
{
  //Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
   // ExampleWindow window;
   // Gtk::Main kit(argc, argv);
  //Shows the window and returns when it is closed.
//  return app->run(window);
 //Gtk::Main::run(m_monnautilus);
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  Glib::RefPtr<Gtk::FileFilter> filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog.add_filter(filter_text);

  Glib::RefPtr<Gtk::FileFilter> filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog.add_filter(filter_cpp);

  Glib::RefPtr<Gtk::FileFilter> filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      std::string filename = dialog.get_filename();

	size_t filename_length = filename.size();
	size_t filename_lastslash = filename.rfind("/",filename_length);
	std::string filename_only = filename.substr(filename_lastslash + 1, filename_length - filename_lastslash);
        std::cout << "File selected: " <<  filename << std::endl;
	m_worklist_entry.set_text(filename_only);
	preference.setworkfile(filename);
	std::string workfiledata=m_workfile1.load_workfile(filename);
	put_workfile_in_object(workfiledata);
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      std::cout << "Cancel clicked." << std::endl;
	    break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
       
      break;
    }
  }


}
void FenetrePrincipale::on_button_save_clicked()
{
  hide();
}
void FenetrePrincipale::on_button_new_clicked()
{
  hide();
}
void FenetrePrincipale::on_notebook_switch_page(Gtk::Widget* /* page */, guint page_num)
{
  std::cout << "Switched to tab with index " << page_num << std::endl;

  //You can also use m_Notebook.get_current_page() to get this index.
}
void FenetrePrincipale::put_workfile_in_object(std::string work_file_data)
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
	document_map[num_of_doc] = new Document;
		
	size_t system_pos = each_doc_string.find("system=",0);
	size_t family_id_pos = each_doc_string.find("family-id",0);
	document_map[num_of_doc]->set_system(each_doc_string.substr(system_pos+8,family_id_pos -system_pos-10));
	size_t end_line_family = each_doc_string.find(">\n",family_id_pos);
	document_map[num_of_doc]->set_family_number(each_doc_string.substr(family_id_pos+11,end_line_family -family_id_pos-12));
	size_t document_id_type_pos = each_doc_string.find("document-id-type=",0);
	size_t end_line_document_id_type = each_doc_string.find(">\n",document_id_type_pos);
	document_map[num_of_doc]->set_id_type(each_doc_string.substr(document_id_type_pos+18,end_line_document_id_type -document_id_type_pos-19));
	size_t country_in = each_doc_string.find("<country>",0);
	size_t country_out = each_doc_string.find("</country>",0);
	document_map[num_of_doc]->set_country(each_doc_string.substr(country_in+9,country_out-country_in-9));
	size_t doc_num_in = each_doc_string.find ("<doc-number>",0);
	size_t doc_num_out = each_doc_string.find ("</doc-number>",0);
	document_map[num_of_doc]->set_number(each_doc_string.substr(doc_num_in+12,doc_num_out-doc_num_in-12));
	size_t kind_in = each_doc_string.find("<kind>",0);
	size_t kind_out = each_doc_string.find("</kind>",0);
		document_map[num_of_doc]->set_kind(each_doc_string.substr(kind_in+6,kind_out-kind_in-6));
	 start1=end+28;
	end1=end;
//  	std::cout << "Start " << start<< " end "<< end<< " length string "<<lenght_of_doc_string<< " "<<num_of_doc<< std::endl;

	std::cout << "country: "<< document_map[num_of_doc]->get_country() << std::endl;
	std::cout << "number: "<< document_map[num_of_doc]->get_number() << std::endl;
	std::cout << "kind: "<< document_map[num_of_doc]->get_kind() << std::endl;
	std::cout << "system: "<< document_map[num_of_doc]->get_system() << std::endl;
	std::cout << "family: "<< document_map[num_of_doc]->get_family_number() << std::endl;
	std::cout << "id type: "<< document_map[num_of_doc]->get_id_type() << std::endl;
	num_of_doc=num_of_doc+1;
	 if (end1 >= ( lenght_of_doc_string -30)) end_of_doc_string=true;
	}//while(end_of_doc_string=false);
	 
	size_t size_worklist = document_map.size();
std::cout << "size worklist: "<< size_worklist<< std::endl;
	for (size_t i=0;i<size_worklist;i++)
	{
		std::string worklist_entry=document_map[i]->get_country()+document_map[i]->get_number() + document_map[i]->get_kind();
std::cout << "worklist_entry: "<< worklist_entry << std::endl;
       		Gtk::TreeModel::Row worklist_row = *(worklisttreeModel->append());
 		worklist_row[tirroir_worklist.m_col_id] = i+1;
		worklist_row[tirroir_worklist.m_col_name] = worklist_entry;//document_map[i]->get_country()+document_map[i]->get_number() + document_map[i]->get_kind();
	}
	worklist_combo.pack_start(tirroir_worklist.m_col_name);
	worklist_combo.set_active(0);
}
void FenetrePrincipale::worklist_element_changedhumm()
{
worklist_element_changed(1);
}
  void FenetrePrincipale::worklist_element_changed(int page_or_doc)
{
std::cout <<"bien ca se rend ici!!"<<std::endl;
int selected = 0;
if(worklist_combo.get_active_row_number() >=0) selected = worklist_combo.get_active_row_number();
std::cout << "worklist_entry: "<< selected << std::endl;
std::string image_name_epo = "";
if(document_map[selected]) image_name_epo = document_map[selected]->get_country() + document_map[selected]->get_number() + "." +document_map[selected]->get_kind() ;
int pos = image_name_epo.find(".",0);
std::cout << "worklist_entry: "<< selected << " : "<< image_name_epo.find(".",0)<<" : "<< pos << std::endl;
if(pos>1) size_t a=requeteweb(image_name_epo,2);

std::string work_text = web_response_string.get_string_from_web();

		//get number of pages
std::cout <<"publication info : "<< work_text << std::endl; 
	
size_t full_doc_pos = work_text.find("FullDocument",0);

size_t num_pages_pos_in = work_text.rfind ("number-of-pages=",full_doc_pos) + 16 ;
size_t num_pages_pos_out = 0;
 
      num_pages_pos_out = work_text.find("desc",num_pages_pos_in);
if(num_pages_pos_out>100001) num_pages_pos_out=num_pages_pos_in+2;
std::cout <<"number of pages : "<<num_pages_pos_in<<" :"<<num_pages_pos_out<< std::endl;
	if(num_pages_pos_out<num_pages_pos_in) num_pages_pos_out=num_pages_pos_in+2;
	//get page start for sections
	//Abstract
	size_t num_pos_AB_numbers=1;
	size_t  num_pos_AB = work_text.find("ABSTRACT",0) + 21;
	if (num_pos_AB != std::string::npos){
	size_t num_pos_AB_end = work_text.find("/>",num_pos_AB);
		if (num_pos_AB_end != std::string::npos ){
			if (num_pos_AB_end > num_pos_AB){
			std::string num_pos_AB_letters = work_text.substr(num_pos_AB,num_pos_AB_end-num_pos_AB);
			num_pos_AB_numbers=get_number_from_string_V2(num_pos_AB_letters);
			}
		}
	}

	size_t num_pos_BIBLIO_numbers=1;
	size_t  num_pos_BIBLIO = work_text.find("BIBLIOGRAPHY",0) + 25;
	if (num_pos_BIBLIO != std::string::npos){
	size_t num_pos_BIBLIO_end = work_text.find("/>",num_pos_BIBLIO);
		if (num_pos_BIBLIO_end != std::string::npos ){
			if (num_pos_BIBLIO_end > num_pos_BIBLIO){
			std::string num_pos_BIBLIO_letters = work_text.substr(num_pos_BIBLIO,num_pos_BIBLIO_end-num_pos_BIBLIO);
			num_pos_BIBLIO_numbers=get_number_from_string_V2(num_pos_BIBLIO_letters);
			}
		}
	}
	size_t num_pos_CLAIMS_numbers=1;
	size_t  num_pos_CLAIMS = work_text.find("CLAIMS",0) + 19;
	if (num_pos_CLAIMS != std::string::npos){
		size_t num_pos_CLAIMS_end = work_text.find("/>",num_pos_CLAIMS);
		if (num_pos_CLAIMS_end != std::string::npos ){
			if (num_pos_CLAIMS_end > num_pos_CLAIMS){
			std::string num_pos_CLAIMS_letters = work_text.substr(num_pos_CLAIMS,num_pos_CLAIMS_end-num_pos_CLAIMS);
			num_pos_CLAIMS_numbers=get_number_from_string_V2(num_pos_CLAIMS_letters);
			}
		}
	}
	size_t num_pos_DESCRIPTION_numbers=1;
	size_t  num_pos_DESCRIPTION = work_text.find("DESCRIPTION",0) + 24;
	if (num_pos_DESCRIPTION != std::string::npos){
	size_t num_pos_DESCRIPTION_end = work_text.find("/>",num_pos_DESCRIPTION);
		if (num_pos_DESCRIPTION_end != std::string::npos ){
			if (num_pos_DESCRIPTION_end > num_pos_DESCRIPTION){
			std::string num_pos_DESCRIPTION_letters = work_text.substr(num_pos_DESCRIPTION,num_pos_DESCRIPTION_end-num_pos_DESCRIPTION);
			num_pos_DESCRIPTION_numbers=get_number_from_string_V2(num_pos_DESCRIPTION_letters);
			}
		}
	}



	size_t num_pos_DRAWINGS_numbers=1;
	size_t  num_pos_DRAWINGS = work_text.find("DRAWINGS",num_pos_DESCRIPTION) + 21;
	if (num_pos_DRAWINGS != std::string::npos){
		size_t num_pos_DRAWINGS_end = work_text.find("/>",num_pos_DRAWINGS);
		if (num_pos_DRAWINGS_end != std::string::npos ){
			if (num_pos_DRAWINGS_end > num_pos_DRAWINGS){
			std::string num_pos_DRAWINGS_letters = work_text.substr(num_pos_DRAWINGS,num_pos_DRAWINGS_end-num_pos_DRAWINGS);
			num_pos_DRAWINGS_numbers=get_number_from_string_V2(num_pos_DRAWINGS_letters);
			}
		}
	}
std::string range_letter;
if (page_or_doc==1) page_pos.zero_page();
if (page_or_doc==2){
page_pos.add_a_page();
}

if (num_pages_pos_in != 15) 
{
std::string num_pages_text = work_text.substr(num_pages_pos_in,num_pages_pos_out -num_pages_pos_in-1);
 int number_pages = get_number_from_string_V2(num_pages_text);
std::cout <<"number of pages : "<< number_pages << std::endl; 
}

if(document_map[selected]) 
{
//last_range=rage_letter;
int page = page_pos.get_page();
	if (page == 1) range_letter ="1";
	else{
	range_letter = std::to_string(num_pos_DRAWINGS_numbers-2 +page);
	}
image_name_epo = document_map[selected]->get_country() +"/" + document_map[selected]->get_number() + "/" + document_map[selected]->get_kind() + "/fullimage?range=" + range_letter;
size_t ok = requeteweb(image_name_epo,3);

       Magick::Image image;
    try
    {

       image.density("100");
       image.read("body.pdf");
       image.write("body.png");
    }
    catch (Magick::WarningCoder &e)
    {
        std::cout << "Warning " << e.what() << std::endl;
    }

//system ("convert body.pdf body.png");


}
FenetrePrincipale::signal_handler_child_widget(1);
//std::cout << "a : "<< a << std::endl;
//if (select_panneau == 1)on_image_change(std::string, int)
}

void FenetrePrincipale::signal_handler_child_widget(int stuf)
{
size_t m_notebook_index = m_Notebook.get_current_page();
note_book_strure_map[m_Notebook.get_current_page()]->panneau2.reload_image();

}

void	FenetrePrincipale::extract_doc_from_results_V2()
{
int number_result_extracted = 0;
int number_result=0;
do{
std::string work_text = web_response_string.get_string_from_web();
		//get number of docs
size_t num_result_pos_in = work_text.find("total-result-count=",0) + 19 ;
size_t num_result_pos_out = work_text.find(">\n",num_result_pos_in);
std::string num_result_text = work_text.substr(num_result_pos_in,num_result_pos_out -num_result_pos_in-1);
 number_result =get_number_from_string_V2 (num_result_text);
		//get low range number 
size_t num_range_low_pos_in = work_text.find("begin=",num_result_pos_in) + 6 ;
size_t num_range_low_pos_out = work_text.find("end",num_range_low_pos_in);
std::string num_range_low_text = work_text.substr(num_range_low_pos_in,num_range_low_pos_out -num_range_low_pos_in-2);
 int range_low =get_number_from_string_V2 (num_range_low_text);
		//get high range number 
size_t num_range_high_pos_in = work_text.find("end=",num_range_low_pos_in) + 4 ;
size_t num_range_high_pos_out = work_text.find(">\n",num_range_high_pos_in);
std::string num_range_high_text = work_text.substr(num_range_high_pos_in,num_range_high_pos_out -num_range_high_pos_in-1);
int range_high =get_number_from_string_V2 (num_range_high_text);
		//extract query
size_t query_in = work_text.find("ops:query syntax=",0) + 17 ;
size_t query_start = work_text.find(">",query_in) + 1 ;
size_t query_end = work_text.find("</ops:query>",query_start);
std::string query = work_text.substr(query_start,query_end -query_start);
std::cout << "text: "<< query<< std::endl;
int next_range_low=range_high+1;
int next_range_high=next_range_low + 99;
if(next_range_high>number_result) next_range_high=number_result;
char buf_low [50], buf_high [50];
int n;
  n=sprintf (buf_low, "%d",next_range_low);
  n=sprintf (buf_high, "%d",next_range_high);
std::cout << "text: "<<next_range_low<<"  "<<next_range_high << std::endl;
std::string query_range = query + "&Range="+buf_low +"-"+ buf_high; 

std::cout << "text: "<< query_range<< std::endl;
write_buffer_to_file();
		//extract docs and send to worklist
//extern FenetrePrincipale window;
//window.put_workfile_in_object(work_text);
 number_result_extracted = range_high;
if (next_range_low<next_range_high)
{
size_t ok = requeteweb(query_range,1);
}

}while(number_result_extracted<number_result);

}


void	extract_doc_from_results()
{
int number_result_extracted = 0;
int number_result=0;
do{
std::string work_text = web_response_string.get_string_from_web();
		//get number of docs
size_t num_result_pos_in = work_text.find("total-result-count=",0) + 19 ;
size_t num_result_pos_out = work_text.find(">\n",num_result_pos_in);
std::string num_result_text = work_text.substr(num_result_pos_in,num_result_pos_out -num_result_pos_in-1);
 number_result =get_number_from_string (num_result_text);
		//get low range number 
size_t num_range_low_pos_in = work_text.find("begin=",num_result_pos_in) + 6 ;
size_t num_range_low_pos_out = work_text.find("end",num_range_low_pos_in);
std::string num_range_low_text = work_text.substr(num_range_low_pos_in,num_range_low_pos_out -num_range_low_pos_in-2);
 int range_low =get_number_from_string (num_range_low_text);
		//get high range number 
size_t num_range_high_pos_in = work_text.find("end=",num_range_low_pos_in) + 4 ;
size_t num_range_high_pos_out = work_text.find(">\n",num_range_high_pos_in);
std::string num_range_high_text = work_text.substr(num_range_high_pos_in,num_range_high_pos_out -num_range_high_pos_in-1);
int range_high =get_number_from_string (num_range_high_text);
		//extract query
size_t query_in = work_text.find("ops:query syntax=",0) + 17 ;
size_t query_start = work_text.find(">",query_in) + 1 ;
size_t query_end = work_text.find("</ops:query>",query_start);
std::string query = work_text.substr(query_start,query_end -query_start);
std::cout << "text: "<< query<< std::endl;
int next_range_low=range_high+1;
int next_range_high=next_range_low + 99;
if(next_range_high>number_result) next_range_high=number_result;
char buf_low [50], buf_high [50];
int n;
  n=sprintf (buf_low, "%d",next_range_low);
  n=sprintf (buf_high, "%d",next_range_high);
std::cout << "text: "<<next_range_low<<"  "<<next_range_high << std::endl;
std::string query_range = query + "&Range="+buf_low +"-"+ buf_high; 

std::cout << "text: "<< query_range<< std::endl;
write_buffer_to_file();
		//extract docs and send to worklist
//extern FenetrePrincipale window;
//window.put_workfile_in_object(work_text);
 number_result_extracted = range_high;
if (next_range_low<next_range_high)
{
size_t ok = requeteweb(query_range,1);
}

}while(number_result_extracted<number_result);

}
int get_number_from_string(std::string num_result_text)
{
size_t length_result=num_result_text.size();
int num_result = 0;
 for(size_t i=0;i<length_result;i++)
{
	
	if (num_result_text.compare(i,1,"1") == 0)
	{
		num_result=num_result*10+1;
	}
	else if (num_result_text.compare(i,1,"2") == 0)
	{
		num_result=num_result*10+2;
	}
	else if (num_result_text.compare(i,1,"3") == 0)
	{
		num_result=num_result*10+3;
	}
	else if (num_result_text.compare(i,1,"4") == 0)
	{
		num_result=num_result*10+4;
	}
	else if (num_result_text.compare(i,1,"5") == 0)
	{
		num_result=num_result*10+5;
	}
	else if (num_result_text.compare(i,1,"6") == 0)
	{
		num_result=num_result*10+6;
	}
	else if (num_result_text.compare(i,1,"7") == 0)
	{
		num_result=num_result*10+7;
	}
	else if (num_result_text.compare(i,1,"8") == 0)
	{
		num_result=num_result*10+8;
	}
	else if (num_result_text.compare(i,1,"9") == 0)
	{
		num_result=num_result*10+9;
	}
	else if (num_result_text.compare(i,1,"0") == 0)
	{
		num_result=num_result*10+0;
	}
}
std::cout << "text: "<< num_result_text<< " length: " <<length_result << " number: " <<num_result << std::endl;
return num_result;
}
int FenetrePrincipale::get_number_from_string_V2(std::string num_result_text)
{
size_t length_result=num_result_text.size();
int num_result = 0;
 for(size_t i=0;i<length_result;i++)
{
	
	if (num_result_text.compare(i,1,"1") == 0)
	{
		num_result=num_result*10+1;
	}
	else if (num_result_text.compare(i,1,"2") == 0)
	{
		num_result=num_result*10+2;
	}
	else if (num_result_text.compare(i,1,"3") == 0)
	{
		num_result=num_result*10+3;
	}
	else if (num_result_text.compare(i,1,"4") == 0)
	{
		num_result=num_result*10+4;
	}
	else if (num_result_text.compare(i,1,"5") == 0)
	{
		num_result=num_result*10+5;
	}
	else if (num_result_text.compare(i,1,"6") == 0)
	{
		num_result=num_result*10+6;
	}
	else if (num_result_text.compare(i,1,"7") == 0)
	{
		num_result=num_result*10+7;
	}
	else if (num_result_text.compare(i,1,"8") == 0)
	{
		num_result=num_result*10+8;
	}
	else if (num_result_text.compare(i,1,"9") == 0)
	{
		num_result=num_result*10+9;
	}
	else if (num_result_text.compare(i,1,"0") == 0)
	{
		num_result=num_result*10+0;
	}
}
std::cout << "text: "<< num_result_text<< " length: " <<length_result << " number: " <<num_result << std::endl;
return num_result;
}

void write_buffer_to_file()
{
std::string string_in=web_response_string.get_string_from_web();
int pos_search_result_begin = string_in.find("<ops:search-result>",0) +19;
int pos_search_result_end = string_in.find("</ops:search-result>",pos_search_result_begin);
std::string buffer_to_add= string_in.substr(pos_search_result_begin,pos_search_result_end -pos_search_result_begin -8);

	std::ifstream work_file;
	work_file.open("CA.txt");
	if(work_file.is_open()) std::cout << "bon ca va la file"<<std::endl;
	std::string file="";
	std::string line;
	while ( work_file.good() )
	    {
      		getline (work_file,line);
      		file = file + line+"\n";
    	}
	work_file.close();

	//std::cout << file << std::endl;
	int lenth_file=file.size();
	int pos_slash_doc=file.find("</documents-list>",0);
	std::cout << "posistion : "<<pos_slash_doc << std::endl;
	if (pos_slash_doc == -1) pos_slash_doc = 0;
	std::string work_file_begin = file.substr(0,pos_slash_doc-1);
	std::string work_file_end = file.substr(pos_slash_doc ,lenth_file);
	std::string work_file_to_write = work_file_begin +buffer_to_add + work_file_end;
	std::fstream write_work_file;
	write_work_file.open("CA.txt",std::ios::in | std::ios::out);
	//write_work_file.seekp(pos_slash_doc);
	write_work_file << work_file_to_write ;
	write_work_file.close();
std::cout << "shit de marde"<<std::endl;
}

PagePosition::PagePosition()
{
page=1;
}
PagePosition::~PagePosition()
{
}
void PagePosition::zero_page()
{
page =1;
}
int PagePosition::get_page()
{
return page;
}
void PagePosition::add_a_page()
{
page=page+1;
}
//void FenetrePrincipale::set_path(std::string path)
//{
//std::string path;
//}
/*
reponce_web::reponce_web()
{
}
reponce_web::~reponce_web()
{
}*/
