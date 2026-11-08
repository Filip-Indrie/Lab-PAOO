#pragma once
#include <iostream>
#include <string>

class InitOrderTrap {
private:
    int m_allocatedCapacity;
    int m_requestedSize;

public:
    InitOrderTrap(int size) 
        : m_requestedSize(size), 
          m_allocatedCapacity(m_requestedSize * 2) // BUG: m_requestedSize contains garbage data!
    {}

    void printState() const {
        std::cout << "  [InitOrderTrap] Requested: " << m_requestedSize 
                  << " | Allocated: " << m_allocatedCapacity << "\n";
    }
};

class SafeInitOrder {
private:
    int m_requestedSize;
    int m_allocatedCapacity;
public:
    SafeInitOrder(int size)
        : m_requestedSize(size),
          m_allocatedCapacity(m_requestedSize * 2)
    {}

    void printState() const {
        std::cout << "  [SafeInitOrder] Requested: " << m_requestedSize 
                  << " | Allocated: " << m_allocatedCapacity << "\n";
    }
};

class LogEntry {
public:
    LogEntry() : m_msg("Default") {
        std::cout << "    [LogEntry] Default ctor\n";
    }
    LogEntry(const std::string& msg) : m_msg(msg) {
        std::cout << "    [LogEntry] Param ctor: " << m_msg << "\n";
    }
    LogEntry(const LogEntry& rhs) : m_msg(rhs.m_msg) {
        std::cout << "    [LogEntry] Copy ctor: " << m_msg << "\n";
    }
    LogEntry& operator=(const LogEntry& rhs) {
        m_msg = rhs.m_msg;
        std::cout << "    [LogEntry] operator= (assignment): " << m_msg << "\n";
        return *this;
    }
private:
    std::string m_msg;
};

class SensorConfigInefficient {
public:
    SensorConfigInefficient(const LogEntry& entry) {
        m_entry = entry; // ctor + assignment
    }
private:
    LogEntry m_entry;
};

class SensorConfigEfficient {
public:
    SensorConfigEfficient(const LogEntry& entry) : m_entry(entry) {} // Only copy ctor
private:
    LogEntry m_entry;
};

class SensorBinding {
public:
    SensorBinding(std::string& sensorName, double calib)
        : m_sensorName(sensorName), m_calibration(calib) {}
private:
    std::string& m_sensorName;  // cannot reassign references --> compilation error
    const double m_calibration; // cannot reassign thorugh assignment --> compilation error
};