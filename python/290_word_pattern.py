# Given a pattern and a string s, find if s follows the same pattern.

# Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

# Example 1:
# Input: pattern = "abba", s = "dog cat cat dog"
# Output: true

# Example 2:
# Input: pattern = "abba", s = "dog cat cat fish"
# Output: false

# Example 3:
# Input: pattern = "aaaa", s = "dog cat cat dog"
# Output: false

# Example 4:
# Input: pattern = "abba", s = "dog dog dog dog"
# Output: false

def wordPattern(p, s):
    # Time complexity: O(n)
    # Space complexity: O(n)
    
    s = s.split()
    if not len(s) == len(p):
        return False
    
    # key is the pattern, value is the word
    mapping = dict()
    
    for i in range(len(s)):
        if p[i] not in mapping:
            if s[i] not in mapping.values(): 
                mapping[p[i]] = s[i]
            else:
                return False
        else:
            if not mapping[p[i]] == s[i]:
                return False
    return True

if __name__ == '__main__':
	print(wordPattern('abba', 'dog cat cat dog'))		# True