#ifndef _TRACKS_H
#define _TRACKS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "track.h"

class Tracks {
	/*
	Tracks represents a collection of compositions, specifically Tracks objects.
	A Tracks container OWNS the tracks within it.
	If the container is destroyed it deletes the Track objects it contains
	If a Track is removed from the container the Track object is deleted from heap space.
	*/
	public:
	Tracks(); 
	~Tracks(void);
	Track * findBySongID(int anID);
	void add(Track& aTrack);
	void remove(Track& aTrack);
	//void showOn(UI& aView) const;
	void printOn(ostream& out) const;
	
	private:
	vector<Track*> collection;
	vector<Track*>::iterator findPosition(Track& aTrack);
};

ostream& operator<<(ostream& out, const Tracks& tracks);
#endif