#ifndef VEHICLECONTROL_H
#define VEHICLECONTROL_H

/* Linking Section */

#include <stdlib.h>
#include <stdio.h>
#include "STD_TYPES.h"

/* User Defined Data Types */

typedef enum{
	ON=1,
	OFF
}boolean;

typedef struct{
	boolean EngineState;
	boolean ACState;
	uint8 VehicleSpeed;
	float32 RoomTempData;
	boolean EngineTempState;
	float32 EngineTemp;

}VEHICLE_t;



/* Functions Declaration Section */
VEHICLE_t VehicleEngine(VEHICLE_t *VehiclePtr,uint8 EngineChoice);
VEHICLE_t TrafficLight(VEHICLE_t *VehiclePtr,uint8 TrafficData);
VEHICLE_t RoomTemp(VEHICLE_t *VehiclePtr,float32 RoomTempData);
VEHICLE_t EngineTemp(VEHICLE_t *VehiclePtr,float32 EngineTempData);
VEHICLE_t SensorSetMenu(VEHICLE_t *VehiclePtr,uint8 SensorChoice);
VEHICLE_t SpeedCheck(VEHICLE_t *VehiclePtr);
VEHICLE_t DisplayState(VEHICLE_t *VehiclePtr);

#endif
