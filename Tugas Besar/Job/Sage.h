//File: Sage.h
//Deklarasi kelas Sage yang diturunkan dari kelas Job

#ifndef Sage_H
#define Sage_H

#include "Job.h"

class Sage : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Sage();	
	Sage(const string&);
	Sage(const Sage&);	
	~Sage();
	void Special (Job &Target);
};

#endif
