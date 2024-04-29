//PRC2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Caesar cipher decryption
string caesarDecrypt(const string& ciphertext, int shift) {
    string decryptedText = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decryptedText += ((c - base - shift + 26) % 26) + base;
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

// Function to perform frequency analysis on the ciphertext
vector<pair<char, int>> frequencyAnalysis(const string& ciphertext) {
    vector<int> freq(26, 0);
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            freq[c - base]++;
        }
    }

    vector<pair<char, int>> letterFreq;
    for (char c = 'a'; c <= 'z'; c++) {
        letterFreq.push_back(make_pair(c, freq[c - 'a']));
    }

    // Sorting the frequencies in descending order
    sort(letterFreq.begin(), letterFreq.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    return letterFreq;
}

int main() {
    string ciphertext;
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);

    // Perform frequency analysis on the ciphertext
    vector<pair<char, int>> letterFrequencies = frequencyAnalysis(ciphertext);

    cout << "Letter Frequencies:" << endl;
    for (const auto& pair : letterFrequencies) {
        if (pair.second)
            cout << pair.first << ": " << pair.second << endl;
    }

    // Determine the shift value
    int shift = letterFrequencies[0].first - 'e';

    // Decrypt the ciphertext
    string plaintext = caesarDecrypt(ciphertext, shift);

    cout << "Decrypted plaintext: " << plaintext << endl;

    return 0;
}
