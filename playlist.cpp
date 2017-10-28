#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "playlist.h"

Playlist::Playlist(const string& aPlaylistName)
{
	playlistName = aPlaylistName;
	cout << "Playlist: " << aPlaylistName << " created." << endl;
}

Playlist::~Playlist()
{
	cout << "Playlist: " << this->getPlaylistName() << " deleted." << endl;
}

void Playlist::addSong(Song& aSong)
{
	songsInPlaylist.push_back(&aSong);
}

void Playlist::addTrack(Track& aTrack)
{
	tracksInPlaylist.push_back(&aTrack);
}

string Playlist::getPlaylistName()
{
	return playlistName;
}

string Playlist::toString() const
{
	return "Playlist: " + playlistName;
}