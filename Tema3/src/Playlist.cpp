#include "Playlist.hpp"
#include <string>
#include <iostream>
#include <utility>

Playlist::Playlist(const std::string &name, int cap)
    : playlistName(name), capacity(cap), size(0), songIDs(new int[cap]){

    std::cout << "[Constructor] (" << this->playlistName << ")" << std::endl;
}

Playlist::~Playlist(){
    delete[] this->songIDs;
    this->songIDs = nullptr;
    std::cout << "[Destructor] (" << this->playlistName << ")" << std::endl;
}

Playlist::Playlist(const Playlist &other)
    : playlistName(other.playlistName + "(Copy)"), capacity(other.capacity), size(other.size), songIDs(new int[other.capacity]){

    for (int i = 0; i < other.size; ++i){
        this->songIDs[i] = other.songIDs[i];
    }
    std::cout << "[Copy Constructor] (" << this->playlistName << ")" << std::endl;
}

Playlist::Playlist(Playlist &&other) noexcept
    : playlistName(std::move(other.playlistName) + "(Moved)"), capacity(other.capacity), size(other.size), songIDs(other.songIDs){

    other.songIDs = nullptr;
    other.capacity = 0;
    other.size = 0;
    std::cout << "[Move Constructor] (" << this->playlistName << ")" << std::endl;
}

void Playlist::addSong(int value){
    if (this->size >= this->capacity) return;
    this->songIDs[this->size++] = value;
}

void Playlist::removeSong(int value){
    if (this->size <= 0) return;

    for (int i = 0; i < this->size; ++i){
        if (this->songIDs[i] == value){
            for (int j = i + 1; j < this->size; ++j){
                this->songIDs[j - 1] = this->songIDs[j];
            }
            --this->size;
            return;
        }
    }

}

void Playlist::printInfo() const{
    std::cout << "Playlist name: " << this->playlistName << std::endl << "Max capacity: " << this->capacity << std::endl << "Current size: " << this->size << std::endl << "Song IDs: ";
    for (int i = 0; i < this->size; ++i){
        std::cout << this->songIDs[i] << ", ";
    }
    std::cout << std::endl;
}