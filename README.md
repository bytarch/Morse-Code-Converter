# Morse Code Converter

## Overview

This C++ program converts messages to Morse code and vice versa. It provides a user-friendly command-line interface to decode Morse code into text and encode text into Morse code.

## Features

- Decodes Morse code to text
- Encodes text to Morse code
- User-friendly command-line interface
- Supports letters A-Z, digits 0-9, and space

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Git

### Installation

```bash
git clone https://github.com/yourusername/morse-code-converter.git
cd morse-code-converter
g++ main.cpp -o morse_converter
./morse_converter

Usage

    Choose an option:
        Enter 1 to decode Morse code.
        Enter 2 to encode a message to Morse code.
        Enter 3 to quit the program.

    Enter Input:
        If decoding, enter the Morse code.
        If encoding, enter the message.

    View Result:
        The program will display the decoded/encoded message.

Morse Code Mapping

The Morse code is mapped as follows:
A .-       N -.
B -...     O ---
C -.-.     P .--.
D -..      Q --.-
E .        R .-.
F ..-.     S ...
G --.      T -
H ....     U ..-
I ..       V ...-
J .---     W .--
K -.-      X -..-
L .-..     Y .--  
M --       Z --..

0 -----
1 .----
2 ..---
3 ...--
4 ....-
5 .....
6 -....
7 --...
8 ---..
9 ----.

Contributions

Feel free to contribute to this project by opening issues or pull requests.
License

This project is licensed under the MIT License.
