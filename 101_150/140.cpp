//
// Created by janeuler on 2024/8/16.
//
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode *children[26];

    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; ++i) {
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

    void insert(string word) {
        TrieNode *node = root;
        for (char c: word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }

    bool searchWord(string word) {
        TrieNode *node = root;
        for (char c: word) {
            int index = c - 'a';
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
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        // 构建字典树
        Trie trie;
        for (const string &word: wordDict) {
            trie.insert(word);
        }

        vector<string> result;
        vector<string> path;
        backtrack(0, s, path, result, trie);
        return result;
    }

private:
    // 回溯函数
    void backtrack(int index, string &s, vector<string> &path, vector<string> &result, Trie &trie) {
        if (index == s.size()) {
            // 结束条件：已经处理完整个字符串
            string sentence = "";
            for (int i = 0; i < path.size(); ++i) {
                sentence += path[i];
                if (i < path.size() - 1) {
                    sentence += " ";
                }
            }
            result.push_back(sentence);
            return;
        }

        // 尝试匹配 wordDict 中的单词
        for (int i = index; i < s.size(); ++i) {
            string prefix = s.substr(index, i - index + 1);
            if (trie.searchWord(prefix)) {
                // 找到一个匹配的单词
                path.push_back(prefix);
                backtrack(i + 1, s, path, result, trie);
                path.pop_back(); // 回溯
            }
        }
    }
};
