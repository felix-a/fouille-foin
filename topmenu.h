#ifndef TOPMENU_H
#define TOPMENU_H

#include <gtkmm.h>

class TopMenu : public Gtk::Box
{
public:

	TopMenu();
	virtual ~TopMenu();

void grab_worklist_combo();
void grab_documentmap();

protected:

	//signal handler
  void on_menu_file_open_workfile();
  void on_menu_file_new_generic();
  void on_menu_file_quit();
  void on_menu_others();

  void on_menu_choices_one();
  void on_menu_choices_two();


  //Child widgets:
  Gtk::VBox m_BoxMenu;

  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;

};
#endif
