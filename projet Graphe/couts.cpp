#include "couts.h"
#include "WGraphe.h"
#include<QGraphicsSceneMouseEvent>
#include<QInputDialog>

couts::couts(WGraphe *parent, int c, int s1, int s2) :
QGraphicsTextItem(QString::number(c)),d_parent(parent), d_cout(c),
    sdep(s1), sarr(s2)
{
}

couts::~couts()
{	}

void couts::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        bool ok ;
        WGraphe * graph = d_parent ;
        int s = sdep, ss = sarr ;
        int rep = QInputDialog::getInt(NULL, QString("Cout"), QString("Cout de l'arc:"),d_cout,-99,99,1,&ok) ;
        if(ok)
        {
            grapheOV *gOV = NULL ;
            grapheNOV * gNOV = NULL ;
            gOV = dynamic_cast<grapheOV *>(graph->gcourant) ;
            gNOV = dynamic_cast<grapheNOV *>(graph->gcourant) ;

            int **c = NULL ;

            if(gOV != NULL)
            {
                c = gOV->couts() ;
                c[s][ss] = rep ;
                gOV->setCouts(c) ;
            }
            else if(gNOV != NULL)
            {
                c = gNOV->couts() ;
                c[s][ss] = rep ;
                gNOV->setCouts(c) ;
            }
            graph->dessiner() ;

        }

    }
}
