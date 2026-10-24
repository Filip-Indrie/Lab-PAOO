#pragma once // TO AVOID MULTIPLE INCLUSION
#include <string>

class Playlist{
    private:
        std::string playlistName;
        int capacity;
        int size;
        int *songIDs;
    
    public:
        Playlist(const std::string &name, int cap);
        ~Playlist();
        Playlist(const Playlist &other);
        Playlist(Playlist &&other) noexcept;

        void addSong(int value);
        void removeSong(int value);
        void printInfo() const;

        int getSize() const {return size;}
        bool isNull() const {return songIDs == nullptr;}
};