#include "misealechelle.h"
#include "fenetreprincipale.h"
#include <glibmm/fileutils.h>


MiseAlEchelle::MiseAlEchelle()
{
	//last_x=178;
}

MiseAlEchelle::~MiseAlEchelle()
{


}
void MiseAlEchelle::alechelle_fenetre(GdkEventConfigure *event, FenetrePrincipale * fenetreprincipale_ptr )
{
//FenetrePrincipale * fenetreprincipale_ptr=&(*event->window);
std::cout<<"heille ca marche enfin: "<<event<<std::endl;
std::cout<<"X : "<<event->x<<std::endl;
std::cout<<"Y : "<<event->y<<std::endl;
std::cout<<"width : "<<event->width<<std::endl;
std::cout<<"height : "<<event->height<<std::endl;
std::cout<<"type : "<<event->type<<std::endl;

//if(event->width!=fenetreprincipale_ptr->maxi_width || event->height!=fenetreprincipale_ptr->maxi_height){
//fenetreprincipale_ptr->set_default_size(fenetreprincipale_ptr->preference.width, fenetreprincipale_ptr->preference.height);
//std::cout<<"ahlkjsdljflsdjkflsdj"<<std::endl;
//}

	if(event->type==true) std::cout<<"send_event : "<<"true"<<std::endl;
	else std::cout<<"send_event : "<<"false" <<std::endl;
	//int numberoftab = event->window->preference.number_of_tab;
	std::cout << "number of tabs : "<<(*fenetreprincipale_ptr).preference.number_of_tab /*numberoftab*/<<std::endl;
	//int window_width=fenetreprincipale_ptr->get_allocated_width ();
	//int window_height=fenetreprincipale_ptr->get_allocated_height ();
	for(int i=1;i<=(*fenetreprincipale_ptr).preference.number_of_tab;i++){
	//std::cout << "map pointer : "<<(*fenetreprincipale_ptr). /*numberoftab*/<<std::endl;
		double percent_left=(double(fenetreprincipale_ptr->preference.tab_structure_map[i-1]->panel_pref_structure.left_panel_cadre_largeur)/(fenetreprincipale_ptr->preference.tab_structure_map[i-1]->panel_pref_structure.left_panel_cadre_largeur + fenetreprincipale_ptr->preference.tab_structure_map[i-1]->panel_pref_structure.right_panel_cadre_largeur));
	 	int left_panel_width = floor((event->width - 10)* percent_left);
	std::cout<<"percent Left : "<<percent_left<<std::endl;
	//	int right_panel_width= event->width - 50 -left_panel_width;
	 //	int left_panel_height=fenetreprincipale_ptr->get_height()-65;
	//	int right_panel_height=fenetreprincipale_ptr->get_height()-65;
		std::cout<<"panel division: "<< left_panel_width<<std::endl;
		fenetreprincipale_ptr->	paned_map[i-1]->set_position(left_panel_width);
//		fenetreprincipale_ptr-> paned_map[i-1]->show_all();
		//fenetreprincipale_ptr->note_book_strure_map[i-1]->panneau1.set_size_request(left_panel_width,left_panel_height);
		//fenetreprincipale_ptr->note_book_strure_map[i-1]->panneau2.set_size_request(right_panel_width,right_panel_height);

	}
	/*	    Glib::RefPtr<Gdk::Window> win = fenetreprincipale_ptr->get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, fenetreprincipale_ptr->get_width(),
                fenetreprincipale_ptr->get_height());
        win->invalidate_rect(r, false);
	std::cout << " invalidate success"<<std::endl;
    }*/


//	last_x=event->x;
}
