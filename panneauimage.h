#ifndef PANNEAUIMAGE_H
#define PANNEAUIMAGE_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class PanneauImage : public Gtk::DrawingArea
{
public:
  PanneauImage();
  virtual ~PanneauImage();
	void reload();
 void on_image_change(std::string, int);
  Glib::RefPtr<Gdk::Pixbuf> m_image,m_image_2;
//protected:
  //Override default signal handler:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);


};

#endif // GTKMM_EXAMPLE_MYAREA_H
