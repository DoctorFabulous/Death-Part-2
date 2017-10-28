#include <iostream>
#include <string>
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
	cout << "Track # " << this->trackNumber << " deleted." << endl;
}

int Track::getTrackID()
{
	return trackNumber;
}

string Track::toString() const
{
	return "track aaa"; //"Track # " + trackNumber + " for song " + songID;
}

ostream& operator<<(ostream& out, const Track& aTrack)
{
	out << aTrack.toString() << endl;
	return out;
}