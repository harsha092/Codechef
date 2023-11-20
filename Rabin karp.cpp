#include<iostream>
#include<cstring>

using namespace std;

void rabinKarpSearch(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    int textHash = 0;
    int patternHash = 0;
    int h = 1;

    for (int i = 0; i < patternLength - 1; i++) {
        h = (h * 256) % patternLength;
    }

    for (int i = 0; i < patternLength; i++) {
        patternHash = (256 * patternHash + pattern[i]) % patternLength;
        textHash = (256 * textHash + text[i]) % patternLength;
    }

    for (int i = 0; i <= textLength - patternLength; i++) {
        if (patternHash == textHash) {
            for (int j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
                if (j == patternLength - 1) {
                    cout << "Pattern found at index " << i << endl;
                }
            }
        }
        if (i < textLength - patternLength) {
            textHash = (256 * (textHash - text[i] * h) + text[i + patternLength]) % patternLength;
            if (textHash < 0) {
                textHash = textHash + patternLength;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    rabinKarpSearch(text, pattern);
    return 0;
}
