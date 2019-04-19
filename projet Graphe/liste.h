#ifndef LISTE_H
#define LISTE_H

#include <iostream>

using std::ostream ;

class graphe ;
class princ ;
class sec ;

class liste
{
public:
    //liste vide
    liste() ;
    //liste principale de nbSommet
    liste(int nbSommet) ;
    //liste correspodant au graphe g
    liste(const graphe& g) ;
    ~liste() ;

    bool affiche(ostream &os) const ;

private:
    princ* d_tete ;
};

ostream& operator<<(ostream& os, const liste& l) ;

//liste principale des sommets
class princ
{
    friend class liste ;

public:
    princ(double info, princ *suiv = NULL, sec *succ = NULL) ;
    ~princ() ;

private:
    double d_info ; //numero du sommet
    princ *d_suiv ; //sommet suivant dans la liste princ
    sec *d_succ ; //successeur
};

//liste secondaire des succ
class sec
{
    friend class princ ;
    friend class liste ;

public:
    sec(double info, princ* som = NULL, sec *succ = NULL) ;

private:
    double d_info ; //numero du succ
    sec * d_succ ; //successeur suivant
    princ* d_som ; //sommet

};

#endif
