class Solution {
public:
    bool checkVowel(char a) {
        bool small = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
        bool large = (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
        return (small || large);
    }

    bool halvesAreAlike(string s) {
        int vowel1 = 0,vowel2 = 0;
        int n = s.length();
        for(int i=0 ; i<n/2 ; ++i) {
            if(checkVowel(s[i])) {
                vowel1 += 1;
            }
        }
        for(int i=n/2 ; i<n ; ++i) {
            if(checkVowel(s[i])) {
                vowel2 += 1;
            }
        }
        return vowel1 == vowel2;
    }
};