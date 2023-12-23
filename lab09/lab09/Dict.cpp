#include "Dict.hpp"

void Translate::addWord(Dictionary * d, char* word, int &size) {
	d[1].engl = 1;
	*d->engl = word[0];
	*d->rus = word[1];
	
}