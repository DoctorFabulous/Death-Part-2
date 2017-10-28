#ifndef _RECORDINGS_H
#define _RECORDINGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "recording.h"

class Recordings
{
	public:
	Recordings();
	~Recordings(void);
	Recording* findByID(int anID);
	void add(Recording& aRecording);
	void remove(Recording& aRecording);
	//void showOn(UI& aView) const;
	void printOn(ostream& out) const;
	
	private:
	vector<Recording*> collection;
	vector<Recording*>::iterator findPosition(Recording & aRecording);
};

#endif
	