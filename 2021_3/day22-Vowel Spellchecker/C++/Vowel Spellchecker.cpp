class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        map<string, string> dict;
        string upper_word, vowel_word;
        for(auto word: wordlist) {
            dict[word] = word;
            upper_word = vowel_word = "";
            for(auto c: word) {
                upper_word += toupper(c);
                switch(upper_word.back()) {
                    case 'A':case 'E':case 'I':case 'O':case 'U':
                        vowel_word += '@';
                        break;
                    default:
                        vowel_word += toupper(c);
                }
            }
            if(!dict.count(upper_word))
                dict[upper_word] = word;
            if(!dict.count(vowel_word))
                dict[vowel_word] = word;
        }
        
        for(auto word: queries) {
            if(dict.count(word)) {
                result.push_back(dict[word]);
                continue;
            }
            
            upper_word = vowel_word = "";
            for(auto c: word) {
                upper_word += toupper(c);
                switch(upper_word.back()) {
                    case 'A':case 'E':case 'I':case 'O':case 'U':
                        vowel_word += '@';
                        break;
                    default:
                        vowel_word += toupper(c);
                }
            }
            
            if(dict.count(upper_word))
                result.push_back(dict[upper_word]);
            else if(dict.count(vowel_word))
                result.push_back(dict[vowel_word]);
            else
                result.push_back("");
        }
        return result;
    }
};