#include "Playlist.hpp"
#include <iostream>
#include <utility>

Playlist createDefaultFavorites() {
    Playlist temp("Default Favorites", 10);
    temp.addSong(101);
    temp.addSong(102);
    return temp;
}

int main() {
    {
        Playlist tempScope("Temporary", 5);
        tempScope.addSong(10);
        tempScope.printInfo();
        // Destructor called here
    }
    std::cout << std::endl;

    // Copy Constructor --> shallow vs deep cloning
    Playlist original("Original", 5);
    original.addSong(201);
    original.addSong(202);

    Playlist cloned = original;

    // Shallow: both will have 999 as their 3rd song ID
    // Deep: original will have 888; cloned will have 999
    original.addSong(888);
    cloned.addSong(999);

    std::cout << "--- Original ---\n";
    original.printInfo();

    std::cout << "--- Cloned ---\n";
    cloned.printInfo();
    std::cout << std::endl;

    // NRVO: The object is created in the correct place in memory, no longer needing to be moved/copied.
    std::cout << "Creating from temporary return value:\n";
    Playlist imported = createDefaultFavorites();
    imported.printInfo();
    std::cout << std::endl;

    // Move constructor; original should not be empty since, if not implemented, the move constructor calls the copy constructor
    std::cout << "Moving from 'original' using std::move:\n";
    Playlist movedTo = std::move(original);

    if (!original.isNull()) 
        original.addSong(555);
    else
        std::cout << "Song list is null" << std::endl;
    movedTo.addSong(444);

    std::cout << "--- Original ---\n";
    original.printInfo();

    std::cout << "--- Moved ---\n";
    movedTo.printInfo();
    std::cout << std::endl;

    std::cout << "--- Source Playlist state after move ---\n";
    std::cout << "Is original.songIDs null? " << (original.isNull() ? "YES" : "NO") << "\n";
    std::cout << "Original size: " << original.getSize() << "\n\n";


    // destructors (if broken, crahses when trying to delete `original (copy)` after `original (moved)` has been deleted)
    return 0;
}