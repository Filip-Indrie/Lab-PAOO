#include "Logger.hpp"
#include <iostream>

BadGlobalLogger::BadGlobalLogger() 
    : m_prefix("[BAD GLOBAL LOG]"), m_isReady(true) {
    std::cout << ">>> BadGlobalLogger built.\n";
}

void BadGlobalLogger::log(const std::string& message) {
    if (!m_isReady) {
        std::cout << "[!] BadGlobalLogger called before being constructed!\n";
    }
    std::cout << m_prefix << " " << message << "\n";
}

BadGlobalLogger g_badLogger;

SafeSystemLogger::SafeSystemLogger() 
    : m_prefix("[SAFE LOCAL LOG]"), m_isReady(true) {
    std::cout << ">>> SafeSystemLogger built on first request.\n";
}

void SafeSystemLogger::log(const std::string& message) {
    std::cout << m_prefix << " " << message << "\n";
}

SafeSystemLogger& getSafeSystemLogger() {
    static SafeSystemLogger logger;
    return logger;
}