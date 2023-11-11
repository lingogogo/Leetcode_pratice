class Trie {
public:

    Trie() {
        //vector<string> tree;
    }
    
    void insert(string word) {
        tree.push_back(word);
    }
    
    bool search(string word) {
        if(find(tree.begin(),tree.end(),word) != tree.end())
            return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        for(int i =0; i < tree.size(); i++)
        {
            if(tree[i].find(prefix)==0)
                return true;
        }
        return false;
    }
    private:
        vector<string> tree;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
