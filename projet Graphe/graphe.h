#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <fstream>

using namespace std ;

class liste ;

class graphe
{
   friend class liste ;
public:
    graphe() ;
    //construire un graphe donne par la file de ses successeurs
    graphe(int *fs, int *aps) ;
    //construire un graphe donne par sa matrice d'adjacence
    graphe(int **adj) ;
    virtual ~graphe() ;

    //affiche les succ de chaque sommet
    virtual void afficher() const ;
    //ajoute un arc entre s1 et s2 si celui-ci n'existe pas
    virtual void ajoutArc(int s1, int s2, int cout = 0) ;
    //supprime un arc entre s1 et s2 si celui-ci existe
    virtual void supprArc(int s1, int s2) ;
    //ajoute un sommet au graphe de numero nbSommet()+1
    virtual void ajoutSommet() ;
    //supprime le sommet s et tous ses arcs si celui-ci existe
    virtual void supprSommet(int s) ;

    graphe& operator=(const graphe &g) ;

    //nombre de sommets du graphe courant
    int nbSommet() const ;
    //file des successeurs du graphe courant
    int* fs() const ;
    //adresse des successeurs dans fs
    int* aps() const ;
    //modification du graphe
    void setFs(int *fs) ;
    void setAps(int *aps) ;

    //affiche simplement fs et aps
    void fs_aps() const ;

    //retourne la matrice d'adjacence du graphe courant
    int** fs2adj() const ;
    //retourne le graphe sous forme de liste
   // liste& fs2liste() const ;

    //lecture et ecriture du graphe dans un fichier
    static graphe* lire(ifstream &is) ;
    static bool ecrire(graphe &g, ofstream &os) ;
    //retourne le tableau aps associe a fs
    static int* fs2aps(int *fs) ;

protected:
    int *d_fs, *d_aps ;

};

#endif
