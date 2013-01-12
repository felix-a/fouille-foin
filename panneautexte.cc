#include <gtkmm/stock.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "fenetreprincipale.h"
#include "panneautexte.h"
#include "requeteweb.h"
#include "searchhistory.h"
#include "/usr/include/gtk-3.0/gdk/gdkkeysyms.h"

extern WebResponseString  web_response_string;

PanneauTexte::PanneauTexte()
{
      std::cout <<  "yomand= " << std::endl;
 m_ScrolledWindow.add(m_TextView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
add(m_ScrolledWindow);

  m_refTextBuffer1 = Gtk::TextBuffer::create();

  m_refTextBuffer1->set_text("/?: ");
  m_TextView.set_buffer(m_refTextBuffer1);
//iciiciciciicicici
m_TextView.signal_key_press_event().connect(sigc::mem_fun(*this,&PanneauTexte::key_pressed),false);  
//signal_key_press_event().connect(sigc::mem_fun(*this,&PanneauTexte::key_pressed)); 
//std::cout <<  hum << std::endl;  
	//bool enter = m_TextView.im_context_filter_keypress(GdkEventKey GDK_KEY_Execute);
//GDK_KEY_Execute

//signal_key_press_event().connect(sigc::mem_fun(*this,&MyClass::key_pressed),false);

  show_all_children();

}

PanneauTexte::~PanneauTexte()
{
}

bool PanneauTexte::key_pressed(GdkEventKey *event)
{
   
if (event->keyval == GDK_KEY_A || event->keyval == GDK_KEY_a ||
    event->keyval == GDK_KEY_B || event->keyval == GDK_KEY_b ||	
    event->keyval == GDK_KEY_C || event->keyval == GDK_KEY_c ||	
    event->keyval == GDK_KEY_D || event->keyval == GDK_KEY_d ||	
    event->keyval == GDK_KEY_E || event->keyval == GDK_KEY_e ||	
    event->keyval == GDK_KEY_F || event->keyval == GDK_KEY_f ||	
    event->keyval == GDK_KEY_G || event->keyval == GDK_KEY_g ||	
    event->keyval == GDK_KEY_H || event->keyval == GDK_KEY_h ||	
    event->keyval == GDK_KEY_I || event->keyval == GDK_KEY_i ||	
    event->keyval == GDK_KEY_J || event->keyval == GDK_KEY_j ||	
    event->keyval == GDK_KEY_K || event->keyval == GDK_KEY_k ||	
    event->keyval == GDK_KEY_L || event->keyval == GDK_KEY_l ||	
    event->keyval == GDK_KEY_M || event->keyval == GDK_KEY_m ||	
    event->keyval == GDK_KEY_N || event->keyval == GDK_KEY_n ||	
    event->keyval == GDK_KEY_O || event->keyval == GDK_KEY_o ||	
    event->keyval == GDK_KEY_P || event->keyval == GDK_KEY_p ||	
    event->keyval == GDK_KEY_Q || event->keyval == GDK_KEY_q ||	
    event->keyval == GDK_KEY_R || event->keyval == GDK_KEY_r ||	
    event->keyval == GDK_KEY_S || event->keyval == GDK_KEY_s ||	
    event->keyval == GDK_KEY_T || event->keyval == GDK_KEY_t ||	
    event->keyval == GDK_KEY_U || event->keyval == GDK_KEY_u ||	
    event->keyval == GDK_KEY_V || event->keyval == GDK_KEY_v ||	
    event->keyval == GDK_KEY_W || event->keyval == GDK_KEY_w ||	
    event->keyval == GDK_KEY_X || event->keyval == GDK_KEY_x ||	
    event->keyval == GDK_KEY_Y || event->keyval == GDK_KEY_y ||	
    event->keyval == GDK_KEY_Z || event->keyval == GDK_KEY_z ||
    event->keyval == GDK_KEY_0 || event->keyval == GDK_KEY_5 ||
    event->keyval == GDK_KEY_1 || event->keyval == GDK_KEY_6 ||	
    event->keyval == GDK_KEY_2 || event->keyval == GDK_KEY_7 ||	
    event->keyval == GDK_KEY_3 || event->keyval == GDK_KEY_8 ||	
    event->keyval == GDK_KEY_4 || event->keyval == GDK_KEY_9 ||
    event->keyval == GDK_KEY_backslash || event->keyval == GDK_KEY_slash ||
    event->keyval == GDK_KEY_minus || event->keyval == GDK_KEY_plus ||
    event->keyval == GDK_KEY_comma || event->keyval == GDK_KEY_period ||					
    event->keyval == GDK_KEY_parenright || event->keyval == GDK_KEY_parenleft ||
    event->keyval == GDK_KEY_asterisk || event->keyval == GDK_KEY_space ||
    event->keyval == GDK_KEY_semicolon || event->keyval == GDK_KEY_colon ||
    event->keyval == GDK_KEY_less || event->keyval == GDK_KEY_greater ||
    event->keyval == GDK_KEY_equal || event->keyval == GDK_KEY_question ||
    event->keyval == GDK_KEY_quoteright || event->keyval == GDK_KEY_quoteleft ||					
    event->keyval == GDK_KEY_percent || event->keyval == GDK_KEY_underscore	
)
{

Glib::ustring bufferNew = m_refTextBuffer1->get_text() + event->keyval;

  // Set the new buffer text to the actual buffer
  m_refTextBuffer1->set_text(bufferNew);


 //std::cout <<  "sd " << (event->keyval) << std::endl; 
	m_TextView.set_buffer(m_refTextBuffer1);  

}
else if(event->keyval == GDK_KEY_Left)
{


//Gtk::TextMark TextMark=m_refTextBuffer1->get_insert();
//m_refTextBuffer1.add_mark(m_refTextBuffer1->get_insert(),true);
Gtk::TextIter TextIter=m_refTextBuffer1->get_iter_at_mark(m_refTextBuffer1->get_insert());
	TextIter.backward_char();
	m_refTextBuffer1->place_cursor(TextIter);
//   	m_TextView.move_visually(m_refTextBuffer1.iterator,-1)preferencepreferencepreference;
}
else if (event->keyval == GDK_KEY_Right)
{
Gtk::TextIter TextIter=m_refTextBuffer1->get_iter_at_mark(m_refTextBuffer1->get_insert());
	TextIter.forward_char();
	m_refTextBuffer1->place_cursor(TextIter);
}					
else if (event->keyval == GDK_KEY_Up)
{
Gtk::TextIter TextIter=m_refTextBuffer1->get_iter_at_mark(m_refTextBuffer1->get_insert());
	TextIter.backward_char();
	m_refTextBuffer1->place_cursor(TextIter);
}
else if (event->keyval == GDK_KEY_Down)
{
Gtk::TextIter TextIter=m_refTextBuffer1->get_iter_at_mark(m_refTextBuffer1->get_insert());
	TextIter.forward_char();
	m_refTextBuffer1->place_cursor(TextIter);
}		
else if (event->keyval == GDK_KEY_BackSpace)
{
  m_refTextBuffer1->backspace(m_refTextBuffer1->get_iter_at_mark(m_refTextBuffer1->get_insert()),true,true);
}
 else if((event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter))
	{
	Glib::ustring oldbuffer=m_refTextBuffer1->get_text();
	std::string test = oldbuffer;
	size_t n_place= test.rfind("/?:");
	size_t string_n_letters=test.size();
	size_t length=string_n_letters-n_place-4;
	std::string requete= " " + test.substr(n_place +4, length) + " ";
	requete=add_search_string(requete);
	std::string sortie=requete;


//std::string requete=
std::cout <<  "n_place " << n_place <<"  "<< string_n_letters <<" " << length<< std::endl;
std::cout << "requete: " << sortie <<std::endl;  
	//Glib::ustring EPOquary=quaryisolator(querybuffer);
std::string dot_dot = requete.substr(1,2);
std::cout << "requete:" << dot_dot << "::"<<std::endl;  
	if (dot_dot==".."){
		if(requete.substr(0,5) ==" ..dv"||requete.substr(0,5)==" ..DV"){
		std::cout << "dv or DV: " << requete <<std::endl;  

		extract_doc_from_results();
Gtk::Widget* parent = get_parent();
		std::cout << "parent: " << parent <<std::endl; 
Gtk::Widget* parentb = get_parent()->get_parent();
Gtk::Widget* parentc = get_parent()->get_parent()->get_parent();
Gtk::Widget* parentd = get_parent()->get_parent()->get_parent()->get_parent();
Gtk::Widget* parente = get_parent()->get_parent()->get_parent()->get_parent()->get_parent();
Gtk::Widget* parentf = get_parent()->get_parent()->get_parent()->get_parent()->get_parent()->get_parent();
Gtk::Widget* parent2 = get_parent()->get_parent()->get_parent()->get_parent()->get_parent()->get_parent()->get_parent();
		std::cout << "parent: " << parent2 <<std::endl; 
	std::string strhelpb=parentb->get_name();
	std::string strhelpc=parentc->get_name();
	std::string strhelpd=parentd->get_name();
	std::string strhelpe=parente->get_name();
	std::string strhelpf=parentf->get_name();
	std::string strhelp=parent2->get_name();
GtkWidget* worklistcombo = parent2->gobj();//child_focus(Gtk::DIR_LEFT);
		std::string  toute=parent2->get_composite_name() ;
//		std::vector<Gtk::Container>
//	std::string humm =worklistcombo;//>get_name;
	          //strhelp=toute.get_name();
		std::cout << "parent hein: " << strhelpb << std::endl;
		std::cout << "parent hein: " << strhelpc << std::endl;
		std::cout << "parent hein: " << strhelpd << std::endl;
		std::cout << "parent hein: " << strhelpe << std::endl;
		std::cout << "parent hein: " << strhelpf << std::endl;
		std::cout << "parent hein: " << strhelp << " humm " << toute << std::endl; 
	Glib::ustring bufferNew = oldbuffer  + "\n sending document to viewer\n/?: " ;

  	m_refTextBuffer1->set_text(bufferNew);
	m_TextView.set_buffer(m_refTextBuffer1); 


		}


	}
	else{
size_t result=requeteweb(requete,1);
size_t search_number=m_searchhistory.add_seach_string(requete);

//std::ifstream t("body.out",std::ifstream::in);
//std::stringstream buffer;
//buffer << t.rdbuf();
//t.close();
  std::string reponse_webe =  web_response_string.get_string_from_web();
std::cout << reponse_webe << "::"<< std::endl;
int pos_result = reponse_webe.find("total-result-count=",1) + 19;
int pos_result_end_line = reponse_webe.find(">",pos_result);
std::cout << pos_result_end_line <<" :: "<<pos_result <<std::endl;
std::string num_result_brut=reponse_webe.substr(pos_result,pos_result_end_line-pos_result-1);
size_t num_result=0;
size_t length_result=num_result_brut.size();
size_t i;
std::cout << num_result_brut <<std::endl;
	
 for(i=1;i<=length_result;i++)
{
	
	if (num_result_brut.compare(i,1,"1") == 0)
	{
		num_result=num_result*10+1;
	}
	else if (num_result_brut.compare(i,1,"2") == 0)
	{
		num_result=num_result*10+2;
	}
	else if (num_result_brut.compare(i,1,"3") == 0)
	{
		num_result=num_result*10+3;
	}
	else if (num_result_brut.compare(i,1,"4") == 0)
	{
		num_result=num_result*10+4;
	}
	else if (num_result_brut.compare(i,1,"5") == 0)
	{
		num_result=num_result*10+5;
	}
	else if (num_result_brut.compare(i,1,"6") == 0)
	{
		num_result=num_result*10+6;
	}
	else if (num_result_brut.compare(i,1,"7") == 0)
	{
		num_result=num_result*10+7;
	}
	else if (num_result_brut.compare(i,1,"8") == 0)
	{
		num_result=num_result*10+8;
	}
	else if (num_result_brut.compare(i,1,"9") == 0)
	{
		num_result=num_result*10+9;
	}
	else if (num_result_brut.compare(i,1,"0") == 0)
	{
		num_result=num_result*10+0;
	}
}
//	std::cout << "resultats: " << num_result <<std::endl;  

	Glib::ustring bufferNew = oldbuffer  + "\n recherche #" + std::to_string(search_number) + " resultats: " + std::to_string(num_result) + "\n/?: " ;

  // Set the new buffer text to the actual buffer
  	m_refTextBuffer1->set_text(bufferNew);


 //std::cout <<  "sd " << (event->keyval) << std::endl; 
	m_TextView.set_buffer(m_refTextBuffer1); 
}
};

return true;
} 

size_t PanneauTexte::requetew(std::string requetebrut)
{
//std::string requetebrut;
std::cout << "requete: " << requetebrut <<std::endl;
return 1;  
}
std::string PanneauTexte::construct_request_histroy_pn(std::string requete, Searchhistory *m_searchhistory_ptr)
{
size_t total_num_search_statements = m_searchhistory_ptr->get_number_of_search_strings();
std::cout << "total_num_search_statements" << total_num_search_statements <<std::endl;  
	//size_t string_to_add[total_num_search_statements];
	size_t j=0;	
	for (size_t i=1; i<=total_num_search_statements;i++){
		std::string num_string= " " + std::to_string(i) + " "; 
		std::cout << "num string" << num_string << ":"<<std::endl;  
			size_t pos=requete.find(num_string,0);		

			std::string pos_char=std::to_string(pos);
			size_t length_pos = pos_char.size() +2;
		std::cout << "pos " << pos << ":"<<"pos char :"<< pos_char <<":"<<std::endl; 
		if (pos < std::string::npos)
		{
		 if(requete.compare(pos,length_pos,num_string) == 0){

				requete.erase(pos,length_pos);
				std::string insert=m_searchhistory_ptr->get_search_string(i);
				std::cout<<"the string history selected: "<<std::endl;
				if(insert.compare(0,1," ") == 0)				 
					insert=insert.erase(0,1);
				size_t length_insert=insert.size()-1;
				if(insert.compare(length_insert,1," ") ==0)
					insert=insert.erase(length_insert,1);
				requete.insert(pos," ("+ insert +") ");
//	sting_to_add[j] =i;		
		};
		};
	}
	size_t length_requete=requete.size()-1;
	if(requete.compare(length_requete,1," ") ==0)
	requete=requete.erase(length_requete,1);

return requete;
}

std::string PanneauTexte::add_search_string( std::string requete)
{

size_t total_num_search_statements = m_searchhistory.get_number_of_search_strings();
std::cout << "total_num_search_statements" << total_num_search_statements <<std::endl;  
	//size_t string_to_add[total_num_search_statements];
	size_t j=0;	
	for (size_t i=1; i<=total_num_search_statements;i++){
		std::string num_string= " " + std::to_string(i) + " "; 
		std::cout << "num string" << num_string <<std::endl;  
			size_t pos=requete.find(num_string,0);		
			std::string pos_char=std::to_string(pos);
			size_t length_pos = pos_char.size() +2;

		 if(requete.compare(0,length_pos,num_string) == 0){

				requete.erase(pos,length_pos);
				std::string insert=m_searchhistory.get_search_string(i);
				if(insert.compare(0,1," ") == 0)				 
					insert=insert.erase(0,1);
				size_t length_insert=insert.size()-1;
				if(insert.compare(length_insert,1," ") ==0)
					insert=insert.erase(length_insert,1);
				requete.insert(pos,"("+ insert +")" +" ");
//	sting_to_add[j] =i;		
		};
	}
	size_t length_requete=requete.size()-1;
	if(requete.compare(length_requete,1," ") ==0)
	requete=requete.erase(length_requete,1);
return requete;
//std::string requete_ptr;
 
}
bool PanneauTexte::has_the_focus()
{
bool test= m_TextView.has_focus();
return test;
}
void PanneauTexte::use_key(GdkEventKey *event,TextBuffer *text_buffer_panneau_ptr)
{
std::string dudes=text_buffer_panneau_ptr->get_buffer();
std::cout << "caractere et buffer: "<< char(event->keyval) << dudes << " : "<<event->keyval<< std::endl;

 char hehee;
hehee=(char)event->keyval;
//std::cout << hehe<<"  "<<hehee << std::endl;
if (event->keyval == GDK_KEY_A || event->keyval == GDK_KEY_a ||
    event->keyval == GDK_KEY_B || event->keyval == GDK_KEY_b ||	
    event->keyval == GDK_KEY_C || event->keyval == GDK_KEY_c ||	
    event->keyval == GDK_KEY_D || event->keyval == GDK_KEY_d ||	
    event->keyval == GDK_KEY_E || event->keyval == GDK_KEY_e ||	
    event->keyval == GDK_KEY_F || event->keyval == GDK_KEY_f ||	
    event->keyval == GDK_KEY_G || event->keyval == GDK_KEY_g ||	
    event->keyval == GDK_KEY_H || event->keyval == GDK_KEY_h ||	
    event->keyval == GDK_KEY_I || event->keyval == GDK_KEY_i ||	
    event->keyval == GDK_KEY_J || event->keyval == GDK_KEY_j ||	
    event->keyval == GDK_KEY_K || event->keyval == GDK_KEY_k ||	
    event->keyval == GDK_KEY_L || event->keyval == GDK_KEY_l ||	
    event->keyval == GDK_KEY_M || event->keyval == GDK_KEY_m ||	
    event->keyval == GDK_KEY_N || event->keyval == GDK_KEY_n ||	
    event->keyval == GDK_KEY_O || event->keyval == GDK_KEY_o ||	
    event->keyval == GDK_KEY_P || event->keyval == GDK_KEY_p ||	
    event->keyval == GDK_KEY_Q || event->keyval == GDK_KEY_q ||	
    event->keyval == GDK_KEY_R || event->keyval == GDK_KEY_r ||	
    event->keyval == GDK_KEY_S || event->keyval == GDK_KEY_s ||	
    event->keyval == GDK_KEY_T || event->keyval == GDK_KEY_t ||	
    event->keyval == GDK_KEY_U || event->keyval == GDK_KEY_u ||	
    event->keyval == GDK_KEY_V || event->keyval == GDK_KEY_v ||	
    event->keyval == GDK_KEY_W || event->keyval == GDK_KEY_w ||	
    event->keyval == GDK_KEY_X || event->keyval == GDK_KEY_x ||	
    event->keyval == GDK_KEY_Y || event->keyval == GDK_KEY_y ||	
    event->keyval == GDK_KEY_Z || event->keyval == GDK_KEY_z ||
    event->keyval == GDK_KEY_0 || event->keyval == GDK_KEY_5 ||
    event->keyval == GDK_KEY_1 || event->keyval == GDK_KEY_6 ||	
    event->keyval == GDK_KEY_2 || event->keyval == GDK_KEY_7 ||	
    event->keyval == GDK_KEY_3 || event->keyval == GDK_KEY_8 ||	
    event->keyval == GDK_KEY_4 || event->keyval == GDK_KEY_9 ||
    event->keyval == GDK_KEY_backslash || event->keyval == GDK_KEY_slash ||
    event->keyval == GDK_KEY_minus || event->keyval == GDK_KEY_plus ||
    event->keyval == GDK_KEY_comma || event->keyval == GDK_KEY_period ||					
    event->keyval == GDK_KEY_parenright || event->keyval == GDK_KEY_parenleft ||
    event->keyval == GDK_KEY_asterisk || event->keyval == GDK_KEY_space ||
    event->keyval == GDK_KEY_semicolon || event->keyval == GDK_KEY_colon ||
    event->keyval == GDK_KEY_less || event->keyval == GDK_KEY_greater ||
    event->keyval == GDK_KEY_equal || event->keyval == GDK_KEY_question ||
    event->keyval == GDK_KEY_quoteright || event->keyval == GDK_KEY_quoteleft ||					
    event->keyval == GDK_KEY_percent || event->keyval == GDK_KEY_underscore ||
    event->keyval == GDK_KEY_quotedbl || event->keyval == GDK_KEY_apostrophe		
)
{
 std::string tappe;
 tappe =hehee;

text_buffer_panneau_ptr->add_string(tappe);

//m_TextView.set_buffer(text_buffer_panneau_ptr->m_refTextBuffer);
set_text_in_text_view(text_buffer_panneau_ptr);
}
else if(event->keyval == GDK_KEY_Left)
{
Gtk::TextIter TextIter=text_buffer_panneau_ptr->m_refTextBuffer->get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert());
	TextIter.backward_char();
	text_buffer_panneau_ptr->m_refTextBuffer->place_cursor(TextIter);
//   	m_TextView.move_visually(m_refTextBuffer1.iterator,-1)preferencepreferencepreference;
}
else if (event->keyval == GDK_KEY_Right)
{
Gtk::TextIter TextIter=text_buffer_panneau_ptr->m_refTextBuffer->get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert());
	TextIter.forward_char();
	text_buffer_panneau_ptr->m_refTextBuffer->place_cursor(TextIter);
}					
else if (event->keyval == GDK_KEY_Up)
{
Gtk::TextIter TextIter=text_buffer_panneau_ptr->m_refTextBuffer->get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert());
	TextIter.backward_char();
	text_buffer_panneau_ptr->m_refTextBuffer->place_cursor(TextIter);
}
else if (event->keyval == GDK_KEY_Down)
{
Gtk::TextIter TextIter=text_buffer_panneau_ptr->m_refTextBuffer->get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert());
	TextIter.forward_char();
	text_buffer_panneau_ptr->m_refTextBuffer->place_cursor(TextIter);
}		
else if (event->keyval == GDK_KEY_BackSpace)
{
  text_buffer_panneau_ptr->m_refTextBuffer->backspace(text_buffer_panneau_ptr->m_refTextBuffer->get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert()),true,true);
}
}
void PanneauTexte::set_text_in_text_view(TextBuffer *text_buffer_panneau_ptr)
{
m_TextView.set_buffer(text_buffer_panneau_ptr->m_refTextBuffer);
//Gtk::TextIter TextIter=text_buffer_panneau_ptr->m_refTextBuffer->end();//get_iter_at_mark(text_buffer_panneau_ptr->m_refTextBuffer->get_insert());
m_TextView.scroll_to(text_buffer_panneau_ptr->m_refTextBuffer->get_insert(),0);
//m_TextView.scroll_to(TextIter,0);
}
TextBuffer::TextBuffer()
{
std::string text_buffer="";
  m_refTextBuffer = Gtk::TextBuffer::create();
  m_refTextBuffer->set_text("/?: ");
}
TextBuffer::~TextBuffer()
{
}

void TextBuffer::initiate_buffer()
{
text_buffer="/?: ";

}
void TextBuffer::add_string(std::string to_add)
{
//std::string buf=text_buffer;
std::string oldbuf = m_refTextBuffer->get_text();
std::string newbuf =oldbuf+to_add;
m_refTextBuffer->set_text(newbuf);
//std::cout << "dddd"<< m_refTextBuffer->get_text()<< std::endl;
}
std::string TextBuffer::get_buffer()
{
return text_buffer;
}
