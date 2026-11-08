#include "HardwarePort.hpp"
#include "Logger.hpp"
#include "SensorTypes.hpp"
#include <iostream>

int main() {
    InitOrderTrap badOrder(50);
    badOrder.printState();

    SafeInitOrder goodOrder(50);
    goodOrder.printState();

    std::cout << "\n";
    LogEntry entry("Sensor_Calibration");
    
    std::cout << "\nCtor body assignment:\n";
    SensorConfigInefficient badCfg(entry);

    std::cout << "\nInitialization list:\n";
    SensorConfigEfficient goodCfg(entry);

    std::cout << "\ng_globalPort has been built before running main()\n";
    g_globalPort.transmit("PAYLOAD_TEST");

    g_badLogger.log("Direct call to g_badLogger");

    std::string sName = "Pressure";
    SensorBinding b1(sName, 1.2);
    SensorBinding b2(sName, 3.4);
    // b1 = b2; // Error: operator= implicitly deleted

    HardwarePort localPort(9000, true);
    // HardwarePort copyPort(localPort); // Error: Private copy ctor
    // localPort = g_globalPort; // Error: Private assignment operator

    return 0;
}