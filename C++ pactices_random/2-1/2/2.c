#include<stdio.h>

typedef struct
{
int xpos;
int ypos;
}Point;

Point getScale2xPoint(Point* p){
    Point p2;
    p2.xpos = p->xpos* 2;
    p2.ypos = p->ypos* 2;
    return p2;
}

void swapPoints(Point* p1, Point* p2){
    int tmp;

    tmp = p1->xpos;
    p1->xpos = p2->xpos;
    p2->xpos = tmp;
    
    tmp = p1->ypos;
    p1->ypos = p2->ypos;
    p2->ypos = tmp;
    
    printf("P1 : %d %d\n", p1->xpos, p1->ypos);
    printf("P2 : %d %d\n", p2->xpos, p2->ypos);
}

int main(void){
    Point p1;
    Point p2;
    
    scanf("%d %d", &p1.xpos, &p1.ypos);  
    p2 = getScale2xPoint(&p1);
    
    printf("Calling getScale2xPoint()\n");
    printf("P1 : %d %d\n", p1.xpos, p1.ypos);
    printf("P2 : %d %d\n", p2.xpos, p2.ypos);
    
    printf("Calling swapPoints()\n");
    swapPoints(&p1, &p2);
}
