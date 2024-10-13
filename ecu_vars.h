// ecu_variables.h
// Header file for ECU Variable Declarations

#ifndef ECU_VARIABLES_H
#define ECU_VARIABLES_H

#include <stdint.h>
#include <stdbool.h>

// Engine Parameters
extern volatile uint16_t engineRPM;
extern volatile float engineLoad;
extern volatile float coolantTemp;
extern volatile float intakeAirTemp;
extern volatile float manifoldAbsolutePressure;
extern volatile float massAirFlow;
extern volatile uint16_t throttlePosition;
extern volatile float boostPressure;

// Fuel System
#define NUM_INJECTORS 4
extern volatile uint16_t injectorPulseWidth[NUM_INJECTORS];
extern volatile float fuelPressure;

// Ignition System
extern volatile float ignitionTiming;
extern volatile bool ignitionCoilStatus[4];

// Sensors
extern volatile float oxygenSensorBank1;
extern volatile float oxygenSensorBank2;
extern volatile bool knockDetected;
extern volatile uint16_t crankPosition;
extern volatile uint16_t camPosition;
extern volatile float vehicleSpeed;

// Actuators
extern volatile uint16_t idleAirControl;
extern volatile uint16_t wastegatePosition;
extern volatile uint16_t egrValveControl;

// Control Variables
extern const float targetAFR;
extern volatile float currentAFR;
extern volatile bool isEngineRunning;
extern volatile bool isTurboActive;
extern volatile bool errorFlag;

// Timing Variables
extern volatile uint32_t cycleTime;

// Miscellaneous
#define MAX_DTC 32
extern volatile uint16_t diagnosticCodes[MAX_DTC];
extern volatile uint8_t dtcCount;

#endif // ECU_VARIABLES_H
