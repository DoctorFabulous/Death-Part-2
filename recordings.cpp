#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "recordings.h"

Recordings::Recordings()
{
	cout << "CREATING RECORDINGS." << endl;
}

Recordings::~Recordings(void)
{
	cout << "DELETING RECORDINGS." << endl;
	for (vector<Recording*>::size_type i = 0; i < collection.size(); i++)
	{
		delete collection[i];
	}
}

vector<Recording*>::iterator Recordings::findPosition(Recording& aRecording)
{
	for (vector<Recording*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		if (*it == &aRecording)
		{
			return it;
		}
	}
	
	return collection.end();
}

Recording* Recordings::findByID(int anID)
{
	for (vector<Recording*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		if ((*it) -> getRecordingID() == anID)
		{
			return *it;
		}
	}
	
	if ((*collection.end()) -> getRecordingID() == anID)
	{
		return *collection.end();
	}
	
	return NULL;
}

void Recordings::add(Recording& aRecording)
{
	collection.push_back(&aRecording);
}

void Recordings::remove(Recording& aRecording)
{
	vector<Recording*>::iterator index = findPosition(aRecording);
	if(index != collection.end()) 
	{
		Recording* tRecording = *index;
		collection.erase(index);
		delete tRecording; //free the memory of theSong
	}
}

/*void Recordings::showOn(UI & view) const 
{
  view.printOutput("RECORDING:");
  for (int i=0; i<collection.size(); i++)
  {
	view.printOutput((*collection[i]).toString());	  
  }
}*/


void Recordings::printOn(ostream& out) const
{
	cout << "RECORDINGS:" << endl;
	for (vector<Recording*>::size_type i = 0; i < collection.size(); i++)
	{
		cout << (*collection[i]).toString() << endl;
	}
}



