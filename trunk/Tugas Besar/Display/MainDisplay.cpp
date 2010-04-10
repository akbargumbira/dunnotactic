#include "Display.h"

int main() {

	Display d;
        string Info[9];
        try{
//	d.displayBoxTurn(1);
//	d.displayBoxTurnWithName("Mukhammad Ifanto");
//	d.setArea(5,5,4);
//	d.displayBoxMap(9,9);
            system("clear");
        d.MoveAnimated(5,5,5,2);
//            d.SelectGrid(1,1);
	cout << endl << endl;
	
        }
        catch (const char* e)
        {
            cout << e << endl;

        }
	return 0;
}
