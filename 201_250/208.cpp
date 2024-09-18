#include <string>

struct Node
{
    char c;
    bool isWord;
    Node *v[26];
};

class Trie
{
    Node *root;

public:
    Trie() { root = new Node(); }

    void insert(std::string word)
    {
        Node *s = root;
        for (const auto &x : word)
        {
            int index = x - 'a';
            if (!(s->v[index]))
            {
                s->v[index] = new Node();
                s->v[index]->c = x;
                s = s->v[index];
            }
            else
            {
                s = s->v[index];
            }
        }
        s->isWord = true;
    }

    bool search(std::string word)
    {
        Node *s = root;
        for (const auto &x : word)
        {
            int index = x - 'a';
            if (s->v[index])
            {
                s = s->v[index];
            }
            else
            {
                return false;
            }
        }
        return s->isWord;
    }

    bool startsWith(std::string prefix)
    {
        Node *s = root;
        for (const auto &x : prefix)
        {
            int index = x - 'a';
            if (s->v[index])
            {
                s = s->v[index];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};