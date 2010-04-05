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
	void Special (const string & STR, Job &Target);
};

#endif
