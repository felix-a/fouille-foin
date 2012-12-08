#ifndef PANNEAUTEXTE_H
#define PANNEAUTEXTE_H

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include "preference.h"
#include "searchhistory.h"

class TextBuffer
{
public:

TextBuffer();
virtual ~TextBuffer();
void	initiate_buffer();
void 	add_string(std::string);
std::string get_buffer();
std::string text_buffer;
  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
private:

};

class PanneauTexte : public Gtk::ScrolledWindow {
public:
  PanneauTexte();
Searchhistory m_searchhistory;

  Gtk::TextView m_TextView;
  virtual ~PanneauTexte();
    bool key_pressed(GdkEventKey *event);
    bool has_the_focus();
void use_key(GdkEventKey *event,TextBuffer *text_buffer_panneau_ptr);
 void set_text_in_text_view(TextBuffer *text_buffer_panneau_ptr);
std::string construct_request_histroy_pn(std::string, Searchhistory *m_searchhistory_ptr);
protected:
//Searchhistory m_searchhistory;
//Signal handlers:
 size_t requetew(std::string);
  void fill_buffers();
 Gtk::ScrolledWindow m_ScrolledWindow;

std::string add_search_string(std::string);



// bool im_context_filter_keypress(GdkEventKey *event);
//{
  //  if(key->keyval == GDK_a)
  //      //do something when 'a' is pressed
//} 

  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1;
};
#endif
