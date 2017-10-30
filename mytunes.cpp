/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include "mytunes.h"
#include "UI.h"
#include "command.h"

MyTunes::MyTunes():view(this)
{
	allSongs = *(new Songs());
	allUsers = *(new Users());
	allRecordings = *(new Recordings());
	allTracks = *(new Tracks());
}

void MyTunes::run()
{
	//start user interface
	view.run(); 
}
void MyTunes::executeCommand(Command cmd){
    //execute application (non UI shell) commands
    //These are the commands that affect the data model or retrieve contents from the data model
	if(cmd.isCommand(CMD_ADD)) executeCMDADD(cmd);
	else if(cmd.isCommand(CMD_DELETE)) executeCMDDELETE(cmd);
	else if(cmd.isCommand(CMD_SHOW)) executeCMDSHOW(cmd);
}

//APP COMMANDS 
void MyTunes::executeCMDADD(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
	
	int holderInt;
	int holderInt2;
	int holderInt3;
   
	if (cmd.getToken(1).compare("-r") == 0)
	{
		// Add a recording
		stringstream holder(cmd.getToken(2));
		stringstream holder2(cmd.getToken(6));
		holder >> holderInt;
		holder2 >> holderInt2;
		Recording* r = new Recording(cmd.getToken(3), cmd.getToken(4), cmd.getToken(5), holderInt2, holderInt);
		cout << "ADDING A NEW RECORDING." << endl;
		allRecordings.add(*r);
	}
	else if (cmd.getToken(1).compare("-s") == 0)
	{
		// Add a song
		stringstream holder(cmd.getToken(2));
		holder >> holderInt;
		//Song* s = new Song(cmd.getToken(3), cmd.getToken(4), holderInt);
		cout << "ADDING A NEW SONG." << endl;
		/*Song x =*/ allSongs.add(*(new Song(cmd.getToken(3), cmd.getToken(4), holderInt)));
		//cout << cmd.getToken(2) << "SAVE ME PLEASE" << endl;
		//cout << x.toString() << endl;
	}
	else if ((cmd.getToken(1)).compare("-u") == 0)
	{
		//User* u = new User(cmd.getToken(3), cmd.getToken(2));
		allUsers.add(*(new User(cmd.getToken(3), cmd.getToken(2))));
	}
	else if (cmd.getToken(1).compare("-t") == 0)
	{
		stringstream holder(cmd.getToken(2));
		stringstream holder2(cmd.getToken(3));
		stringstream holder3(cmd.getToken(4));
		holder >> holderInt;
		holder2 >> holderInt2;
		holder3 >> holderInt3;
		//Track* t = new Track(holderInt, holderInt2, holderInt3);
		cout << "ADDING A NEW TRACK." << endl;
		allTracks.add(*(new Track(holderInt, holderInt2, holderInt3)));
	}
	else if (cmd.getToken(1).compare("-p") == 0)
	{
		//Playlist* p = new Playlist(cmd.getToken(2));
		(*allUsers.findByID(cmd.getToken(2))).addPlaylist(*(new Playlist(cmd.getToken(3))));
	}
	else if (cmd.getToken(1).compare("-l") == 0)
	{
		stringstream holder(cmd.getToken(4));
		holder >> holderInt;
		User* userP = allUsers.findByID(cmd.getToken(2));
		cout << "0" << endl;
		Playlist* playlistP = (*userP).getPlaylist(cmd.getToken(3));
		cout << "1" << endl;
		Track trackP = *(allTracks.findBySongID(holderInt));
		cout << "2" << endl;
		(*playlistP).addTrack(trackP);
		cout << "3" << endl;
		cout << (*playlistP)
		//
		cout << (*userP).toString() << endl;
		//(*(*allUsers.findByID(cmd.getToken(2))).getPlaylist(cmd.getToken(3))).addTrack(*allTracks.findBySongID(holderInt)); //Is there a problem with the dereferencing? (*s)
		//work on the above
	}
	else
	{
		cout << "Invalid command." << endl;
	}
}
void MyTunes::executeCMDDELETE(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
	
	int holderInt;
	int holderInt2;
	int holderInt3;
	
	if (cmd.getToken(1).compare("-r") == 0)
	{
	   
	}
	else if (cmd.getToken(1).compare("-s") == 0)
	{
	   
	}
	else if (cmd.getToken(1).compare("-u") == 0)
	{
	    
	}
	else if (cmd.getToken(1).compare("-t") == 0)
	{
 	   
	}
	else if (cmd.getToken(1).compare("-p") == 0)
	{
	    
	}
	else if (cmd.getToken(1).compare("-l") == 0)
	{
 		
	}
	else
	{
		cout << "Invalid command." << endl;
	}
}
void MyTunes::executeCMDSHOW(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
	
	if (cmd.getToken(1).compare("-r") == 0)
	{
	   allRecordings.printOn(cout);
	}
	else if (cmd.getToken(1).compare("-s") == 0)
	{
	   allSongs.printOn(cout);
	}
	else if (cmd.getToken(1).compare("-u") == 0) //1. show -u //2. show -u <userID> -p //3. show -u <userID> -p -s
	{
		if (cmd.getToken(2).compare("") == 0) //If the second token equal to "", aka it is empty...
		//The user just wants to see all users
		{
			allUsers.printOn(cout);
		}
		
		User* foundUser = allUsers.findByID(cmd.getToken(2));
		if(foundUser != NULL) //The user wants to see a specific user's playlist names
		{
			if (cmd.getToken(3).compare("-p") == 0)
			{
				if (cmd.getToken(4).compare("") == 0) //If they only want the playlist names
				{
					cout << "Displaying playlists of user: " << (*foundUser).getID() << endl;
					cout << "  " << (*foundUser).getPlaylistNames() << endl;
				}
				else if (cmd.getToken(4).compare("-s") == 0) //They want to see the songs in the playlist
				{
					//Need to go through all playlists and print their songs
					cout << "Displaying playlists of user: " << (*foundUser).getID() << endl;
					cout << (*foundUser).getPlaylistContents() << endl;
				}
				else {
					cout << "Invalid command. What about the user's playlist did you want to see? Type show -u <userID> -p -s for songs" << endl;
				}
			}
			else
			{
				cout << "Invalid command. What did you want to see in that user's profile? Type -p for playlists" << endl;
			}
		}
		else {
			cout << "Invalid command -- could not find user to display playlists" << endl;
		}
	}
	else if (cmd.getToken(1).compare("-t") == 0)
	{
 	   allTracks.printOn(cout);
	}
	else if (cmd.getToken(1).compare("-p") == 0)
	{
	    allUsers.printAllPlaylists(cout);
	}
	else if (cmd.getToken(1).compare("-l") == 0)
	{
		//What is this?
	}
	else
	{
		cout << "Invalid command." << endl;
	}
}
