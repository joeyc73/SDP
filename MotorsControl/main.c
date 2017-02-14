#include <stdio.h>
#include "MotorsControl.h"

int main(void){


	if (MotorsInit()){
		printf("ERROR: Could not Init Motors\n");
		return 1;
	}

   return 0;
}
