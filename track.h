#ifndef _TRACK_H
#define _TRACK_H

#include <ostream>
#include <string>

class Track
{
	public: 
	Track(const int anAlbumID, const int aSongID, const int aTrackNumber);
	~Track(void);
	int getTrackNumber();
	int getSongID();
	string toString() const;
	
	private:
	int albumID;
	int songID;
	int trackNumber;
	string mp3_file;
};

ostream& operator<<(ostream& out, const Track& aTrack);
#endif