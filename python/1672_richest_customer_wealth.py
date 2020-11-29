def maximumWealth(acc):
    # 1 способ
    import numpy as np
    return max([np.sum(acc[i], axis=0) for i in range(len(acc))])

    # 2 способ
    return max(sum(row) for row in accounts)

if __name__ == "__main__":
	# You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
	# Return the wealth that the richest customer has.

	# A customer's wealth is the amount of money they have in all their bank accounts. 
	# The richest customer is the customer that has the maximum wealth.

	# Example:
	# Input: accounts = [[1,5],[7,3],[3,5]]
	# Output: 10

	# Explanation: 
	# 1st customer has wealth = 6
	# 2nd customer has wealth = 10 
	# 3rd customer has wealth = 8
	# The 2nd customer is the richest with a wealth of 10.

	print(maximumWealth([[1, 5], [7, 3], [3, 5]]))	# 10