#include <bits/stdc++.h>
using namespace std;

int part1(const vector<string>& rotations) {
    int currentDialPos = 50;
    int counter = 0;

    for (const string& line : rotations) {
        char dir = line[0];
        int val = stoi(line.substr(1));

        if (dir == 'L') {
            currentDialPos = (currentDialPos - val + 100) % 100;
        }
        else if (dir == 'R') { 
            currentDialPos = (currentDialPos + val) % 100;
        }
        if (currentDialPos == 0) counter++;
    }

    return counter;
}

int part2(const vector<string>& rotations) {
    int currentDialPos = 50;
    int counter = 0;

    for (const string& line : rotations) {
        char dir = line[0];
        int val = stoi(line.substr(1));

        if (dir == 'L') {
            for (int i = 0; i < val; i++) {
                currentDialPos = (currentDialPos - 1 + 100) % 100;
                if (currentDialPos == 0) counter++;
            }
        } else if (dir == 'R') {
            for (int i = 0; i < val; i++) {
                currentDialPos = (currentDialPos + 1) % 100;
                if (currentDialPos == 0) {
                    counter++;
                }
            }
        }
    }

    return counter;
}

int main() {
    ifstream file("day01/day1input.txt");
    vector<string> rotations;
    string line;
    while (getline(file, line)) rotations.push_back(line);

    cout << "Part 1: " << part1(rotations) << endl;
    cout << "Part 2: " << part2(rotations) << endl;

    return 0;
}
