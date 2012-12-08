#include <Magick++.h>
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

    Gtk::Main kit(argc, argv);
	Magick::InitializeMagick(*argv);

 FenetrePrincipale window;
	
 Gtk::Main::run(window);

  //Shows the window and returns when it is closed.
  //return app->run(window);
}
