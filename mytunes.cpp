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
using namespace std;
#include "mytunes.h"
#include "UI.h"
#include "command.h"

MyTunes::MyTunes():view(this)
{
	/*view.printOutput("Creating mytunes.");
	allSongs = new Songs();
	Users* allUsers = new Users();
	Recordings*	allRecordings = new Recordings();
	Tracks* allTracks = new Tracks();*/
}

void MyTunes::run()
{
	//start user interface
	view.run(); 

}
void MyTunes::executeCommand(Command cmd){

    //execute application (non UI shell) commands
    //These are the commands that affect the data model
    //or retrieve contents from the data model
	if(cmd.isCommand(CMD_ADD)) executeCMDADD(cmd);
	else if(cmd.isCommand(CMD_DELETE)) executeCMDDELETE(cmd);
	else if(cmd.isCommand(CMD_SHOW)) executeCMDSHOW(cmd);
}

//APP COMMANDS
void MyTunes::executeCMDADD(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
	//view.printOutput("SAVE ME");
}
void MyTunes::executeCMDDELETE(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
}
void MyTunes::executeCMDSHOW(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());
}




