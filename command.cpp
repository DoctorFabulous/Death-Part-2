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

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#include "str_util.h"
#include "command.h"
#include "songs.h"
#include "recordings.h"
#include "users.h"
#include "tracks.h"

Command::Command(string cmdStr)
{
	commandString = cmdStr;
	parse(commandString);
}

string Command::getCommandString()
{
	return commandString;
}
string Command::getCommandName(){return tokens[0];}
string Command::getToken(int i){
	   if(i >= 0 && i<tokens.size())
	      return tokens[i];
	   else
		  return "";
   
}

bool Command::isCommand(string aCommandName){
	return getCommandName().compare(aCommandName) == 0;
}

bool Command::isUICommand(){
	for(int i=0; i<NumberOfUICommands; i++)
		if(getCommandName().compare(UICommands[i]) == 0) return true;
	return false;
}
bool Command::isAppCommand(){
		for(int i=0; i<NumberOfAppCommands; i++)
		if(getCommandName().compare(AppCommands[i]) == 0) return true;
	return false;
}
bool Command::isDevCommand(){
		for(int i=0; i<NumberOfDevCommands; i++)
		if(getCommandName().compare(DevCommands[i]) == 0) return true;
	return false;
}
void Command::parse(string cmdStr)
{	
    /*
	Parse (tokenize) the command 
	
	Parse a command like:
	add -s "The Girl From Ipanema"
	into:
	add
	-s
	The Girl From Ipanema
	*/
    string buffer;
    stringstream ss(cmdStr); // Insert the string into a stringstream

	//Tokenize the command
	//collect substrings between "" quotation marks as a single token
	//and strip off the "" quotation marks.
	//This parser essentially does a trim() as well because it
	//uses a stringstream that strips off white space
	
	string tokenStr = ""; //for collecting "" quoted substring words
	bool collecting = false; //not collecting quoted words
    while (ss >> buffer){
		if((buffer.length() == 2) &&
     		(buffer[0] == '"') &&(buffer[1] == '"')){
			//word is a "" empty string
		}
		else if((buffer.length() > 2) &&
     		(buffer[0] == '"') &&
			(buffer[buffer.length()-1] == '"')){
			//single word in "" quotes -strip off the quotes
			tokens.push_back(buffer.substr(1,buffer.length()-2));	
		}
	    else if((buffer.length() == 1) && (buffer[0] == '"')) {
			//word is a single "
			//could be the starting quote or ending quote
			if(collecting == false) {
				collecting = true; //start collecting
			}
			else {
				collecting = false; //stop collecting
			    tokens.push_back(StrUtil::trim(tokenStr));
			    tokenStr = "";
			}
		}
	    else if((buffer.length() > 1) && (buffer[buffer.length()-1] == '"')) {
			//word ends with "
			tokenStr.append(" " + buffer.substr(0,buffer.length()-1));
			collecting = false;
			tokens.push_back(StrUtil::trim(tokenStr));
			tokenStr = "";
		}
		else if((buffer.length() > 1) && (buffer[0] == '"')) {
			//word starts with "
			tokenStr.append(buffer.substr(1,buffer.length()-1));
			collecting = true;
		}
		else if(collecting == true)
			//word within "" quoted substring
			   tokenStr.append(" " + buffer);
		else
			tokens.push_back(buffer);
	}

    if(tokens.size() == 0) tokens.push_back("NO COMMAND");
	
   //Command is now tokenized into tokens vector
	
   //Print parsed command tokens for now
   cout << "PARSED COMMAND:" << '\n';
   //shows use of iterator
   for (vector<string>::iterator it = tokens.begin(); it!=tokens.end(); ++it)
   {
       cout << *it << '\n';
   }
   
   // INTREPRETING THE COMAND TOKEN BY TOKEN
   // MAYBE PUT IN AN EXECUTE COMMAND METHOD THAT IS CALLED HERE INSTEAD (PUT ALL THIS IN THERE THEN)   
   /*
   int holderInt;
   int holderInt2;
   int holderInt3;
   
   if ((tokens[0]).compare("add") == 0) //Are we trying to add something ?
   {
	   if ((tokens[1]).compare("-r") == 0)
	   {
		   // Add a recording
		   stringstream holder(tokens[2]);
		   stringstream holder2(tokens[6]);
		   holder >> holderInt;
		   holder2 >> holderInt2;
		   Recording* r = new Recording(tokens[3], tokens[4], tokens[5], holderInt2, holderInt);
		   cout << "ADDING A NEW RECORDING." << endl;
		   allRecordings.add(*r);
		   //cout << o.toString() << endl;
	   }
	   else if ((tokens[1]).compare("-s") == 0)
	   {
		   // Add a song
		   stringstream holder(tokens[2]);
		   holder >> holderInt;
		   //Song* s = new Song(tokens[3], tokens[4], holderInt);
		   cout << "ADDING A NEW SONG." << endl;
		   //Song x = allSongs.add(*(new Song(tokens[3], tokens[4], holderInt)));
		   //cout << tokens[2] << "SAVE ME PLEASE" << endl;
		   //cout << x.toString() << endl;
	   }
	   else if ((tokens[1]).compare("-u") == 0)
	   {
		   //User* u = new User(tokens[3], tokens[2]);
		   allUsers.add(*(new User(tokens[3], tokens[2])));
	   }
	   else if ((tokens[1]).compare("-t") == 0)
	   {
		   stringstream holder(tokens[2]);
		   stringstream holder2(tokens[3]);
		   stringstream holder3(tokens[4]);
		   holder >> holderInt;
		   holder2 >> holderInt2;
		   holder3 >> holderInt3;
		   //Track* t = new Track(holderInt, holderInt2, holderInt3);
		   cout << "ADDING A NEW TRACK." << endl;
		   allTracks.add(*(new Track(holderInt, holderInt2, holderInt3)));
	   }
	   else if ((tokens[1]).compare("-p") == 0)
	   {
		   //Playlist* p = new Playlist(tokens[2]);
		   (*allUsers.findByID(tokens[2])).addPlaylist(*(new Playlist(tokens[2])));
	   }
	   else if ((tokens[1]).compare("-l") == 0)
	   {
		   stringstream holder(tokens[4]);
		   holder >> holderInt;
		   (*(*allUsers.findByID(tokens[2])).getPlaylist(tokens[3])).addTrack(*allTracks.findBySongID(holderInt));
	   }
	   else
	   {
		   cout << "Invalid command." << endl;
	   }
   }
   else if ((tokens[0]).compare("delete") == 0) // Are we trying to delete something ?
   {
	   
   }
   else if ((tokens[0]).compare("show") == 0) // Are we trying to display something ?
   {
	   if ((tokens[1]).compare("-r") == 0)
	   {
		   
	   }
	   else if ((tokens[1]).compare("-s") == 0)
	   {
		   
	   }
	   else if ((tokens[1]).compare("-u") == 0)
	   {
		   
	   }
	   else if ((tokens[1]).compare("-t") == 0)
	   {
		   
	   }
	   else if ((tokens[1]).compare("-p") == 0)
	   {
		   
	   }
	   else if ((tokens[1]).compare("-l") == 0)
	   {
			
	   }
	   else
	   {
		   cout << "Invalid command." << endl;
	   }
   }
   */
}

