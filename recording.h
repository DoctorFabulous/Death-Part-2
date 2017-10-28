#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>

class Recording
{
	public:
	Recording(const string& aTitle, const string& anArtist, const string& aProducer, const int aYear , const int anID);
	~Recording(void);
	int getRecordingID();
	string toString() const;
	
	private:
	string title;
	string artist;
	int year;
	string producer;
	int recordingID;
};

ostream& operator<<(ostream& out, const Recording& aRecording);
#endif