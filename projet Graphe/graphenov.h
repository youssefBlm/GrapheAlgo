#ifndef GRAPHENOV_H
#define GRAPHENOV_H

#include "graphe.h"

//graphe non-oriente, value
class grapheNOV : public graphe
{
public:
    grapheNOV() ;
    //creation d'un grapheNONV a partir de la file des successeurs
    grapheNOV(int *fs, int *aps, int **cout) ;
    virtual ~grapheNOV() ;

    //affichage avec la matrice des couts
    virtual void afficher() const ;
    //ajout de l'arc entre s1 et s2 avec le cout c si celui-ci n'existe pas
    virtual void ajoutArc(int s1, int s2, int c) ;
    //suppression de l'arc entre s1 et s2 si celui ci existe
    virtual void supprArc(int s1, int s2) ;
    //ajoute un sommet au graphe de numero nbSommet()+1 et redimensionne d_cout
    virtual void ajoutSommet() ;
    //supprime le sommet s et tous ses arcs si celui-ci existe et redimensionne d_cout
    virtual void supprSommet(int s) ;

    //retourne la matrice des couts du graphe courant
    int** couts() const ;
    //modification de la matrice des couts
    //renvoie false si la matrice des cout n'est pas de la bonne taille
    bool setCouts(int **couts) ;


    //d contient la distance min par rapport au sommet s
    bool Dijkstra(int s, int* &d, int* &pere) const ;

    //creer la matrice d'ajdacence
    void Kruskal(int **&arrete);

private:
    //dedouble toutes les aretes du graphes si celles-ci n'existent pas
    //pour obtenir un graphe non-oriente
    void dedoublerAretes() ;
    //recherche l'indice ds d tq ins[i] = true et d[i] minimal
    int dmin(bool* ins, int *d) const ;

    //matrice des couts
    int **d_cout ;
};

#endif
