//File: Knight.h
//Deklarasi kelas Knight yang diturunkan dari kelas Job

#ifndef ARCHER_H
#define ARCHER_H

#include "Job.h"

class Archer : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Archer();	
	Archer(const string&);
	Archer(const Archer&);	
	~Archer();
	void SpecialArea (const int & SPC);
	void Special (const int & SPC, Job &Target);
	
};

#endif
