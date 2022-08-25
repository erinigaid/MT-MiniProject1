#include "VehicleControl.h"

/*************************************************************************************************************************
/*	Function Name : VehicleEngine.

/*	Function Info : This function sets the state of the Engine
					based on user input whether it's on or off.

/*	Function Input: This function takes the following parameters:

											VehiclePtr  : the address of the instance of the struct.
											EngineChoice: user input choice for the engine state.
*************************************************************************************************************************/

VEHICLE_t VehicleEngine(VEHICLE_t *VehiclePtr,uint8 EngineChoice)
{
	switch(EngineChoice)
	{
		case ON:
			printf("Engine is ON.\n");
			VehiclePtr->EngineState = ON;
		break;

		case OFF:
			printf("Engine is OFF.\n");
			VehiclePtr->EngineState = OFF;
		break;

		default:
			printf("Wrong Entry try again.\n");
		break;
	}

	printf("\n===============================================================================\n");
}


/*************************************************************************************************************************
/*	Function Name : SensorSetMenu.

/*	Function Info : This function sets the different sensors of the Vehicle
					based on user input it can be the EngineState, TrafficLight, RoomTemp, EngineTemp.

/*	Function Input: This function takes the following parameters:

											VehiclePtr  : the address of the instance of the struct.
											SensorChoice: user input choice for the targeted sensor.
*************************************************************************************************************************/

VEHICLE_t SensorSetMenu(VEHICLE_t *VehiclePtr,uint8 SensorChoice)
{
	uint8 color;
	float32 Rtemp, Etemp;
	switch(SensorChoice)
	{
		case 'a':
			printf("Engine is OFF.\n");
			VehiclePtr->EngineState = OFF;
		break;

		case 'b':
			printf("Enter the required color: \n");
			fflush(stdout);
			scanf(" %c",&color);
			TrafficLight(VehiclePtr,color);
		break;

		case 'c':
			printf("Enter the required room temp: \n");
			fflush(stdout);
			scanf("%f",&Rtemp);
			RoomTemp(VehiclePtr,Rtemp);
		break;

		case 'd':
			printf("Enter the required engine temp: \n");
			fflush(stdout);
			scanf("%f",&Etemp);
			EngineTemp(VehiclePtr,Etemp);
		break;
		default:
			printf("Wrong Entry try again.\n");
		break;
	}
	printf("\n===============================================================================\n");
}



/*************************************************************************************************************************
/*	Function Name : TrafficLight.

/*	Function Info : This function sets speed of the vehicle based on the tarffic light sensor
					which is a user input it can be (G,g), (O,o), (R,r).

/*	Function Input: This function takes the following parameters:

											VehiclePtr  : the address of the instance of the struct.
											TrafficData	: user input for the traffic light color.
*************************************************************************************************************************/

VEHICLE_t TrafficLight(VEHICLE_t *VehiclePtr,uint8 TrafficData)
{
	switch(TrafficData){
		case 'G':
		case 'g':
			VehiclePtr->VehicleSpeed = 100;
		break;

		case 'O':
		case 'o':
			VehiclePtr->VehicleSpeed = 30;
		break;

		case 'R':
		case 'r':
			VehiclePtr->VehicleSpeed = 0;
		break;

		default:
		printf("Wrong Entry.\n");
		break;
	}
	printf("\n===============================================================================\n");
	DisplayState(VehiclePtr);
	printf("\n===============================================================================\n");
}


/*************************************************************************************************************************
/*	Function Name : RoomTemp.

/*	Function Info : This function sets AC state and the room temp of the vehicle based
					on the room temp sensor which is a user input.

/*	Function Input: This function takes the following parameters:

											VehiclePtr  : the address of the instance of the struct.
											RoomTempData: user input for the temp of the room.
*************************************************************************************************************************/

VEHICLE_t RoomTemp(VEHICLE_t *VehiclePtr,float32 RoomTempData)
{
	if(10 > VehiclePtr->RoomTempData || 30 < VehiclePtr->RoomTempData)
	{
		VehiclePtr->ACState = ON;
		VehiclePtr->RoomTempData = 20;
	}

	else
	{
		VehiclePtr->ACState = OFF;
	}
	printf("\n===============================================================================\n");
	DisplayState(VehiclePtr);
	printf("\n===============================================================================\n");
}



/*************************************************************************************************************************
/*	Function Name : EngineTemp.

/*	Function Info : This function sets Engine Temperature Controller state and the temp of the Engine based
					on the engine temp sensor which is a user input.

/*	Function Input: This function takes the following parameters:

											VehiclePtr 	  : the address of the instance of the struct.
											EngineTempData: user input for the temp of the engine.
*************************************************************************************************************************/

VEHICLE_t EngineTemp(VEHICLE_t *VehiclePtr,float32 EngineTempData)
{
	if((100 > EngineTempData) || (150 < EngineTempData))
	{
		VehiclePtr->EngineTempState = ON;
		VehiclePtr->EngineTemp = 125;
	}

	else
	{
		VehiclePtr->EngineTempState = OFF;
	}
	printf("\n===============================================================================\n");
	DisplayState(VehiclePtr);
	printf("\n===============================================================================\n");
}


/*************************************************************************************************************************
/*	Function Name : DisplayState.

/*	Function Info : This function displays the current vehicle state

/*	Function Input: This function takes the following parameters:

											VehiclePtr  : the address of the instance of the struct.
*************************************************************************************************************************/

VEHICLE_t DisplayState(VEHICLE_t *VehiclePtr)
{

	if(30 == VehiclePtr->VehicleSpeed)
	{
		VehiclePtr->ACState = ON;
		VehiclePtr->RoomTempData = VehiclePtr->RoomTempData * 1.25 + 1;
		VehiclePtr->EngineTempState = ON;
		VehiclePtr->EngineTemp = VehiclePtr->EngineTemp * 1.25 + 1;
	}

	if(VehiclePtr->EngineState == ON)
		printf("Engine State: ON\n");
	else
		printf("Engine State: OFF\n");

	if(VehiclePtr->ACState == ON)
		printf("AC: ON\n");
	else
		printf("AC: OFF\n");



	printf("Vehicle Speed: %d Km/h\n",VehiclePtr->VehicleSpeed);

	printf("Room Temperature: %0.2f C\n",VehiclePtr->RoomTempData);

	if(VehiclePtr->EngineTempState == ON)
		printf("Engine Temperature Controller State: ON\n");
	else
		printf("Engine Temperature Controller State: OFF\n");

	printf("Engine Temperature: %0.2f C\n",VehiclePtr->EngineTemp);
}
