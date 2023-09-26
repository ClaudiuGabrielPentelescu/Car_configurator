#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "meniu.h"

using namespace std;


int main()
{
    do
    {
        switch(selectare_optiune())
        {
            case 1: someInfo(1); break;
            case 2: someInfo(2); break;
            case 3: someInfo(3); break;
            case 4: someInfo(4); break;
            case 5: someInfo(5); break;
            case 6: someInfo(6); exit(0);

        }
    }while(1);
    return 0;
}
