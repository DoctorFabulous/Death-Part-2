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

string* Playlist::getSongs()
{
	string* output = new string("");
	(*output) = "";
	if (songsInPlaylist.size() == 0) {
		(*output).append("There are no songs in that playlist");
		(*output).append("\n");
		return output;
	}
	for (int i = 0; i < songsInPlaylist.size(); i++)
	{
		(*output).append((songsInPlaylist[i])->toString());
		(*output).append("\n");
	}
	return output;
}

string* Playlist::getTracks()
{
	string* output = new string("");
	(*output) = "";
	cout << endl << endl << tracksInPlaylist.size() << endl;
	if (tracksInPlaylist.size() == 0) {
		(*output).append("There are no tracks in that playlist");
		(*output).append("\n");
		return output;
	}
	
	for (int i = 0; i < tracksInPlaylist.size(); i++)
	{
		(*output).append((tracksInPlaylist[i])->toString());
		(*output).append("\n");
	}
	cout << (*output);
	return output;
}

string Playlist::toString() const
{
	return "Playlist: " + playlistName;
}