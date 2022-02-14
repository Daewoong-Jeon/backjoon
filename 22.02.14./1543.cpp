#include <iostream>
#include <string>

using namespace std;

int main() {
    string document, word, sub;
    int index = 0;
    int result = 0;
    int word_length, document_length;
    getline(cin, document);
    getline(cin, word);

    word_length = word.length();
    document_length = document.length();
    while (1) {
        if (document_length - index < word_length)
            break;
        sub = document.substr(index, word_length);
        if (sub == word) {
            index += word_length;
            result++;
        }
        else {
            index++;
        }
    }
    cout << result << endl;
}