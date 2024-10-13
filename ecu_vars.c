// ecu_variables.c
// ECU Variable Definitions

#include "ecu_vars.h"

// Engine Parameters
volatile uint16_t engineRPM = 0;
volatile float engineLoad = 0.0f;
volatile float coolantTemp = 0.0f;
volatile float intakeAirTemp = 0.0f;
volatile float manifoldAbsolutePressure = 0.0f;
volatile float massAirFlow = 0.0f;
volatile uint16_t throttlePosition = 0;
volatile float boostPressure = 0.0f;

// Fuel System
volatile uint16_t injectorPulseWidth[NUM_INJECTORS] = {0};
volatile float fuelPressure = 0.0f;

// Ignition System
volatile float ignitionTiming = 0.0f;
volatile bool ignitionCoilStatus[4] = {false, false, false, false};

// Sensors
volatile float oxygenSensorBank1 = 0.0f;
volatile float oxygenSensorBank2 = 0.0f;
volatile bool knockDetected = false;
volatile uint16_t crankPosition = 0;
volatile uint16_t camPosition = 0;
volatile float vehicleSpeed = 0.0f;

// Actuators
volatile uint16_t idleAirControl = 0;
volatile uint16_t wastegatePosition = 0;
volatile uint16_t egrValveControl = 0;

// Control Variables
const float targetAFR = 14.7f;
volatile float currentAFR = 0.0f;
volatile bool isEngineRunning = false;
volatile bool isTurboActive = false;
volatile bool errorFlag = false;

// Timing Variables
volatile uint32_t cycleTime = 0;

// Miscellaneous
volatile uint16_t diagnosticCodes[MAX_DTC] = {0};
volatile uint8_t dtcCount = 0;
