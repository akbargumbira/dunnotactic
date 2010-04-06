#ifndef display_H
#define display_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Display {
	public:
		// constructor
		Display();
		// copy constructor
		Display(const Display&);
		// operator assignment
		Display& operator= (const Display&);
		// destructor
		~Display();
		
		// method
		// menampilkan BOX TURN ke layar
		void displayBoxTurn(int);
		void displayBoxTurnWithName(string);
		void displayBoxMap(int P, int L); // P = X, L = Y
		void displayBoxInfo(string* Info);
		void setArea(int, int, int);
		void MoveAnimated(int, int, int, int);
                void SelectGrid(int x, int y);
		
	private:
		// data member
		int MapPlayer[30][30];
		int MapArea[30][30];
		
		// private method
		// mencari nilai minimum antara 2 nilai
		int Min2(int, int);
		// mencari nilai yang paling kecil di sekitar koordinat
		int MinAround(int, int);
		// mengembalikan apakah petak x,y dapat di tembus
		bool PassTerrain(int, int);
		bool PassPlayer(int, int, int, int);
		bool IsTree(int, int);
		bool IsWater(int,int);
		bool IsLumpur(int, int);
		int IdPlayer(int, int);
		bool IsFriend(int, int, int, int);
		
		
};

#endif
