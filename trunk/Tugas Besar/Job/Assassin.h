//File: Assassin.h
//Deklarasi kelas Assassin yang diturunkan dari kelas Job

#ifndef Assassin_H
#define Assassin_H

#include "Job.h"

class Assassin : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Assassin();	
	Assassin(const string&);
	Assassin(const Assassin&);	
	~Assassin();
	void Special (Job &Target);
};

#endif
