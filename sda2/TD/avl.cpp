#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_noeud {
	int r;
	unsigned int	h;
	struct s_noeud *fg, *fd;
} noeud, *avl;

avl avlnouv();
avl enrac(int x, avl g, avl d);
avl racine(avl a);
avl ag(avl a);
avl ad(avl a);
bool vide(avl a);
bool appartient(avl a, int x);
bool est_trie(avl a);
void affiche(avl a);
unsigned int hauteur(avl a);
int deseq(avl a);
avl reeq(avl a);
avl insavl(avl a, int x);
avl supavl(avl a, int x);
avl otermax1(avl a);
int max(avl a);
int min(avl a);

/////////////////////////////
avl avlnouv() { return NULL; }

// fonction interne
void updateh(avl a)
{
	if (a->fg == NULL && a->fd == NULL) a->h = 0;
	else if (a->fg == NULL) a->h = 1 + a->fd->h;
	else if (a->fd == NULL) a->h = 1 + a->fg->h;
	else a->h = 1 + (a->fg->h > a->fd->h ? a->fg->h : a->fd->h);
}

avl enrac(int x, avl g, avl d)
{
	avl n = (avl)malloc(sizeof(noeud));
	n->r = x;
	n->fg = g;
	n->fd = d;
	updateh(n);
	return n;
}

avl ag(avl a)
{
	if (a != NULL) return a->fg;
	return NULL;
}

avl ad(avl a)
{
	if (a != NULL) return a->fd;
	return NULL;
}

bool vide(avl a) { return a == NULL; }

bool appartient(avl a, int x)
{
	if (a == NULL) return false;
	if (a->r == x) return true;
	else if (x<a->r) return appartient(a->fg, x);
	else return appartient(a->fd, x);
}

bool est_trie(avl a)
{
	bool estTrie = true;
	if (a == NULL) return true;
	if (a->fg != NULL) estTrie = (a->r > max(a->fg)) && est_trie(a->fg);
	if (a->fd != NULL) estTrie = (a->r < min(a->fd)) && est_trie(a->fd);
	return estTrie;
}

unsigned int hauteur(avl a) { return a->h; }

void affiche(avl a)
{
	if (a == NULL) return;
	affiche(a->fg);
	printf("%d(%u) ", a->r, a->h);
	affiche(a->fd);
}

// rotations
avl	rd(avl a)
{
	avl temp;

	if (a == NULL) abort(); // erreur
	if (a->fg == NULL) abort(); // erreur
	temp = a->fg;
	a->fg = temp->fd;
	updateh(a);
	temp->fd = a;
	updateh(temp);
	return temp;
}

avl	rg(avl a)
{
	avl temp;

	if (a == NULL) abort(); // erreur
	if (a->fd == NULL) abort(); // erreur
	temp = a->fd;
	a->fd = temp->fg;
	updateh(a);
	temp->fg = a;
	updateh(temp);
	return temp;
}

avl	rgd(avl a)
{
	a->fg = rg(a->fg);
	updateh(a);
	return rd(a);
}

avl	rdg(avl a)
{
	a->fd = rd(a->fd);
	updateh(a);
	return rg(a);
}

// equilibrage
int deseq(avl a) 
{ 
	int hg = a->fg == NULL ? -1 : (int)a->fg->h;
	int hd = a->fd == NULL ? -1 : (int)a->fd->h;
	return hg-hd;  
}

avl reeq(avl a)
{
 	int de = deseq(a);
 	if (de == 0 || de == -1 || de == 1) return a;
 	if (de == +2 && deseq(a->fg) > 0) return rd(a);
 	if (de == -2 && deseq(a->fd) < 0) return rg(a);
 	if (de == +2 && deseq(a->fg) <= 0) return rgd(a);
 	if (de == -2 && deseq(a->fd) >= 0) return rdg(a);
 	return a;
}


avl insavl(avl a, int x)
{
	if (a == NULL) return enrac(x, avlnouv(), avlnouv());
	if (x <= a->r)  a->fg = insavl(a->fg, x);
	else a->fd = insavl(a->fd, x);
	updateh(a);
	return reeq(a);
}

avl otermax1(avl a)
{
	if (a->fd == NULL) return a->fg;
	a->fd = otermax1(a->fd);
	updateh(a);
	return reeq(a);
}

int max(avl a)
{
	if (a->fd == NULL) return a->r;
	return max(a->fd);
}

int min(avl a)
{
	if (a->fg == NULL) return a->r;
	return min(a->fg);
}

avl supavl(avl a, int x)
{
	if (a == NULL) return NULL;
	if (a->r == x)
	{
		if (a->fd == NULL) return a->fg;
		if (a->fg == NULL) return a->fd;
		a->r = max(a->fg);
		a->fg = otermax1(a->fg);
		updateh(a);
		return reeq(a);
	}
	if (x<a->r) a->fg = supavl(a->fg, x);
	else a->fd = supavl(a->fd, x);
	updateh(a);
	return reeq(a);
}


////////////////////////////////////
int main()
{
	avl a = insavl(avlnouv(), 6);
	a = insavl(a, 3);
	a = insavl(a, 1);
	a = insavl(a, 4);
	a = insavl(a, 5);
	a = insavl(a, 7);
	a = insavl(a, 9);
	a = insavl(a, 14);

	avl b = insavl(avlnouv(), 2);
	b = insavl(b, 1);
	b = insavl(b, 3);
	b = insavl(b, 4);

	printf("existe %d: %s\n", 9, appartient(a, 9) ? "oui" : "non");
	printf("existe %d: %s\n", 4, appartient(a, 4) ? "oui" : "non");
	printf("Hauteur a = %u\n", hauteur(a));
	affiche(a); printf("\n");
	printf("a est trié ? %d\n", est_trie(a));
	printf("Hauteur b = %u\n", hauteur(b));
	affiche(b); printf("\n");
	printf("b est trié ? %d\n", est_trie(b));


	printf("ins feuille %d\n", 10);
	a = insavl(a, 10); 
	printf("Hauteur a = %u\n", hauteur(a));
	affiche(a); printf("\n");
	
	printf("sup %d\n", 3);
	a = supavl(a, 3);
	affiche(a); printf("\n");
	printf("sup %d\n", 7);
	a = supavl(a, 7);
	printf("Hauteur a = %u\n", hauteur(a));
	affiche(a); printf("\n");
}

