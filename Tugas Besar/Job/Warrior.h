//File: Warrior.h
//Deklarasi kelas Warrior yang diturunkan dari kelas Job

#ifndef Warrior_H
#define Warrior_H

#include "Job.h"

class Warrior : public Job {
	
	public:
	//Ctor, dctor dan cctor
	Warrior();	
	Warrior(const string&);
	Warrior(const Warrior&);	
	~Warrior();
	void SpecialArea (const int & SPC);
	void Special (const int & SPC, Job &Target);
};

#endif
