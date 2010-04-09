#ifndef _Job_H
#define _Job_H

#include <iostream>
#include <string>
//Job, merupakan penambahan attribut untuk suatu Job yang dipilih
using namespace std;
class Job {
protected :
 
    int     ID;	//ID untuk objek
    string  Name; //Nama objek (User yang memberi)
	string 	JobName; //Job Name objek
	string 	RaceName; //RAce Name  objek
	bool	Death; //Status objek untuk mati (jika darah habis (0) ) - true jika mati
	bool 	AttackTurn;	//Status Objek untuk Attack - true jika telah melakukan serangan
	bool	Enable; //True jika turn dia habis
	bool	MoveTurn; //Status Objek untuk Move - true jika telah melakukan move
      
    //attribut
    int     AttackPoint; //Attribut nilai serangan
    int     Defense; //Attribut nilai pertahanan
    int     Acc; //Attribut nilai ketepatan dalam menyerang
    int     Evade; //Attribut nilai dalam menghindar
    float   SpecialBonus; //Attribut nilai tambahan dalam melakukan serangan special 
    int     RangeMove; //Attribut nilai daerah yang bisa dilalui move
    int     RangeAttack; //Attribut nilai daerah yang bisa diserang
      
    int     HP;	//Attribut nilai kehidupan (jika HP = 0 maka karakter mati, Death = true)
    int     SP;	//Attribut nilai simpanan untuk melakukan serangan special (jika SP <= cost yang diperlukan untuk melakukan serangan suatu special, Special tidak dapat dilakukan)
	string 	SpecialArray[10]; //Attribut List special yang dimiliki
	
	//Attribut Default
    int		HPDefault; //Attribut HPMax
	int		SPDefault; //Attribut SPMax
	int 	AttackPointDefault;	//Attribut Attack original
	int 	AccDefault; //Attruibut Acc Default
	int		RangeAttackDefault;	//Attribut Ranget Attack Original
    
	//Kordinat karakter
    int       X;				//Posisi Karakter dalam garis X
    int       Y; 				//Posisi Karakter dalam garis Y
 
 public :
    //METHOD
    //Constructor dan destructor
    Job (); //Constructor Default
	
	Job (const string&);	
	//Construstor dengan parameter string
	//I.S : Karakter belum diinstansi
	//F.S : Karakter telah diinstansi dengan race string	  

	//Destructor virtual  
	virtual ~Job ();
      
    //Attribute
	int GetID(); //Mengembalikan ID
	string GetName(); //mengembalikan nilai Name Karakter
	string GetJobName(); //mengembalikan nilai JobName Karakter
	string GetRaceName(); //mengembalikan nilai RaceName Karakter
    int GetAttackPoint (); //mengembalikan nilai attack_point
    int GetDefensePoint (); //mengembalikan nilai defense_point
    int GetAcc (); //mengembalikan nilai acc
    int GetEvade (); //mengembalikan nilai evade
    float GetSpecialBonus (); //mengembalikan nilai spsial_bonus
    int GetRangeMove (); //mengembalikan nilai range_move
    int GetRangeAttack(); //mengembalikan nilai range_attack
    int GetHP(); //mengembalikan nilai HP
    int GetSP(); //mengembalikan nilai SP
	int GetHPDefault(); //mengembalikan nilai HPDefault
	int GetSPDefault();	//mengembalikan nilai SPDefault
	
	void GetSpecialArray(); //mengembalikan isi list SpesialArray
	void SetID(const int &); //Mengeset ID
	void SetName(const string&); //Mengeset Name
	void SetDeath(bool &); //Mengeset status death
	void SetAttackTurn (bool &); //Mengeset status  Attack
	void SetEnable (bool &); //Mengeset status  enable
	void SetMoveTurn (bool &); //Mengeset status Move
	bool GetDeath(); //Mengembalikan status Death
	bool GetAttackTurn(); //Mengembalikan status Attack
	bool GetEnable(); //Mengembalikan status Enable
	bool GetMoveTurn(); //Mengembalikan status Turn
	  
	//Method Lain
	void Status(); //Mengembalikan status Status Semuanya
      
    //Posisi
	void SetXY (const int &, const int &); //Mengeset nilai x, y
    int GetX (); //mengembalikan nilai X
    int GetY (); //mengembalikan nilai Y
	  
    //Method Karakter
	void Move (const int &, const int &); 	 
	//I.S : Posisi suatu karakter original
	//F.S : Posisi suatu karakter berubah menjadi x, y
	  
	void Wait ();
	//Fungsi Wait
	//I.S : Fungsi masih dalam keadaan Enable = true
	//F.S : Enable = false
	  
	void Attack (Job &Target);
	//Fungsi menyerang karakter lain
	//I.S : Target.HP masih yang lama
	//F.S : Target.HP telah dikurangi Attack this
	  
    void ReceiveAttack (const int& );
	//Fungsi menerima serangan
	//I.S : HP masih yang lama
	//F.S : HP telah berkurang sesuai Attack
	  
    void ReceiveHP (const int& );
	//Fungsi menerima HP
	//I.S : HP masih yang lama
	//F.S : HP telah Bertambah sesuai dengan spesial
	  
	virtual void SpecialArea (const int & SPC);
	//Fungsi serangan tambahan
	//I.S : ~~
	//F.S : Target.HP dalam suatu area berkurang (jika spesial heal, maka Target.HP bertambah)
	  
	virtual void Special (const int & SPC, Job &Target);
	//Fungsi serangan tambahan
	//I.S : ~~
	//F.S : Target.HP berkurang
};      
      
#endif
