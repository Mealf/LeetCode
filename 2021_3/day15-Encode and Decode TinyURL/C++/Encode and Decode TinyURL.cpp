class Solution {
    int count=1;
    unordered_map<string, string> m;
    string hash = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int c = count;
        string s = "";
        while(c) {
            s += hash[c%hash.size()];
            c /= hash.size();
        }
        m[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));