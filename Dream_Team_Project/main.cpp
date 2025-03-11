#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Stats {
    char add_member;
    char drop_member;
    int tally_total_members;
    int total_members;
    double average_members;
    Stats() : add_member(0), drop_member(0), tally_total_members(0), total_members(0), average_members(0.0) {}
};

struct Team {
    string character;
    string add_drop;
    int totalmember;
    Team() : character(""), add_drop(""), totalmember(0) {}
};

// Function to update stats (called after each Add/Drop action)
void update_stats(Stats& s, Team& t) {
    s.tally_total_members++;
    s.total_members = 0;
    s.average_members = (s.total_members / s.tally_total_members);
}

// Function to display team status after each action
void display(string dreamTeam[], int size) {
    if (size == 0) {
        cout << "No characters in the episode." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << dreamTeam[i] << endl;  // Display each member in the team
        }
    }
}

int main() {
    const int SIZE = 20;  // Array size to hold up to 20 members
    string dreamTeam[SIZE];
    Team dream;
    Stats data;
    unsigned size = 0;  // Tracks the current number of members in the team

    ifstream file;
    file.open("dream_team.csv");
    if (!file.is_open()) {
        cout << "File is not open properly.\n";
        return 1;
    }

    cout << "This program demonstrates the thinking process of building a cast for the next episode of SILO" << endl;

    while (!file.eof()) {
        getline(file, dream.add_drop, ',');
        getline(file, dream.character);

        // Process Add action
        if (dream.add_drop == "Add") {
            data.tally_total_members++;
            dreamTeam[size] = dream.character;
            size++;

            cout << "After adding " << dream.character << " the episode now has " << data.tally_total_members << " character(s)" << endl;
            display(dreamTeam, size); // Display the team roster
        }

        // Process Drop action
        if (dream.add_drop == "Drop") {
            data.tally_total_members--;
            bool found = false;
            for (int i = 0; i < size && !found; i++) {
                if (dreamTeam[i] == dream.character) {
                    // Shift the members to fill the gap
                    for (int j = i; j < size - 1; j++) {
                        dreamTeam[j] = dreamTeam[j + 1];
                    }
                    size--;
                    found = true;
                }
            }

            cout << "After dropping " << dream.character << " the episode now has " << data.tally_total_members << " character(s)" << endl;
            display(dreamTeam, size); // Display the updated team roster
        }
    }

    file.close();  // Close the file after processing

    return 0;
}

     