#include <string.h>
#include <iostream>
#include <stdlib.h>

#ifndef _Chaine_h
#define _Chaine_h
#include "Chaine.h"
#endif

using namespace std;

//Constructeur par defaut
Chaine::Chaine(){
    string = (char*) malloc(sizeof(char));
    strcpy(string, "");
    size = strlen(string);
}

//Constructeur à un paramètre
Chaine::Chaine(char* str){
    size = strlen(str);
    string = (char*) malloc((size+1) * sizeof(char));
    strcpy(string, str);
}

//Constructeur de recopie
Chaine::Chaine(const Chaine& obj) : size(obj.size){
    string = (char*) malloc(size * sizeof(char));
    strcpy(string, obj.string);
}

//Destructeur
Chaine::~Chaine(){
    free(string);
}

unsigned int Chaine::getSize(){
    return size;
}

char* Chaine::getString() const{
    char* str = (char*) malloc((size+1) * sizeof(char));
    strcpy(str, string);

    return str;
}

void Chaine::addString(char* str){
    char* tmp = (char*) malloc((size+1) * sizeof(char));
    strcpy(tmp, string);
    size += strlen(str);
    string = (char*) realloc(string, (size+1) + sizeof(char));
    strcpy(string, tmp);
    strcat(string, str);
    free(tmp);
}

void Chaine::replaceString(char* str){
    free(string);
    size = strlen(str);
    string = (char*) malloc((size+1) * sizeof(char));
    strcpy(string, str);
}

Chaine& Chaine::operator=(const Chaine& c){
	replaceString(c.string);
	size=c.size;
	return *this;
}
