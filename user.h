#ifndef _USER_H
#define _USER_H

#include <ostream>
#include <string>
#include <vector>

#include "playlist.h"

class User 
{
	public:
	User(const string& aName, const string& aUserID);
	~User();
	string getID();
	void addPlaylist(Playlist& aPlaylist);
	Playlist* getPlaylist(const string& aPlaylistName);
	string toString() const;
	
	private:
	string name;
	string userID;
	vector <Playlist*> playlistsU;
};

ostream& operator<<(ostream& out, const User& aUser);
#endif