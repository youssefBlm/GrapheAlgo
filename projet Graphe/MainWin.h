#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtGui>

#include<QCheckBox>
#include<QVBoxLayout>
#include<QPushButton>
#include "WGraphe.h"
#include "graphe.h"
#include "grapheOV.h"
#include "grapheNONV.h"
#include "grapheNOV.h"
#include "grapheONV.h"
#include<QMainWindow>

// fenetre principale du programme
class Mainwin : public QMainWindow
{
    Q_OBJECT
public:
    Mainwin() ;
    virtual ~Mainwin() ;

    void afficherTab(int *tab);

    public slots:
        //menu fichier
        void chargerGraphe() ;
        void sauvegarderGraphe() ;
        void nouveauGraphe() ;

        //dockwidget
        void setAjoutSom() ;
        void setSupprSom() ;
        void setAjoutArc() ;
        void setSupprArc() ;
        void setEnregistrement() ;

        //menu graphe

        void rang() ;
        void distances() ;
        void dessinerDijkstra() ;
        void redessinerGraphe() ;
        void coderPrufer() ;
        void dessinerKruskal() ;
        void afficherDantzig() ;

private:
    //widget du graphe
    WGraphe *wid ;
    //widget et table pour l'affichage des distances
    QWidget *w ;
    QTableWidget *table ;

    //element de la boite a outils
    QDockWidget *dock ;
    QWidget *dockwid ;
    QPushButton *ajoutsom, *supprsom, *ajoutarc, *supprarc, *enregistrement ;
    QCheckBox *value, *oriente;
    QVBoxLayout *dockLayout ;

    //elements du menu
    QMenu *fichier ;
    QMenu *graph ;

    //action des menu
    QAction *quitter ;
    QAction *nveau ;
    QAction *charger ;
    QAction *sauvegarder ;
    QAction *dessiner ;
    QAction *rg ;
    QAction *dist ;
    QAction *Dijkstra ;
    QAction *prufer ;
    QAction *kruskal ;
    QAction *dantzig ;
    QAction *ordo ;
    QAction *color;

    //largeur et hauteur de la fenetre
    static const int HAUT = 700, LARG = 700 ;
};

#endif
