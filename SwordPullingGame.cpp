#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class Sword {
public:
    int effort;

    Sword() : effort(0) {}

    void pullEffort() {
        int additionalEffort = 5;
        effort += additionalEffort;
        cout << "You exerted " << additionalEffort << " effort. Total effort: " << effort << endl;
    }

    bool isPulled() {
        return effort >= 20;
    }

    void reset() {
        effort = 0;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int timeLimitSeconds = 10;
    auto startTime = steady_clock::now();
    int swordsPulled = 0;
    Sword sword;
    char choice;

    cout << "Sword Pulling Game!" << endl;
    cout << "Pull as many swords out the ground as possible!" << "(Press any key to exert effort, or 'q' to quit)" << endl;

    while (true) {
        auto currentTime = steady_clock::now();
        auto elapsedTime = duration_cast<seconds>(currentTime - startTime).count();

        if (elapsedTime >= timeLimitSeconds) {
            cout << "Time's up!" << endl;
            break;
        }

        cout << "Time remaining: " << timeLimitSeconds - elapsedTime << " seconds." << endl;

        choice = _getch();

        if (choice == 'q') {
            cout << "Quitting the game. Thanks for playing!" << endl;
            break;
        } else {
            sword.pullEffort();
            if (sword.isPulled()) {
                swordsPulled++;
                cout << "Congratulations! You have successfully pulled a sword!" << endl;
                sword.reset();
            }
        }

        this_thread::sleep_for(milliseconds(200));
    }

    cout << "You pulled " << swordsPulled << " swords in " << timeLimitSeconds << " seconds." << endl;

    return 0;
}
