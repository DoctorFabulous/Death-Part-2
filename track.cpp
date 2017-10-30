#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "track.h"

Track::Track(const int anAlbumID, const int aSongID, const int aTrackNumber)
{
	albumID = anAlbumID;
	songID = aSongID;
	trackNumber = aTrackNumber;
	mp3_file = "";
	cout << "Track: " << anAlbumID << " " << aSongID << " " << aTrackNumber << " created." << endl;
}

Track::~Track()
{
	cout << "Track: # " << this->trackNumber << " deleted." << endl;
}

int Track::getTrackNumber()
{
	return trackNumber;
}

int Track::getSongID()
{
	return songID;
}

string Track::toString() const
{
	stringstream holder;
	holder << "Track# " << trackNumber << " for song " << songID;
	return holder.str();
}

ostream& operator<<(ostream& out, const Track& aTrack)
{
	out << aTrack.toString() << endl;
	return out;
}