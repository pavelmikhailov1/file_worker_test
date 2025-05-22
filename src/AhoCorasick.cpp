
#include "AhoCorasick.hpp"

AhoCorasick::~AhoCorasick() {
    clear(root);
}

void AhoCorasick::addToken(const std::string& pattern, size_t* countPtr) {
    Node* node = root;
    for (char ch : pattern) {
        if (!node->children[ch])
            node->children[ch] = new Node;
        node = node->children[ch];
    }
    node->outputs.push_back(countPtr);
}

void AhoCorasick::build() {
    std::queue<Node*> q;

    root->fail = root;

    for (auto& [ch, child] : root->children) {
        child->fail = root;
        q.push(child);
    }

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        for (auto& [ch, next] : current->children) {
            Node* fail = current->fail;
            while (fail != root && !fail->children.count(ch)) {
                fail = fail->fail;
            }

            if (fail->children.count(ch)) {
                fail = fail->children[ch];
            }

            next->fail = fail;

            next->outputs.insert(
                next->outputs.end(),
                fail->outputs.begin(),
                fail->outputs.end()
            );

            q.push(next);
        }
    }
}

void AhoCorasick::search(const std::string& text) {
    Node* node = root;
    for (char ch : text) {
        while (node != root && !node->children.count(ch)) {
            node = node->fail;
        }

        if (node->children.count(ch)) {
            node = node->children[ch];
        }


        for (auto* countPtr : node->outputs) {
            ++(*countPtr);
        }

    }
}

void AhoCorasick::clear(Node* node) {
    for (auto& [_, child] : node->children) {
        clear(child);
    }
    delete node;
}