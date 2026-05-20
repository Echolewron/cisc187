#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

vector<string> findPlayersInBoth(vector<vector<string>> sport_list1, vector<vector<string>> sport_list2) {
    vector<string> result;  // This will store name of players that play both sports
    
    // Storing names of players that play sport#1 into a set for O(1) recall later
    unordered_set<string> sport_set1;
    sport_set1.reserve(sport_list1.size());

    for (const vector<string>& player : sport_list1) {
        string name = player[0] + " " + player[1];
        sport_set1.insert(name);
    }

    // Checking each sport#2 player name against previous set to see if they already play in sport#1
    for (const vector<string>& player : sport_list2) {
        string name = player[0] + " " + player[1];
        if (sport_set1.count(name)) {
            result.push_back(name);
        }
    }

    return result;
}

int main() {
    vector<vector<string>> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<vector<string>> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    vector<string> both = findPlayersInBoth(basketball_players, football_players);

    for (const string& player : both) {
        cout << player << endl;
    }
}