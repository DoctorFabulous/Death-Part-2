#include <iostream>
#include <string>
using namespace std;

#include "recording.h"

Recording::Recording(const string& aTitle, const string& anArtist, const string& aProducer, const int aYear , const int anID)
{
	title = aTitle;
	artist = anArtist;
	year = aYear;
	producer = aProducer;
	recordingID = anID;
	cout << "Recording: " << aTitle << " " << anArtist << " " << aYear << " " << aProducer << " " << anID << " created." << endl;
}

Recording::~Recording(void)
{
	cout << "Recording #: " << this->recordingID << " deleted." << endl;
}

int Recording::getRecordingID()
{
	return recordingID;
}

string Recording::toString() const 
{
	return "Recording: " + title + " with id " + to_string(recordingID) + " written by " + artist + " in " + to_string(year) + " & produced by " + producer;
}

ostream& operator<<(ostream& out, const Recording& aRecording)
{
	out << aRecording.toString() << endl;
	return out;
}
	