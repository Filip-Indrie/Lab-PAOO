#pragma once

class Uncopyable {
protected:
    Uncopyable() {}
    ~Uncopyable() {}
    Uncopyable(const Uncopyable&) = delete;
    Uncopyable& operator=(const Uncopyable&) = delete;
// private:
//     Uncopyable(const Uncopyable&);
//     Uncopyable& operator=(const Uncopyable&);
};