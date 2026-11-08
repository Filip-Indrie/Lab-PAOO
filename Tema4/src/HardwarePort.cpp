#include "HardwarePort.hpp"
#include "Logger.hpp"
#include <iostream>

HardwarePort::HardwarePort(int portId, bool useSafeLogger) : m_portId(portId) {
    std::cout << "[HardwarePort " << m_portId << "] Constructor called on system start-up.\n";
    
    if (useSafeLogger) {
        getSafeSystemLogger().log("Port successfully initialized via SafeLogger.");
    } else {
        g_badLogger.log("Port tried to use g_badLogger.");
    }
}

HardwarePort::~HardwarePort() {
    std::cout << "[HardwarePort " << m_portId << "] Destructor called.\n";
}

void HardwarePort::transmit(const std::string& data) {
    std::cout << "[Port " << m_portId << "] Transmission: " << data << "\n";
}

HardwarePort g_globalPort(8080, false);