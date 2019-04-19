#include <math.h>
#include "arc.h"
#include "sommet.h"

arc::arc(sommet *s1, sommet *s2, bool oriente, QGraphicsScene* parent) :
QGraphicsLineItem(s1->x()+sommet::WIDTH/2,s1->y()+sommet::WIDTH/2,s2->x()+sommet::WIDTH/2,s2->y()+sommet::WIDTH/2),
d_parent(parent), sdep(s1->getNum()), sarr(s2->getNum())
{
    if(oriente)
    {
        double x1 = s1->x()+sommet::WIDTH/2, y1 = s1->y()+sommet::WIDTH/2 ,
            x2 = s2->x()+sommet::WIDTH/2, y2 = s2->y()+sommet::WIDTH/2,
            x3 = x1 + (x2 - x1) / 5,
            y3 = y1 + (y2 - y1) / 5 ;
        double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) ;
        double angle = M_PI-acos((x2-x1)/dist) ;

        if(y2-y1 > 0)
            angle *= -1 ;

        d_parent->addLine(x3,y3,x3+cos(angle-30*M_PI/180)*15,y3+sin(angle-30*M_PI/180)*15) ;
        d_parent->addLine(x3,y3,x3+cos(angle+30*M_PI/180)*15,y3+sin(angle+30*M_PI/180)*15) ;
    }
}
