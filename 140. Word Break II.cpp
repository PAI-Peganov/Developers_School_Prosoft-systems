#include <vector>
#include <string>
#include <map>


using namespace std;

class Solution {
private:
    struct Node {
        map<char, Node*> links;
        Node () {}
    };
    vector<string> answer;
    string sousage;

    void deep(int n, string& s, Node* node) {
        if (n == s.size() && node->links.count(' ') == 1) { answer.push_back(sousage); return; }
        for (auto const [key, val] : node->links) {
            sousage.push_back(key);
            if (key == ' ') {
                deep(n, s, val);
            } else if (s[n] == key) {
                deep(n + 1, s, val);
            }
            sousage.pop_back();
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Node *tree = new Node();
        Node *cur;
        for (string line : wordDict) {
            cur = tree;
            for (char el : line) {
                if (cur->links.count(el) == 0) cur->links[el] = new Node();
                cur = cur->links[el];
            }
            cur->links[' '] = tree;
        }
        deep(0, s, tree);
        return answer;
    }
};