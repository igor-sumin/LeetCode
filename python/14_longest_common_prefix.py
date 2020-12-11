# 1 способ
def longestCommonPrefix(strs):
	res = ''
	lst = list(zip(*strs))
	
	for item in lst:
		if len(set(item)) == 1:
			res += item[0]
		else:
			break
			
	return res

# 2 способ
def longestCommonPrefix(strs):
	res = min(strs, key=len) if strs else ''
	
	for i, char in enumerate(res):
		for string in strs:
			if string[i] != char:
				return res[:i]
	
	return res

if __name__ == '__main__':
	# Write a function to find the longest common prefix string amongst an array of strings.
	# If there is no common prefix, return an empty string "".

	# Example 1:
	# Input: strs = ["flower","flow","flight"]
	# Output: "fl"

	# Example 2:
	# Input: strs = ["dog","racecar","car"]
	# Output: ""
	# Explanation: There is no common prefix among the input strings.

	longestCommonPrefix(["flower","flow","flight"])		# 'fl'