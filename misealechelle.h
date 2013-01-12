#ifndef MISEALECHELLE_H
#define MISEALECHELLE_H

//#include "fenetreprincipale.h"
#include <gtkmm.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
class FenetrePrincipale;

class MiseAlEchelle
{
public:
MiseAlEchelle();
virtual ~MiseAlEchelle();
		FenetrePrincipale *fenetreprincipale_ptr;
	void alechelle_fenetre(GdkEventConfigure *event,FenetrePrincipale *fenetreprincipale_ptr);
	 

private:
int last_x;
int largeur_fenetre;
int hauteur_fenetre;

};
#endif
