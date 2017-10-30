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
	cout << "Starting to add the track" << endl;
	tracksInPlaylist.push_back(&aTrack);
	cout << "Some garbage" << endl;
}

string Playlist::getPlaylistName()
{
	return playlistName;
}

string* Playlist::getContents()
{
	string* output;
	(*output) = "";
	for (int i = 0; i < songsInPlaylist.size(); i++)
	{
		(*output).append((songsInPlaylist[i])->toString());
		(*output).append("\n");
	}
	return output;
}

string Playlist::toString() const
{
	return "Playlist: " + playlistName;
}