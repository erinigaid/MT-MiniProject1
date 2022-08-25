#include "Program.h"
uint8 EngineIterator, SensorIterator;

VEHICLE_t Vehicle1;

void program(void)
{
	while(TRUE){
		Label:
		printf("a. Turn on the vehicle engine.\n");
		printf("b. Turn off the vehicle engine.\n");
		printf("c. Quit the system.\n");
		printf("-----> ");
		fflush(stdout);
		scanf(" %c", &EngineIterator);


		switch(EngineIterator)
		{
			case 'a':
				EngineIterator = ON;
			break;

			case 'b':
				EngineIterator = OFF;
			break;

			case 'c':
				exit(0);
			break;
		}

		VehicleEngine(&Vehicle1,EngineIterator);

		while(ON == EngineIterator)
		{
			printf("a. Turn off the engine.\n");
			printf("b. Set the traffic light color.\n");
			printf("c. Set the room temperature.\n");
			printf("d. Set the engine temperature.\n");
			printf("-----> ");
			fflush(stdout);
			scanf(" %c",&SensorIterator);

			SensorSetMenu(&Vehicle1,SensorIterator);

			if('a' == SensorIterator)
			{
				goto Label;
			}


		}
	}


}
