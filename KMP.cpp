#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void buildLPSArray(string pattern, vector<int>& lps) {
    int n = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string base, string pattern) {
    int m = pattern.length();
    int n = base.length();

    vector<int> lps(m);
    buildLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (base[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != base[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string base, pattern;
    getline(cin, base);
    getline(cin, pattern);
    KMPSearch(base, pattern);
    return 0;
}

