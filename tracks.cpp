#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "tracks.h"

Tracks::Tracks()
{
	cout << "CREATING TRACKS." << endl;
}

Tracks::~Tracks(void)
{
	cout << "DELETING TRACKS." << endl;
	for (vector<Track*>::size_type i = 0; i < collection.size(); i++)
	{
		delete collection[i];
	}
}

vector<Track*>::iterator Tracks::findPosition(Track& aTrack)
{
	for (vector<Track*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		if (*it == &aTrack)
		{
			return it;
		}
	}
	
	return collection.end();
}

Track* Tracks::findBySongID(int anID)
{
	for (int i = 0; i < collection.size(); i++)
	{
		if (((*collection[i]).getSongID()) == anID)
		{
			return collection[i];
		}
	}
	return NULL;
}

void Tracks::add(Track& aTrack)
{
	collection.push_back(&aTrack);
}

void Tracks::remove(Track& aTrack)
{
	vector<Track*>::iterator index = findPosition(aTrack);
	
	if (index != collection.end())
	{
		Track* tTrack = *index;
		collection.erase(index);
		delete tTrack;
	}
}

/*void Tracks::showOn(UI& view) const
{
	view.printOutput("TRACKS:");
	
	for (int i = 0; i < collection.size(); i++)
	{
		view.printOutput((*collection[i]).toString());
	}
}*/

void Tracks::printOn(ostream& out) const
{
	cout << "TRACKS:" << endl;
	
	for (vector<Tracks*>::size_type i = 0; i < collection.size(); i++)
	{
		cout << (*collection[i]).toString() << endl;
	}
}

ostream& operator<<(ostream& out, const Tracks& tracks)
{
	tracks.printOn(out);
	return out;
}

