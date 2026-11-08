#pragma once
#include "Uncopyable.hpp"
#include <string>

class HardwarePort : private Uncopyable {
public:
    explicit HardwarePort(int portId, bool useSafeLogger);
    ~HardwarePort();
    void transmit(const std::string& data);
private:
    int m_portId;
};

extern HardwarePort g_globalPort;
