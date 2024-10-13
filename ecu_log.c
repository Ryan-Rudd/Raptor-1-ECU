// ecu_log.c
// ECU Logging Functionality

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "ecu_vars.h"

// Function to simulate delay (replace with accurate delay for your platform)
void delay_ms(uint32_t ms) {
    // Implement a millisecond delay based on your hardware
    // For example, using a busy-wait loop or a hardware timer
    // This is a placeholder
    volatile uint32_t count;
    while (ms--)
        for (count = 0; count < 8000; count++);
}

// Function to print the table header
void print_table_header() {
    printf("\n+-------+------------+-------------+-------------+------------------+---------+---------+---------+\n");
    printf("| RPM   | Load(%%)    | Coolant(C)  | Intake(C)   | MAP(kPa)         | MAF(g/s)| Throttle| Boost(kPa)|\n");
    printf("+-------+------------+-------------+-------------+------------------+---------+---------+---------+\n");
}

// Function to print the table row with current variable values
void print_table_row() {
    printf("| %-5u | %-10.2f | %-11.2f | %-11.2f | %-16.2f | %-7.2f | %-7u | %-9.2f |\n",
           engineRPM,
           engineLoad,
           coolantTemp,
           intakeAirTemp,
           manifoldAbsolutePressure,
           massAirFlow,
           throttlePosition,
           boostPressure);
}

// Function to print additional variables
void print_additional_info() {
    printf("\n+----------------+---------------+----------------+----------------+---------------+\n");
    printf("| Fuel Pressure  | Ignition Timing| Current AFR    | Engine Running | Turbo Active  |\n");
    printf("+----------------+---------------+----------------+----------------+---------------+\n");
    printf("| %-14.2f | %-13.2f | %-14.2f | %-14s | %-13s |\n",
           fuelPressure,
           ignitionTiming,
           currentAFR,
           isEngineRunning ? "Yes" : "No",
           isTurboActive ? "Yes" : "No");
    
    printf("\n+---------------+-----------------+----------------+-----------------+-----------------+\n");
    printf("| Knock Detected| Vehicle Speed(km/h)| Cycle Time(us) | DTC Count      | Error Flag     |\n");
    printf("+---------------+-----------------+----------------+-----------------+-----------------+\n");
    printf("| %-14s | %-16.2f | %-14u | %-15u | %-15s |\n",
           knockDetected ? "Yes" : "No",
           vehicleSpeed,
           cycleTime,
           dtcCount,
           errorFlag ? "Yes" : "No");
    
    printf("\n+-----------------------------+\n");
    printf("| Injector Pulse Width (us)   |\n");
    printf("+-----------------------------+\n");
    for (int i = 0; i < NUM_INJECTORS; i++) {
        printf("| Injector %-2d: %-7u |\n", i + 1, injectorPulseWidth[i]);
    }
    printf("+-----------------------------+\n");
}

// Main logging function
int main(void) {
    print_table_header();
    
    while (1) {
        printf("\033[2J\033[H"); 
        
        print_table_header();
        
        print_table_row();
        
        print_additional_info();
    
        delay_ms(1000); 
    }
    
    return 0;
}
