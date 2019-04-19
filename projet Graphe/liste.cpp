
#include "liste.h"
#include "graphe.h"

using std::ostream ;
using std::endl ;

liste::liste() : d_tete(NULL)
{	}

liste::liste(int nbSommet) : d_tete(NULL)
{
    if(nbSommet == 0)
        d_tete = NULL ;
    else //creation de la liste principale
    {
        d_tete = new princ(1) ;

        princ *tmp = d_tete ;

        for(int i=2 ; i<=nbSommet ; ++i)
        {
            tmp->d_suiv = new princ(i) ;
            tmp = tmp->d_suiv ;
        }
    }
}

liste::liste(const graphe& g) : d_tete(NULL)
{
    int nbSom = g.nbSommet() ;

    if(nbSom != 0)
    {
        //creation de la liste principale
        d_tete = new princ(1) ;

        princ *tmp = d_tete ;

        for(int i=2 ; i<=nbSom ; ++i)
        {
            tmp->d_suiv = new princ(i) ;
            tmp = tmp->d_suiv ;
        }

        //creation des listes secondaires
        int sommet = 1,
            k = 1,
            n = g.d_fs[k] ;

        princ *rech = d_tete ;
        //sec *succ = d_tete->d_succ ;
        sec *succ ;
        tmp = d_tete;

        //tq on a pas traite tous les sommets
        while(sommet <= nbSom)
        {
            bool prem = true ;
            //tq le sommet courant a des successeurs
            while(n != 0)
            {
                //recherche du succ ds la liste princ
                for(int j=1 ; j<n ; ++j)
                    rech = rech->d_suiv ;
                if(prem)
                {
                    tmp->d_succ = new sec(rech->d_info, rech) ;
                    succ = tmp->d_succ ;
                    prem = false ;
                }else
                {
                    //on cree le succ
                    succ->d_succ = new sec(rech->d_info, rech) ;
                    //on met a jour
                    succ = succ->d_succ ;
                }
                n = g.d_fs[++k] ;
                rech = d_tete ;
            }
            //on passe au sommet suivant
            ++sommet ;
            tmp = tmp->d_suiv ;
            n = g.d_fs[++k] ;
            //on traite maintenant les succ du sommet pointÃ© par tmp
        }
    }
}

liste::~liste()
{
    if(d_tete != NULL)
    {
        princ *tmp = d_tete ;

        while(tmp != NULL)
        {
            tmp = d_tete->d_suiv ;
            delete d_tete ;
            d_tete = tmp ;
        }
    }
}

bool liste::affiche(ostream &os) const
{
    if(!os.good())
        return false ;

    if(d_tete == NULL)
    {
        os << "Liste vide" << endl ;
        return true ;
    }

    princ *sommet = d_tete ;
    sec *succ = d_tete->d_succ ;
    while(sommet != NULL)
    {
        os << "Succ de " << sommet->d_info << " : " ;
        while(succ != NULL)
        {
            os << succ->d_info << " " ;
            succ = succ->d_succ ;
        }
        os << endl ;

        sommet = sommet->d_suiv ;
        if(sommet != NULL)
            succ = sommet->d_succ ;
        else
            succ = NULL ;

    }
    return true ;

}

ostream& operator<<(ostream& os, const liste& l)
{
    l.affiche(os) ;
    return os ;
}

princ::princ(double info, princ *suiv, sec *succ) :
    d_info(info), d_suiv(suiv), d_succ(succ)
{	}

princ::~princ()
{
    sec *tmp = d_succ ;

    while(tmp != NULL)
    {
        tmp = tmp->d_succ ;
        delete d_succ ;
        d_succ = tmp ;
    }
}

sec::sec(double info, princ *som, sec *succ) :
    d_info(info), d_succ(succ), d_som(som)
{	}



