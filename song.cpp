#include <iostream>
#include <string>
using namespace std;

#include "song.h"
	
Song::Song(const string & aTitle, const string & aComposer, const int anID){
	//cout << "Song(string&, string&, int) " << this->toString() << endl;
	title = aTitle;
	composer = aComposer;
	id = anID;
	cout << "Song: " << aTitle << " " << aComposer << " " << anID << " created." << endl; 
}
Song::~Song(void)
{
	cout << "Song: " << this->title << " deleted." << endl;
}
int Song::getID(){return id;}

string Song::toString()const {
	return to_string(id) + " " + title + " " + composer;
}

ostream & operator<<(ostream & out, const Song & aSong){
	out << aSong.toString() << endl;
	return out;
}
