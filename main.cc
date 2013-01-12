#include <Magick++.h>
#include <gtk/gtk.h>
#include "fenetreprincipale.h"
#include "requeteweb.h"
//#include "main.h"

//#include <gtkmm/application.h>

WebResponseString web_response_string;
WebResponseImage   web_response_image_obj;
  //FenetrePrincipale window;
int main(int argc, char *argv[])
{
//  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
GtkWidget *window_try;

//gtk_init(argc, *argv);
//window_try=gtk_window_new (GTK_WINDOW_TOPLEVEL);
    Gtk::Main kit(argc, argv);
	Magick::InitializeMagick(*argv);

 FenetrePrincipale window;
window.add_events(Gdk::PROPERTY_CHANGE_MASK);
//window_try.add(widow);
 Gtk::Widget * window_ptr;
window_ptr=&window;
 // gtk_widget_add_events(GTK_WIDGET(window_try), GDK_CONFIGURE);	
//g_signal_connect(G_OBJECT(window_ptr), "configure-event", G_CALLBACK(&FenetrePrincipale::frame_callback), NULL);
 Gtk::Main::run(window);




//slot prototype: developer.gnome.org./gtkmm/unstable/classGtk_1_1Widget.html
  //Shows the window and returns when it is closed.
  //return app->run(window);
}
