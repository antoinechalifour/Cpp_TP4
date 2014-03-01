#include <iostream>
#include <stdio.h>
#include "Chaine.h"
#include "CTableGType.h"
#include "DynamicTable.h"

using namespace std;

template <class T>
void swapT(T&a, T&b){
	T tmp;
	tmp=a;
	a=b;
	b=tmp;
}

ostream& operator<<(ostream& os, const Chaine& c){
    os<<c.getString();
    return os;
}

int main(){
    // --------------- SWAP
    /*
	int i=5;
	int j=6;

	cout<<"i= "<<i<<" j= "<<j<<endl;
	swapT<int>(i,j);
	cout<<"i= "<<i<<" j= "<<j<<endl;

	double f=5.55, g=6.66;
	cout<<"f= "<<f<<" g= "<<g<<endl;
	swapT<double>(f,g);
	cout<<"f= "<<f<<" g= "<<g<<endl;

	Chaine s="chaine_1", t="chaine2";
	cout<<"s= "<<s<<" t= "<<t<<endl;
	swapT<Chaine>(s,t);
	cout<<"s= "<<s<<" t= "<<t<<endl;
	*/

	//-------------- Table generique
    /*
	CTableGType<int, 15> table;
	int i, elmnt;

	table.pushElement(0);
	table.pushElement(1);
	table.pushElement(2);
	table.pushElement(3);

	cout<<"La table contient "<<table.getSize()<<" elements :"<<endl;
	for(i=0; i<table.getSize() ; i++)
		cout<<"table["<<i<<"] = "<<table[i]<<endl;

	table[2]=5;
	elmnt=table.popElement();

	cout<<"La table contient "<<table.getSize()<<" elements :"<<endl;
	for(i=0; i<table.getSize() ; i++)
		cout<<"table["<<i<<"] = "<<table[i]<<endl;

	cout<<"elmnt : "<<elmnt<<endl;
	try{
		elmnt=table[10];
	}
	catch(int e){
		cout<<e<<" - bad index exception"<<endl;
	}
	*/

	DynamicTable<int, 2> dt;
	DynamicTable<int, 2> dt2;
	int i=1, j=2, k=3, l=4, m=5;

    try{
        cout<<"Remplissage de dt..."<<endl;
        dt.pushElement(i);
        dt.pushElement(j);
        dt.pushElement(k);
        dt.pushElement(l);
        dt.pushElement(m);

        cout<<"Affichage de dt..."<<endl;
        cout<<"dt  > i ="<<dt[0]<<endl;
        cout<<"dt  > j ="<<dt[1]<<endl;
        cout<<"dt  > k ="<<dt[2]<<endl;
        cout<<"dt  > l ="<<dt[3]<<endl;
        cout<<"dt  > m ="<<dt[4]<<endl<<endl;

        cout<<"Remplissage de dt2 via = sur dt..."<<endl;
        dt2=dt;

        cout<<"Popage de dt2..."<<endl;
        cout<<"dt2 > m ="<<dt2.popElement()<<endl;
        cout<<"dt2 > l ="<<dt2.popElement()<<endl;
        cout<<"dt2 > k ="<<dt2.popElement()<<endl;
        cout<<"dt2 > j ="<<dt2.popElement()<<endl;
        cout<<"dt2 > i ="<<dt2.popElement()<<endl<<endl;

        cout<<"Creation de dt3 par recopie de dt..."<<endl;
        DynamicTable<int, 2> dt3=dt;

        cout<<"Affichage de dt..."<<endl;
        cout<<"dt  > i ="<<dt[0]<<endl;
        cout<<"dt  > j ="<<dt[1]<<endl;
        cout<<"dt  > k ="<<dt[2]<<endl;
        cout<<"dt  > l ="<<dt[3]<<endl;
        cout<<"dt  > m ="<<dt[4]<<endl<<endl;

        cout<<"Affichage de dt3..."<<endl;
        cout<<"dt3 > i ="<<dt3[0]<<endl;
        cout<<"dt3 > j ="<<dt3[1]<<endl;
        cout<<"dt3 > k ="<<dt3[2]<<endl;
        cout<<"dt3 > l ="<<dt3[3]<<endl;
        cout<<"dt3 > m ="<<dt3[4]<<endl<<endl;
    }
    catch (int e){
        cout<<"An exception occured. Code : "<<e;
    }
}
