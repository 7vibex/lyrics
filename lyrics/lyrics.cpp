#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void displayLyrics(const std::vector<std::string>& lyrics, const std::vector<int>& lineDelays, const std::vector<int>& interLineDelays) {
    for (size_t i = 0; i < lyrics.size(); ++i) {
        const std::string& line = lyrics[i];
        int letterDelay = lineDelays[i] / line.size();  // Întârziere între litere

        for (char c : line) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(letterDelay));
        }
        std::cout << std::endl;

        if (i < interLineDelays.size()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(interLineDelays[i]));  // Pauză unică între versuri
        }
    }
}

void setColor(int code) {
    std::cout << "\033[38;5;" << code << "m";
}

void resetColor() {
    std::cout << "\033[0m";
}

int main() {
    std::vector<std::string> lyrics = {
        "With no makeup she a ten",
        "And she the best with that head\nEven better then Karrine",
        "She don't want money",
        "She want the time that we could spend",
        "She said \"cause I really need somebody\nSo tell me you're that somebody\"",
        "Girl, I fuck who I want ",
        "and fuck who I don't",
        "Got that A1 credit, that's that filet mignon"
    };

    std::vector<int> lineDelays = { 1800, 3400, 1500, 1800, 4000, 1600, 1800, 3050 };

    std::vector<int> interLineDelays = { 300, 600, 600, 50, 60, 400, 100 };

    setColor(21); // Albastru 
    displayLyrics({ lyrics[0], lyrics[1], lyrics[2], lyrics[3] }, { lineDelays[0], lineDelays[1], lineDelays[2], lineDelays[3] }, { interLineDelays[0], interLineDelays[1], interLineDelays[2], interLineDelays[3] });

    setColor(201); // Pink color
    displayLyrics({ lyrics[4] }, { lineDelays[4] }, { interLineDelays[4] });

    setColor(21); // Albastru 
    displayLyrics({ lyrics[5], lyrics[6], lyrics[7] }, { lineDelays[5], lineDelays[6], lineDelays[7] }, { interLineDelays[5], interLineDelays[6] });

    resetColor(); // Reset 
    return 0;
}
