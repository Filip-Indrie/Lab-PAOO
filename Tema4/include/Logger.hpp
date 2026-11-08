#pragma once
#include <string>

class BadGlobalLogger {
public:
    BadGlobalLogger();
    void log(const std::string& message);
private:
    std::string m_prefix;
    bool m_isReady;
};

extern BadGlobalLogger g_badLogger;

class SafeSystemLogger {
public:
    SafeSystemLogger();
    void log(const std::string& message);
private:
    std::string m_prefix;
    bool m_isReady;
};


SafeSystemLogger& getSafeSystemLogger();
