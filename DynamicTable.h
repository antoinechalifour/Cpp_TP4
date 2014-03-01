#include <iostream>
#include <stdlib.h>
#include <string.h>

#ifndef DYNAMICTABLE_H_INCLUDED
#define DYNAMICTABLE_H_INCLUDED

using namespace std;

template<class T, int N=10>
class DynamicTable{
private:
	T** tab;
	int count;
	int indexBlock;
public:
	DynamicTable();
	DynamicTable(const DynamicTable<T, N>&);
	~DynamicTable();
	DynamicTable& operator=(const DynamicTable<T, N>&);
	T operator[](int i) const;
	T& operator[](int i);
	int getSize();
	void pushElement(T i);
	T popElement();
};

template<class T, int N> DynamicTable<T, N>::DynamicTable():
    count(0),
    indexBlock(-1)
{
    tab= (T**) malloc(sizeof(T*));
    tab[++indexBlock]= (T*) malloc(N*sizeof(T));
}


template <class T, int N>DynamicTable<T, N>::DynamicTable(const DynamicTable<T, N>& dt):
    count(0),
    indexBlock(-1)
{
    tab= (T**) malloc(sizeof(T*));
    tab[++indexBlock]= (T*) malloc(N*sizeof(T));
    for(int i=0 ; i<dt.count ; i++){
        pushElement(dt[i]);
	}
}


template<class T, int N> T DynamicTable<T, N>::operator[](int i) const{
	if(i<0) throw -1;
	if(i>=count) throw -2;
	return tab[i/N][i%N];
}

template<class T, int N> T& DynamicTable<T, N>::operator[](int i){
	if(i<0) throw -1;
	if(i>=count) throw -2;
	return tab[i/N][i%N];
}


template<class T, int N> DynamicTable<T, N>& DynamicTable<T, N>::operator=(const DynamicTable<T, N>& dt){
	for(int i=0 ; i<dt.count ; i++){
        pushElement(dt[i]);
	}

	return *this;
}

template<class T, int N> int DynamicTable<T, N>::getSize(){
	return count;
}

template<class T, int N> void DynamicTable<T, N>::pushElement(T i){
	if(count != 0 && count%N == 0){ //allouer des nouveaux blocks quand le block courant est plein.
	    T** tmp= (T**) malloc(sizeof(tab)); // sauvegarde pour gérer le cas où realloc trouve une autre zone
	    memcpy(tmp, tab, sizeof(tab)); //copie de la zone courante

	    indexBlock++;
	    tab=(T**) realloc(tab, (indexBlock+1)*sizeof(T*));
        if(tab == NULL) throw -6 ; //on realloue le tableau de blocks pour l'agrandird | exception si fail
        memcpy(tab, tmp, sizeof(tmp)); //restauration de la zone en cas de zone différente
        if((tab[indexBlock]= (T*) malloc(N*sizeof(T))) == NULL) throw -2; //on alloue N*size of type du tableau au block courant | exception si fail
	}

	//ajout de l'élément
    tab[count/N][count%N]= i;
    count++;
}


template<class T, int N> T DynamicTable<T, N>::popElement(){
    if(count==0) throw -1;
    T ret = tab[(count-1)/N][(count-1)%N];

    count--;
    if(count%N==N-1) {
        cout<<"Destruction de tab["<<indexBlock<<"]"<<endl;
        free(tab[indexBlock--]);
    }

	return ret;
}

template<class T, int N> DynamicTable<T, N>::~DynamicTable(){
    for(int i=0 ; i<=indexBlock ; i++){
        free(tab[i]);
    }
    free(tab);
}

#endif // DYNAMICTABLE_H_INCLUDED
