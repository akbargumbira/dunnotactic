//File: Sage.cpp
//Implementasi kelas Sage

#include <vector>

#include "Sage.h"
#include "../DunnoTactic.h"

Sage::Sage(){}

Sage::Sage(const string& RaceName) : Job(RaceName){

	Name 	   			= "";
	JobName	   			= "Sage";
	AttackPoint			= int(AttackPoint*0.5);
	Defense    			= int(Defense*1);
	Acc	       			= int(Acc*1);
	Evade      			= int(Evade*0.8);
	RangeMove  			-= 0;
	RangeAttack			+= 2;
	HP         			= int(HP*0.8);
	SPDefault       		= int(SPDefault*1.8);
	HPDefault  			= HP;
	SP  			= 0;
	AccDefault 			= Acc;
	AttackPointDefault 	= AttackPoint;
	RangeAttackDefault 	= RangeAttack;	
	SpecialArray[0] 	= "1.Heal                  30 \n  Description : Menambah HP teman sebanyak 300";
	SpecialArray[1] 	= "2.Circle Heal           50 \n  Description : Menambah HP teman dalam area sebanyak 300";
}

Sage::Sage(const Sage& k){
	
	Name 				= k.Name;
	AttackPoint 		= k.AttackPoint;
	Defense 			= k.Defense;
	RangeMove 			= k.RangeMove;
	RangeAttack 		= k.RangeAttack;
	HP 					= k.HP;
	SP 					= k.SP;
	Acc 				= k.Acc;
	Evade	    		= k.Evade;
	HPDefault   		= k.HP;
	SPDefault   		= k.SP;
	AttackPointDefault 	= k.AttackPointDefault;
	RangeAttackDefault 	= k.RangeAttackDefault;	
	AccDefault 			= Acc;
	SpecialArray[0] 	= k.SpecialArray[0];
	SpecialArray[1] 	= k.SpecialArray[1];
	AttackTurn 			= k.AttackTurn;
	Enable  			= k.Enable;
	MoveTurn   			= k.MoveTurn;
	Death	   			= k.Death;	
}

Sage::~Sage(){
}

void Sage::SpecialArea (const int & SPC){
	if (SPC == 2) {
            if (SP>=50) {
                int range;
                vector<int> ID_array;
                if (ID > 100 && ID<=500) {
                    for (int i=0;i<DunnoTactic::P1.size();++i) {
                        range = abs(DunnoTactic::P1[i]->GetX()-X) + abs(DunnoTactic::P1[i]->GetY()-Y);
                        if (range<=RangeAttack) {
                            ID_array.push_back(DunnoTactic::P1[i]->GetID());
                            DunnoTactic::P1[i]->ReceiveHP(int(300*SpecialBonus));
                        }
                    }
                }
                else {
                    for (int i=0;i<DunnoTactic::P2.size();++i) {
                        range = abs(DunnoTactic::P2[i]->GetX()-X) + abs(DunnoTactic::P2[i]->GetY()-Y);
                        if (range<=RangeAttack) {
                            ID_array.push_back(ID);
                            DunnoTactic::P2[i]->ReceiveHP(int(300*SpecialBonus));
                        }
                    }
                }
                SP -= 50;
                AttackTurn = true;
                string s;
                string s1;
                s = "Teman dengan ID ";
                for (int i=0;i<ID_array.size();++i) {
                    s+=DunnoTactic::ToString(ID_array[i]);
                    s+=" ";
                }
                s1 ="telah di tambah Hp-nya sebesar "+DunnoTactic::ToString(300*SpecialBonus)+".";
                DunnoTactic::D.SetInfo(s, 0);
                DunnoTactic::D.SetInfo(s1,1);
                DunnoTactic::D.SetInfo("", 2);

            }
            else {
                throw "SP tidak mencukupi.";
            }
        }
}


void Sage::Special (const int & SPC, Job &Target){
	if (AttackTurn == false) {
		if (SPC == 1) {
			if (SP>=20) {
                            Target.ReceiveHP(int (300*SpecialBonus));
                            SP	-= 20;
                            AttackTurn = true;
                            DunnoTactic::D.SetInfo("Teman dengan ID "+DunnoTactic::ToString(Target.GetID()), 0);
                            DunnoTactic::D.SetInfo("telah ditambah HPnya sebesar "+DunnoTactic::ToString(300*SpecialBonus)+".",1);
                            DunnoTactic::D.SetInfo("", 2);
                        }
			else {
                            throw "SP tidak mencukupi.";
			}
		} else if (SPC ==2 ) {
                    SpecialArea(SPC);
                } else {
                    throw "Tidak ada Skill yang dimaksud!.";
		}
                DunnoTactic::D.displayGame();
	}
}


