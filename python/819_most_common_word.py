import re
from collections import defaultdict

def mostCommonWord(par: str, banned: List[str]) -> str:
    regex = re.compile(r'\w+')
    words = regex.findall(par)
    
    res = defaultdict(int)
    for i in range(len(words)):
        word = words[i].lower()
        if word not in banned:
            res[word] += 1 
        
    # return sorted(res.items(), key=lambda x: x[1])[-1][0]
    return max(res.items(), key=operator.itemgetter(1))[0]


if __name__ == "__main__":
    
    # Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  
    # It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

    # Words in the list of banned words are given in lowercase, and free of punctuation.  
    # Words in the paragraph are not case sensitive.  The answer is in lowercase.

    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]

    print(mostCommonWord(paragraph, banned))    # "ball"