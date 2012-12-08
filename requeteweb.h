#ifndef REQUETEWEB_H
#define REQUETEWEB_H
#include <vector>
#include <string>
#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>

size_t requeteweb(std::string,size_t);
size_t requeteweb_2(std::string,size_t,std::string *web_html_response_ptr);
std::string prep_requete(std::string);
 // Glib::RefPtr<Gtk::TextBuffer> m_responce_buffer1;
void load_buffer();
class WebResponseString
{
public:
WebResponseString();
virtual ~WebResponseString();

void set_string_from_web(std::string);
void add_string_from_web(std::string);
std::string get_string_from_web();
void set_zero_from_web();

private:
std::string web_response;
};

class WebResponseImage
{
public:
WebResponseImage();
virtual ~WebResponseImage();

void set_image_from_web(std::string);
void add_image_from_web(std::string);
std::string get_image_from_web();
void set_zero_from_web_image();
void write_pdf_file();

private:
std::string web_response_image;
};
//extern WebResponseString web_response_string();
#endif
