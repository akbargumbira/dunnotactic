//File: Mage.h
//Deklarasi kelas Mage yang diturunkan dari kelas Job

#ifndef Mage_H
#define Mage_H

#include "Job.h"

class Mage : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Mage();	
	Mage(const string&);
	Mage(const Mage&);	
	~Mage();
	void Special (Job &Target);
};

#endif
