#include "sommet.h"
#include<QGraphicsSceneMouseEvent>
#include<QInputDialog>

sommet::sommet(QWidget *parent, int num, double x, double y):
QGraphicsEllipseItem(0,0,WIDTH,HEIGHT), d_num(num), d_parent(parent), d_info(QString::number(num))
{
    setPos(x,y) ;
    setOpacity(1.0) ;
    setZValue(1) ;
    setToolTip(d_info) ;

    setBrush(QBrush(QColor(Qt::gray),Qt::SolidPattern)) ;
}

sommet::~sommet()
{	}

void sommet::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        WGraphe *g = static_cast<WGraphe *>(d_parent) ;

        if(g->getSS())
            g->supprimerSommet(d_num) ;

        else if(g->getAA())
        {
            if(g->dep == 0)
            {
                g->dep = this->d_num ;

            }
            else
            {
                g->arr = this->d_num ;
                if(g->value)
                {
                    bool ok ;
                    int rep = QInputDialog::getInt(NULL, QString("Cout"), QString("Cout de l'arc:"),0,-99,99,1,&ok) ;
                    if(ok)
                        g->ajouterArc(g->dep,g->arr,rep) ;
                }
                else
                    g->ajouterArc(g->dep,g->arr,0) ;

                g->arr = 0 ;
                g->dep = 0 ;
            }

        }
        else if(g->getSA())
        {
            if(g->dep == 0)
            {
                g->dep = this->d_num ;

            }
            else
            {
                g->arr = this->d_num ;
                g->supprimerArc(g->dep,g->arr) ;
                g->arr = 0 ;
                g->dep = 0 ;
            }
        }
        else if(g->getE())
        {
            QString str = QInputDialog::getText(d_parent, "Enregistrement", "Texte :") ;
            setInfo(str) ;

        }
        else
            event->ignore() ;
    }
}
