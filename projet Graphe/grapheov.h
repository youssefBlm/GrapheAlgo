#ifndef GRAPHEOV_H
#define GRAPHEOV_H

#include "graphe.h"

//graphe oriente, value
class grapheOV : public graphe
{
public:
    grapheOV() ;
    //creation d'un graphe a partir de la file des successeurs
    grapheOV(int *fs, int *aps, int **d_cout) ;
    virtual ~grapheOV() ;

    //affichage avec la matrice des couts
    virtual void afficher() const ;
    //ajout de l'arc entre s1 et s2 avec le cout c si celui-ci n'existe pas
    virtual void ajoutArc(int s1, int s2, int cout) ;
    //suppression de l'arc entre s1 et s2 si celui ci existe
    virtual void supprArc(int s1, int s2) ;
    //ajoute un sommet au graphe de numero nbSommet()+1 et redimensionne d_cout
    virtual void ajoutSommet() ;
    //supprime le sommet s et tous ses arcs si celui-ci existe et redimensionne d_cout
    virtual void supprSommet(int s) ;

    //retourne la matrice des couts du graphe courant
    int** couts() const ;
    //modification de la matrice des couts
    bool setCouts(int **couts) ;

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

    //retourne faux si un sommet est inaccessible
    //d contient la distance min par rapport au sommet s
    bool Dijkstra(int s, int* &d, int* &pere) const ;
    //return NULL si circuit absorbant
    int** Dantzig() const ;

//    bool bellman(int s, int *&d, int *&pere);
   // bool Ford(int s, int* &d, int *&pere) const ;
    bool circuit(int* fs, int* aps, int* statut, int s);

    grapheOV* Critique(int* &lc, int* &fpc, int*& appc, int*coutotal);
    void ordonnancement(int *&fs, int *&num);

    //retourn la file des pred a partir de la file des successeurs
    static int* fs2fp_(int *fs) ;
private:
    //matrice des couts
    int **d_cout ;

    //recherche l'indice ds d tq ins[i] = true et d[i] minimal
    int dmin(bool* ins, int *d) const ;
};

#endif


#ifndef GRAPHEOV_H
#define GRAPHEOV_H

#endif // GRAPHEOV_H
