#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Input Data Stream
    cout << "Enter message bits: ";
    string message;
    cin >> message;
    cout << "Enter generator: ";
    string generator;
    cin >> generator;

    int messageLength = message.length();
    int generatorLength = generator.length();
    vector<int> data(messageLength + generatorLength - 1);
    vector<int> divisor(generatorLength);

    // Convert message and generator strings to integer arrays
    for (int i = 0; i < messageLength; ++i) {
        data[i] = message[i] - '0'; // Convert char to int
    }
    for (int i = 0; i < generatorLength; ++i) {
        divisor[i] = generator[i] - '0'; // Convert char to int
    }

    // Calculation of CRC
    for (int i = 0; i < messageLength; ++i) {
        if (data[i] == 1) {
            for (int j = 0; j < generatorLength; ++j) {
                data[i + j] ^= divisor[j];
            }
        }
    }

    // Display CRC
    cout << "The checksum code is: ";
    for (int i = 0; i < messageLength; ++i) {
        data[i] = message[i] - '0'; // Reset data array to original message
    }
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i];
    }
    cout << endl;

    // Check for input CRC code
    cout << "Enter checksum code: ";
    cin >> message;
    cout << "Enter generator: ";
    cin >> generator;

    messageLength = message.length();
    generatorLength = generator.length();
    data = vector<int>(messageLength + generatorLength - 1);
    divisor = vector<int>(generatorLength);

    for (int i = 0; i < messageLength; ++i) {
        data[i] = message[i] - '0';
    }
    for (int i = 0; i < generatorLength; ++i) {
        divisor[i] = generator[i] - '0';
    }

    // Calculation of remainder
    for (int i = 0; i < messageLength; ++i) {
        if (data[i] == 1) {
            for (int j = 0; j < generatorLength; ++j) {
                data[i + j] ^= divisor[j];
            }
        }
    }

    // Display validity of data
    bool valid = true;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == 1) {
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << "Data stream is valid" << endl;
    } else {
        cout << "Data stream is invalid. CRC error occurred." << endl;
    }

    return 0;
}
