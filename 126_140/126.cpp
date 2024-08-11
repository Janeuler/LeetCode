//
// Created by janeuler on 2024/8/9.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <queue>

class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord,
                                                       std::vector<std::string> &wordList) {
        std::vector<std::vector<std::string> > res;
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end()) {
            return res;
        }

        dict.erase(beginWord);

        std::unordered_map<std::string, int> steps = {{beginWord, 0}};
        std::unordered_map<std::string, std::set<std::string> > from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        std::queue<std::string> q;
        q.push(beginWord);
        int wordLen = beginWord.length();

        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                std::string currWord = std::move(q.front());
                std::string nextWord = currWord;
                q.pop();
                for (int j = 0; j < wordLen; ++j) {
                    char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        dict.erase(nextWord);
                        q.push(nextWord);
                        from[nextWord].insert(currWord);
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }

        if (found) {
            std::vector<std::string> path = {endWord};
            backtrack(res, endWord, from, path);
        }
        return res;
    }

    void backtrack(std::vector<std::vector<std::string> > &res, const std::string &node,
                   std::unordered_map<std::string, std::set<std::string> > &from,
                   std::vector<std::string> &path) {
        if (from[node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const std::string &parent: from[node]) {
            path.push_back(parent);
            backtrack(res, parent, from, path);
            path.pop_back();
        }
    }
};
