#include <iostream>
#include <string>
using namespace std;

#include "user.h"

User::User(const string& aName, const string& aUserID)
{
	cout << "User: " << aName << " with ID " << aUserID << " created." << endl;
	name = aName;
	userID = aUserID;
}

User::~User()
{
	cout << "User: " << this->userID << " deleted." << endl;
}

string User::getID()
{
	return userID;
}

void User::addPlaylist(Playlist& aPlaylist)
{
	playlistsU.push_back(&aPlaylist);
}

Playlist* User::getPlaylist(const string& aPlaylistName)
{
	for (vector<Playlist*>::iterator it = playlistsU.begin(); it != playlistsU.end(); ++it)
	{
		if (((*it) -> getPlaylistName()).compare(aPlaylistName) == 0)
		{
			return *it;
		}
	}
	
	if (((*playlistsU.end()) -> getPlaylistName()).compare(aPlaylistName) == 0)
	{
		return *(playlistsU.end());
	}
	
	return NULL;
}

string* User::getPlaylistNames()
{
	string* output;
	(*output) = "";
	for (vector<Playlist*>::iterator it = playlistsU.begin(); it != playlistsU.end(); ++it) {
		(*output).append((*it)-> toString());
		(*output).append("\n");
	}
	return output;
}
string User::toString() const
{
	return "User: " + name + " with ID: " + userID;
}

ostream& operator<<(ostream& out, const User& aUser)
{
	out << aUser.toString() << endl;
	return out;
}