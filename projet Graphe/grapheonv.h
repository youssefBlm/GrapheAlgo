#ifndef GRAPHEONV_H
#define GRAPHEONV_H

#include "graphe.h"

//graphe oriente, non-value
class grapheONV : public graphe
{
public:
    grapheONV() ;
    grapheONV(int *fs, int *aps) ;

    //retourne le nb de pred de chaque sommet
    int* nb_pred() const ;
    //retourne la matrice des distance
    int* dist(int s) const ;
    //calcul du rang
    int* rang(int *&pilch, int *&prem) const ;
    //retourne la file des pred
    int* fs2fp() const ;
    //retourne le pred dans le chemin critique
    int* det_pred() const ;
    //retourne le plus long chemin arrivant a s
    int* chemin(int s) const ;

};

#endif
