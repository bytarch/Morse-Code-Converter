#include <iostream>
#include <map>
#include <sstream>
#include <cctype>

std::map<char, std::string> charToMorseMap;
std::map<std::string, char> morseCodeMap;
void initializeMorseCodeMap() {
    morseCodeMap[".-"] = 'A';
    morseCodeMap["-..."] = 'B';
    morseCodeMap["-.-."] = 'C';
    morseCodeMap["-.."] = 'D';
    morseCodeMap["."] = 'E';
    morseCodeMap["..-."] = 'F';
    morseCodeMap["--."] = 'G';
    morseCodeMap["...."] = 'H';
    morseCodeMap[".."] = 'I';
    morseCodeMap[".---"] = 'J';
    morseCodeMap["-.-"] = 'K';
    morseCodeMap[".-.."] = 'L';
    morseCodeMap["--"] = 'M';
    morseCodeMap["-."] = 'N';
    morseCodeMap["---"] = 'O';
    morseCodeMap[".--."] = 'P';
    morseCodeMap["--.-"] = 'Q';
    morseCodeMap[".-."] = 'R';
    morseCodeMap["..."] = 'S';
    morseCodeMap["-"] = 'T';
    morseCodeMap["..-"] = 'U';
    morseCodeMap["...-"] = 'V';
    morseCodeMap[".--"] = 'W';
    morseCodeMap["-..-"] = 'X';
    morseCodeMap["-.--"] = 'Y';
    morseCodeMap["--.."] = 'Z';
    morseCodeMap["-----"] = '0';
    morseCodeMap[".----"] = '1';
    morseCodeMap["..---"] = '2';
    morseCodeMap["...--"] = '3';
    morseCodeMap["....-"] = '4';
    morseCodeMap["....."] = '5';
    morseCodeMap["-...."] = '6';
    morseCodeMap["--..."] = '7';
    morseCodeMap["---.."] = '8';
    morseCodeMap["----."] = '9';
}
void initializeCharToMorseMap() {
    // Reverse mapping for encoding
    for (const auto& entry : morseCodeMap) {
        charToMorseMap[entry.second] = entry.first;
    }
}

std::string encodeToMorseCode(const std::string& message) {
    std::stringstream encodedMorse;

    for (char ch : message) {
        if (std::isalpha(ch) || std::isdigit(ch)) {
            char upperCh = std::toupper(ch);
            encodedMorse << charToMorseMap[upperCh] << ' ';
        } else if (ch == ' ') {
            // Treat space as '/'
            encodedMorse << "/ ";
        }
    }

    return encodedMorse.str();
}

std::string decodeMorseCode(const std::string& morseCode) {
    std::stringstream decodedMessage;
    std::string currentSymbol;

    for (char ch : morseCode) {
        if (ch == ' ' || ch == '/') {
            if (!currentSymbol.empty()) {
                decodedMessage << morseCodeMap[currentSymbol];
                currentSymbol.clear();
            } else if (ch == '/') {
                // Treat '/' as space
                decodedMessage << ' ';
            }
        } else {
            currentSymbol += ch;
        }
    }

    if (!currentSymbol.empty()) {
        decodedMessage << morseCodeMap[currentSymbol];
    }

    return decodedMessage.str();
}

int main() {
    initializeMorseCodeMap();
    initializeCharToMorseMap();

    int choice;
    std::string input;
    std::string decodedMessage;
    std::string encodedMorse;

    do {
        std::cout << "Choose an option:\n";
        std::cout << "1. Decode Morse code\n";
        std::cout << "2. Encode message to Morse code\n";
        std::cout << "3. Quit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline left in the buffer

        switch (choice) {
            case 1:
                std::cout << "Enter Morse code: ";
                std::getline(std::cin, input);
                decodedMessage = decodeMorseCode(input);
                std::cout << "Decoded Message: " << decodedMessage << std::endl;
                break;
            case 2:
                std::cout << "Enter message to encode: ";
                std::getline(std::cin, input);
                encodedMorse = encodeToMorseCode(input);
                std::cout << "Encoded Morse code: " << encodedMorse << std::endl;
                break;
            case 3:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
