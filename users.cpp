#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "users.h"

Users::Users()
{
	cout << "CREATING USERS." << endl;
}

Users::~Users(void)
{
	cout << "DELETING USERS" << endl;
	for (vector<User*>::size_type i = 0; i < collection.size(); i++)
	{
		delete collection[i];
	}
}

vector<User*>::iterator Users::findPosition(User& aUser)
{
	for (vector<User*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		if (*it == &aUser) 
		{
			return it;
		}
	}
	return collection.end();
}

User* Users::findByID(string anID)
{
	for (vector<User*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		if (((*it)->getID()).compare(anID) == 0)
		{
			return *it;
		}
	}
	return NULL;
}

void Users::add(User& aUser)
{
	collection.push_back(&aUser);
}

void Users::remove(User& aUser)
{
	vector<User*>::iterator index = findPosition(aUser);
	if (index != collection.end())
	{
		User* tUser = *index;
		collection.erase(index);
		delete tUser;
	}
}

void Users::printOn(ostream& out) const
{
	cout << "USERS:" << endl;
	for (vector<User*>::size_type i = 0; i < collection.size(); i++)
	{
		cout << (*collection[i]).toString() << endl;
	}
}

void Users::printAllPlaylists(ostream& out) const
{
	cout << "ALL USER PLAYLISTS:" << endl;
	for (int i = 0; i < collection.size(); i++)
	{
		cout << (*(collection[i])).toString() << endl; //Print user's name
		cout << "Playlists:" << endl; //introduce a playlist will be printed
		cout << (*(*(collection[i])).getPlaylistNames()) << endl << endl; //Print all playlists of that user
	}
}

int Users::getSize()
{
	return collection.size();
}

ostream& operator<<(ostream& out, const Users& users)
{
	users.printOn(out);
	return out;
}
