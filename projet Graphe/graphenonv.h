#ifndef GRAPHENONV_H
#define GRAPHENONV_H

#include "graphe.h"

//graphe non-oriente, non-value
class grapheNONV : public graphe
{
public:
    grapheNONV() ;
    //creation d'un grapheNONV a partir d'une matrice d'adjacence
    grapheNONV(int **adj);
    //creation d'un grapheNONV a partir de la file des successeurs
    grapheNONV(int *fs, int *aps) ;
    virtual ~grapheNONV() ;

    //ajout de l'arc entre s1 et s2 si celui-ci n'existe pas
    virtual void ajoutArc(int s1, int s2, int c = 0) ;
    //suppression de l'arc entre s1 et s2 si celui ci existe
    virtual void supprArc(int s1, int s2) ;

    //Prufer
    //retourne false si le graphe n'est pas un arbre
    bool est_arbre(int *&d);
    //retourne la matrice d'adjacence correspondant au codage de Prufer passé en parametre
    static int** decodage(int *d);

private:
    //dedouble toutes les aretes du graphes si celles-ci n'existent pas
    //pour obtenir un graphe non-oriente
    void dedoublerAretes() ;
};

#endif
