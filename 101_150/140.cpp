//
// Created by janeuler on 2024/8/16.
//
# include <string>
# include <vector>

class TrieNode {
public:
    TrieNode *children[26];

    bool isWord;

    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(std::string &word) {
        TrieNode *node = root;
        for (auto x: word) {
            int index = x - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isWord = true;
    }

    bool search(std::string &target) {
        TrieNode *node = root;

        for (auto x: target) {
            int index = x - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }

        return node->isWord;
    }
};

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict) {
        // insert wordDict first,then seach all combination bypass backtrack
        Trie root;
        for (auto &x: wordDict) {
            root.insert(x);
        }

        std::vector<std::string> ans;
        std::vector<std::string> part;
        backtrack(ans, 0, part, s, root);
        return ans;
    }

private:
    void backtrack(std::vector<std::string> &ans, int index, std::vector<std::string> &part, std::string &s,
                   Trie &root) {
        if (index == s.size()) {
            std::string sentence = "";
            for (int i = 0; i < part.size(); i++) {
                sentence += part[i];
                if (i != part.size() - 1) {
                    sentence += " ";
                }
            }
            ans.push_back(sentence);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            std::string temp = s.substr(index, i - index + 1);
            if (root.search(temp)) {
                part.push_back(temp);
                backtrack(ans, i + 1, part, s, root);
                part.pop_back();
            }
        }
    }
};