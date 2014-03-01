#ifndef _CTableGTypeT_H
#define _CTableGTypeT_H

template<class T, int N=10>
class CTableGType{
private:
	T tab[N];
	int lastIndex;
public:
	CTableGType();
	CTableGType(const CTableGType<T, N>&);
	~CTableGType();
	CTableGType& operator=(const CTableGType<T, N>&);
	T operator[](int i) const;
	T& operator[](int i);
	int getSize();
	void pushElement(T i);
	T popElement();
};

template<class T, int N> CTableGType<T, N>::CTableGType(){ lastIndex=-1;}

template <class T, int N>CTableGType<T, N>::CTableGType(const CTableGType<T, N>& ct):
	lastIndex(ct.lastIndex)
{
	for(int i=0 ; i<=lastIndex ; i++)
		tab[i]=ct[i];
}


template<class T, int N> T CTableGType<T, N>::operator[](int i) const{
	if(i<0) throw -1;
	if(i>lastIndex) throw -2;
	return tab[i];
}

template<class T, int N> T& CTableGType<T, N>::operator[](int i){
	if(i<0) throw -1;
	if(i>lastIndex) throw -2;
	return tab[i];
}

template<class T, int N> CTableGType<T, N>& CTableGType<T, N>::operator=(const CTableGType<T, N>& ct){
	lastIndex=ct.lastIndex;
	for(int i=0 ; i<=lastIndex ; i++)
		tab[i]=ct[i];

	return *this;
}

template<class T, int N> int CTableGType<T, N>::getSize(){
	return lastIndex+1;
}

template<class T, int N> void CTableGType<T, N>::pushElement(T i){
	tab[++lastIndex]=i;
}

template<class T, int N> T CTableGType<T, N>::popElement(){
	return tab[lastIndex--];
}

template<class T, int N> CTableGType<T, N>::~CTableGType(){}

#endif
