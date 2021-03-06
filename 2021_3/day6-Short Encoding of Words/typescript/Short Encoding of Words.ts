function minimumLengthEncoding(words: string[]): number {
    let dict = new Set(words);
    
    for(let word of words) {
        for(let i = 1; i<word.length; i++) {
            dict.delete(word.substring(i));
        }
    }
    
    let ans : number = 0;
    for(let word of dict) 
        ans += word.length + 1
    
    return ans;
};