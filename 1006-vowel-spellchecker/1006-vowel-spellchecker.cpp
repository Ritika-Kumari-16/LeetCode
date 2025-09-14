class Solution {
public:
    string to_lower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactset(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caselist;
        unordered_map<string, string> vowelig;

        for (auto &word : wordlist) {
            string lowercaseword = to_lower(word);
            if (caselist.find(lowercaseword) == caselist.end()) {
                caselist[lowercaseword] = word;
            }

            string masked = lowercaseword;
            for (char &c : masked) {
                if (isvowel(c)) c = '*';
            }

            if (vowelig.find(masked) == vowelig.end()) {
                vowelig[masked] = word;
            }
        }

        vector<string> ans;

        for (auto &query : queries) {
            if (exactset.count(query)) {
                ans.push_back(query);
                continue;
            }

            string lowerquery = to_lower(query);
            if (caselist.find(lowerquery) != caselist.end()) {
                ans.push_back(caselist[lowerquery]);
                continue;
            }

            string maskedquery = lowerquery;
            for (char &c : maskedquery) {
                if (isvowel(c)) c = '*';
            }

            if (vowelig.find(maskedquery) != vowelig.end()) {
                ans.push_back(vowelig[maskedquery]);
            } else {
                ans.push_back("");
            }
        }

        return ans;
    }
};
