#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <ostream>
#include <string>
#include <vector>
#include "song.h"
#include "track.h"

class Playlist
{
	public:
	Playlist(const string& aPlaylistName);
	~Playlist(void);
	void addSong(Song& aSong);
	void addTrack(Track& aTrack);
	string getPlaylistName();
	string toString() const;
	
	private:
	string playlistName;
	vector<Song*> songsInPlaylist;
	vector<Track*> tracksInPlaylist;
};

ostream& operator<<(ostream& out, const Playlist& aPlaylist);
#endif