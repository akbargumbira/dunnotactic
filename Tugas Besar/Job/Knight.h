//File: Knight.h
//Deklarasi kelas Knight yang diturunkan dari kelas Job

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Job.h"

class Knight : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Knight();	
	Knight(const string&);
	Knight(const Knight&);	
	~Knight();
	void SpecialArea (const int & SPC);
	void Special (const int & SPC, Job &Target);
	
};

#endif

