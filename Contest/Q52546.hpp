#include <iostream>
#include <string>

using namespace std;

int main() {
    int ok_strings = 0, test_cases;
    string init;
    cin >> init >> test_cases;
    for (; test_cases > 0; test_cases--) {
        string test;
        cin >> test;
        int current_char_index = 0;
        char current_char = init[0];
        for (char c : test) {
            if (current_char == c) {
                current_char_index++;
                if (current_char_index == init.size()) {
                    ok_strings++;
                    break;
                }
                current_char = init[current_char_index];
            }
        }
    }
    cout << ok_strings;
}