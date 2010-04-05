#include "Display.h"

int main() {

	Display d;
        string Info[9];
        try{
	d.displayBoxTurn(1);
	d.displayBoxTurnWithName("Mukhammad Ifanto");
	d.setArea(5,5,4);
	d.displayBoxMap(9,9);
	cout << endl << endl;
        Info[0]="Ifan ganteng";
        Info[1]="banget";
	d.displayBoxInfo(Info);
        }
        catch (const char* e)
        {
            cout << e << endl;

        }
	return 0;
}
