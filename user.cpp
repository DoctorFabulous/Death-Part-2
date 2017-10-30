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
	cout << endl << endl << endl << endl << endl;
}

Playlist* User::getPlaylist(const string& aPlaylistName)
{
	cout << "Starting to find a playlist" << endl;
	for (int i = 0; i < playlistsU.size(); i++)
	{
		if ((playlistsU[i]->getPlaylistName()).compare(aPlaylistName) == 0)
		{
			return playlistsU[i];
		}
	}
	cout << "Done for loop" << endl;
	/*
	if (((*playlistsU.end()) -> getPlaylistName()).compare(aPlaylistName) == 0)
	{
		return *(playlistsU.end());
	}
	cout << "Done if" << endl;
	*/
	return NULL;
}

string* User::getPlaylistNames()
{
	string* output;
	(*output) = "";
	for (int i = 0; i < playlistsU.size(); i++)
	{
		(*output).append(playlistsU[i]->toString());
		(*output).append("\n");
	}
	return output;
}

string* User::getPlaylistContents()
{
	
	string* output;
	(*output) = "";
	for (int i = 0; i < playlistsU.size(); i++)
	{
		(*output).append((playlistsU[i])-> toString());
		output->append("\n");
		(*output).append(*(playlistsU[i])-> getContents());
		output->append("\n");
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