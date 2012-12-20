#ifndef TOPMENU_H
#define TOPMENU_H
#include "workfile.h"
#include "preference.h"

#include <gtkmm.h>
class FenetrePrincipale;
//Tree model columns:



class TopMenu : public Gtk::Box
{
public:

	TopMenu();
	virtual ~TopMenu();
	//Tirroirs worklist_drawer_pour_menu;
	FenetrePrincipale * pointer_principale;
	void grab_fenetre_principale(FenetrePrincipale *);
	Preference *preference_topmenu_Ptr;
	void grab_document_map_menu(std::map<size_t, Document*> *);
std::map<size_t, Document*> m_map_menu, * document_map_ptr_menu;
	int string_poiter;
	WorkFile *m_workfile1_Ptr;
void grab_worklist1(WorkFile*);
void grab_documentmap();
void grab_preference(Preference*);

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
