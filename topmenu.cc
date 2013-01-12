#include "topmenu.h"
#include "fenetreprincipale.h"
#include <gtkmm/stock.h>
#include <iostream>

TopMenu::TopMenu()
{
  add(m_BoxMenu);  

 //Create actions for menus and toolbars:
  m_refActionGroup = Gtk::ActionGroup::create();

  //File|New sub menu:
 // m_refActionGroup->add(Gtk::Action::create("FileNewStandard",
   //           Gtk::Stock::NEW, "_New", "Create a new file"),
     //     sigc::mem_fun(*this, &TopMenu::on_menu_file_new_generic));

  /*m_refActionGroup->add(Gtk::Action::create("FileNewFoo",
              Gtk::Stock::NEW, "New Foo", "Create a new foo"),
          sigc::mem_fun(*this, &TopMenu::on_menu_file_new_generic));

  m_refActionGroup->add(Gtk::Action::create("FileNewGoo",
              Gtk::Stock::NEW, "_New Goo", "Create a new goo"),
          sigc::mem_fun(*this, &TopMenu::on_menu_file_new_generic));*/

  //File menu:
  m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
  //Sub-menu.
  m_refActionGroup->add(Gtk::Action::create("OpenWorkfile", 
				Gtk::Stock::OPEN, "_OpenWorkfile", "Open a workfile"),
			sigc::mem_fun(*this, &TopMenu::on_menu_file_open_workfile));

  m_refActionGroup->add(Gtk::Action::create("FileNew", 
				Gtk::Stock::NEW/*, "_New", "Create a new file"*/),
			sigc::mem_fun(*this, &TopMenu::on_menu_file_new_generic));

  m_refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
          sigc::mem_fun(*this, &TopMenu::on_menu_file_quit));

  //Edit menu:
  m_refActionGroup->add(Gtk::Action::create("EditMenu", "Edit"));
  m_refActionGroup->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY),
          sigc::mem_fun(*this, &TopMenu::on_menu_others));
  m_refActionGroup->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE),
          sigc::mem_fun(*this, &TopMenu::on_menu_others));
  m_refActionGroup->add(Gtk::Action::create("EditSomething", "Something"),
          Gtk::AccelKey("<control><alt>S"),
          sigc::mem_fun(*this, &TopMenu::on_menu_others));


  //Choices menu, to demonstrate Radio items
  m_refActionGroup->add( Gtk::Action::create("ChoicesMenu", "Choices") );
  Gtk::RadioAction::Group group_userlevel;
  m_refChoiceOne = Gtk::RadioAction::create(group_userlevel, "ChoiceOne", "One");
  m_refActionGroup->add(m_refChoiceOne,
          sigc::mem_fun(*this, &TopMenu::on_menu_choices_one) );
  m_refChoiceTwo = Gtk::RadioAction::create(group_userlevel, "ChoiceTwo", "Two");
  m_refActionGroup->add(m_refChoiceTwo,
          sigc::mem_fun(*this, &TopMenu::on_menu_choices_two) );

  //Help menu:
  m_refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
  m_refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
          sigc::mem_fun(*this, &TopMenu::on_menu_others) );

  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);

  //add_accel_group(m_refUIManager->get_accel_group());

  //Layout the actions in a menubar and toolbar:
  Glib::ustring ui_info = 
        "<ui>"
        "  <menubar name='MenuBar'>"
        "    <menu action='FileMenu'>"
		"		<menuitem action='OpenWorkfile'/>"
        "      	<menuitem action='FileNew'/>"
//        "        <menuitem action='FileNewStandard'/>"
//        "        <menuitem action='FileNewFoo'/>"
//        "        <menuitem action='FileNewGoo'/>"
//        "      </menu>"
        "      <separator/>"
        "      <menuitem action='FileQuit'/>"
        "    </menu>"
        "    <menu action='EditMenu'>"
        "      <menuitem action='EditCopy'/>"
        "      <menuitem action='EditPaste'/>"
        "      <menuitem action='EditSomething'/>"
        "    </menu>"
        "    <menu action='ChoicesMenu'>"
        "      <menuitem action='ChoiceOne'/>"
        "      <menuitem action='ChoiceTwo'/>"
        "    </menu>"
        "    <menu action='HelpMenu'>"
        "      <menuitem action='HelpAbout'/>"
        "    </menu>"
        "  </menubar>"
        "  <toolbar  name='ToolBar'>"
        "    <toolitem action='FileNewStandard'/>"
        "    <toolitem action='FileQuit'/>"
        "  </toolbar>"
        "</ui>";

  try
  {
    m_refUIManager->add_ui_from_string(ui_info);
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "building menus failed: " <<  ex.what();
  }

  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = m_refUIManager->get_widget("/MenuBar");
  if(pMenubar)
    m_BoxMenu.pack_start(*pMenubar, Gtk::PACK_SHRINK);

 // Gtk::Widget* pToolbar = m_refUIManager->get_widget("/ToolBar") ;
 // if(pToolbar)
  //  m_BoxMenu.pack_start(*pToolbar, Gtk::PACK_SHRINK);

  show_all_children();
}

TopMenu::~TopMenu()
{
}

void TopMenu::on_menu_file_quit()
{
    hide(); //Closes the main window to stop the Gtk::Main::run().
}

void TopMenu::on_menu_file_new_generic()
{
   std::cout << "A File|New menu item was selected." << std::endl;
} 

void TopMenu::on_menu_file_open_workfile()
{
//	std::cout <<"load a file"<<std::endl;
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  //dialog.set_transient_for(*this);

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
	preference_topmenu_Ptr->setworkfile(filename);
        std::cout << "File selected: " <<  filename << std::endl;
		std::string window_title="Fouille Foin : fichier de travail : "+ filename_only;
pointer_principale->set_title (window_title);

	std::string workfiledata=m_workfile1_Ptr->load_workfile(filename);

  std::cout << "document map pointer second time: " << pointer_principale <<std::endl;

			m_workfile1_Ptr->put_workfile_in_object_fuck(workfiledata,document_map_ptr_menu,pointer_principale);

//	std::string workfiledata=m_workfile1.load_workfile(filename);
//	put_workfile_in_object(workfiledata);
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

void TopMenu::on_menu_others()
{
  std::cout << "A menu item was selected." << std::endl;
}

void TopMenu::on_menu_choices_one()
{
  Glib::ustring message;
  if(m_refChoiceOne->get_active()) 
    message = "Choice 1 was selected.";
  else
    message = "Choice 1 was deselected";

  std::cout << message << std::endl;
}

void TopMenu::on_menu_choices_two()
{   
  Glib::ustring message;
  if(m_refChoiceTwo->get_active())
    message = "Choice 2 was selected.";
  else
    message = "Choice 2 was deselected";

  std::cout << message << std::endl;
}
void TopMenu::grab_preference(Preference * preference_topmenu_Ptr)
{
std::string dude=preference_topmenu_Ptr->getworkfile();
std::cout<<"what is the work file now: "<<dude<<std::endl;

}
void TopMenu::grab_document_map_menu(std::map<size_t, Document*> * document_map_ptr_menu)
{
  std::cout << "document map pointer" << document_map_ptr_menu <<std::endl;
TopMenu::document_map_ptr_menu=document_map_ptr_menu;
//string_poiter = (int)&document_map_ptr_menu;
//  std::cout << "document map pointer" << string_poiter <<std::endl;
}
void TopMenu::grab_worklist1(WorkFile *m_workfile1_Ptr)
{


}
void	TopMenu::grab_fenetre_principale(FenetrePrincipale * pointer_principale)
{
TopMenu::pointer_principale=pointer_principale;
  std::cout << "document map pointer second time: " << pointer_principale <<std::endl;
}

void TopMenu::grab_documentmap()
{
}
