#include <iostream>
typedef std::pair<std::string, int> psi;

psi getNext(std::string &s, int i) {
    int start = i;
    while (start < s.size() && !('a' <= s[start] && s[start] <= 'z') && !('A' <= s[start] && s[start] <= 'Z')) {
        start++;
    }
    if (start >= s.size()-1) return std::pair(s.substr(s.size()-1), -1);
    int end = start;
    while (end+1 < s.size() && ('a' <= s[end+1] && s[end+1] <= 'z') || ('A' <= s[end+1] && s[end+1] <= 'Z')) {
        end++;
    }
    return psi(s.substr(start, end - start + 1), end);
}

int main() {
    std::string s, w;
    std::getline(std::cin, w);
    std::getline(std::cin, s);
    int count = 0;
    int i = 0;
    psi pos = getNext(s, i);
    while (pos.second != -1) {
        if (pos.first == w) count++;
        pos = getNext(s, pos.second+1);
    }
    printf("%d\n", count);
}
