#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations of a string
void permutationGenerator(string &s, int pos, vector<string>& ans) {
    if (pos == s.size()) {
        ans.push_back(s);
        return;
    }
    for (int i = pos; i < s.size(); i++) {
        swap(s[pos], s[i]);          // Swap current index with the pos index
        permutationGenerator(s, pos + 1, ans);
        swap(s[pos], s[i]);          // Swap back to restore the original string
    }
}

// Function to print a permutation
void permutationPrinter(const string &str) {
    cout << "{" << str << "} ";
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    vector<string> ans;
    permutationGenerator(str, 0, ans);

    cout << "Permutations of the given string are:\n";
    for (const auto &perm : ans) {
        permutationPrinter(perm);
    }
    cout << endl; // Ensure there's a newline at the end of output

    return 0;
}
