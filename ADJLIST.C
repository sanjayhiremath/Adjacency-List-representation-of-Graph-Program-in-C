
#include<cr7.h>
#include<stdio.h>
struct node
{
 int adj;
 struct node *nxt;
};
struct vertex
{
  struct vertex *nxt;
  struct node *first;
  int v;
};
struct vertex *start;
struct vertex *findvertex(int);
void insver();
void insedge();
void delver();
void deledge();
void dis();
void main()
{
int ch,i;
start=NULL;
  while(1)
  {

   clrscr();
  // PF(".............................SINGLY LINKED LIST.........................");
   PF("\nPRESS 1:     INSERT VERTEX\nPRESS 2:     INSERT EDGE\nPRESS 3:     DELETE VERTEX\nPRESS 4:     DELETE EDGE\nPRESS 5:    DISPLAY\nPRESS 0:     EXIT");
   PF("\nENTER YOUR CHOICE:");
   SF("%d",&ch);
   switch(ch)
   {
     case 0:exit(0);
     case 1:insver();       break;
     case 2:insedge();    break;
     case 3:delver();    break;
     case 4:deledge();  break;
     case 5:dis();       break;
     default:PF("\nWrong Choice");
   }
     getch();
  }
 }
struct vertex *findver(int u)
{
 struct vertex *p;
 p=start;
 while(p!=NULL)
 {
  if(p->v==u)
    return p;
  p=p->nxt;
 }
 return p;
}
void insver()
{
  struct vertex *p,*t;
  int u ;
  PF("\nENTER THE VERTEX TO BE ADDED:");
  SF("%d",&u);
  if(start==NULL)
  {
    t=(struct vertex*)malloc(sizeof(struct vertex));
    t->v=u;
    t->nxt=t->first=NULL;
    start=t;
    return;
  }
  p=start;
  while(p->nxt!=NULL && p->v!=u)
    p=p->nxt;
 if(p->v==u)
 {
   PF("\nVERTEX %d IS ALREADY PRESENT",p->v);
   return;
 }
    t=(struct vertex*)malloc(sizeof(struct vertex));
    t->v=u;
    t->nxt=t->first=NULL;
    p->nxt=t;
}
void insedge()
{
 int s,d;
 struct vertex *la,*lb;
 struct node *p,*t;
 PF("\nENTER SOURCE AND DEST VER RESPECTIVELY:");
 SF("%d%d",&s,&d);
 la=findver(s);
 if(la==NULL)
 {
  PF("\nSTART VER %d DOESNT FOUND",s);
  return;
 }
 lb=findver(d);
  if(lb==NULL)
 {
  PF("\nDEST VER %d DOESNT FOUND",s);
  return;
 }
  t=(struct node*)malloc(sizeof(struct node));
  t->adj=d;
  t->nxt=NULL;
  if(la->first==NULL)
  {
    la->first=t;
    return;
  }

  p=la->first;
  while(p->nxt!=NULL && p->adj!=d)
    p=p->nxt;

  if(p->adj==d)
  {
    PF("%d IS ALREADY PRESENT",d);
    return;
  }
  p->nxt=t;
}
void dis()
{
   struct vertex *v1;
   struct node *n1;
   if(start==NULL)
   {
    PF("\nGRAPH IS NOT PRESENT\n");
    return;
   }
   PF("\n");
   v1=start;
   while(v1!=NULL)
   {
      PF("\n   %d->   ",v1->v);
      n1=v1->first;

      while(n1!=NULL)
      {
       PF("%d->",n1->adj);
       n1=n1->nxt;
      }
      v1=v1->nxt;
   }
//   n1=start->first;
}
void deledge()
{
  struct vertex *la;
    struct node *t,*t1;
  int s,d;
  PF("\nENTER SOURCE AND DEST VER RESPECTIVELY:");
  SF("%d%d",&s,&d);
  la=findver(s);
  if(la==NULL)
  {
    PF("\nSTART vERTEX %d DOESNT FOUNd",s);
    return;
  }
  if(la->first==NULL)
  {
    PF("\nEDGE DOESNT PREESENT");
    return;
  }
  t=la->first;
  if(t->adj==d)
  {
   la->first=t->nxt;
   return;
  }
  while(t!=NULL)
  {
    if(t->adj==d)
    {
     t1->nxt=t->nxt;
     free(t);
     return;
    }
    t1=t;
    t=t->nxt;
  }

    PF("\nEDGE DOESN,T PREESENT");
}
void delver()
{
  int u ;
  struct vertex  *v1,*v2,*v3,*v4;
  struct node  *t1,*t2,*t3,*t4,*t5;
  if(start==NULL)
  {
   PF("\nGRAPH IS NOT PRESENT");
   return;
  }
  PF("\nENTER THE VERTEX TO BE DELETED:");
  SF("%d",&u);
  if(start->v==u)
  {
    t1=start;
    start=start->nxt;
   // free(t1);
  }
 //finding delvertex
  else
  {
    v1=start;
    while(v1->nxt!=NULL)
    {
      if(v1->v==u)
	 break;
      v2=v1;
      v1=v1->nxt;
    }
    if(v1->v==u)
     {
	  v2->nxt=v1->nxt;
	   free(v1);
     }
     else
     {
      PF("\nVER NOT FOUND");
      return;
     }
  }

 //deleteing all edges consisting delver
  v3=start;


  while(v3!=NULL)
  {
  loop:
    if(v3->first==NULL)
    {
     v3=v3->nxt;
     continue;
    }
     t5=v3->first;
    if(t5->adj==u)
    {
      t3=v3->first;
      v3->first=t3->nxt;
      free(t3);
      break;
    }
       t4=v3->first;
    while(t4!=NULL)
    {
      if(t4->adj== u)
      {
	t3->nxt=t4->nxt;
	free(t4);
	break;
      }
      t3=t4;
      t4=t4->nxt;
    }
     v3=v3->nxt;
   }

}


