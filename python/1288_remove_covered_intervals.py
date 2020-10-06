def removeCoveredIntervals(self, intervals):
    """
    :type intervals: List[List[int]]
    :rtype: int
    """
    
    # 1 способ O(n^2)
    size = len(intervals)
    result = 0
    for i in range(size):
        if any(True for j in range(size) \
            if i != j and intervals[j][0] <= intervals[i][0] and intervals[i][1] <= intervals[j][1]
        ):
            result += 1
            
    return size - result
    
    # 2 способ O(n*logn)
    result = 0
    right = 0
    # сортируем правые границы в порядке убывания
    intervals.sort(key=lambda x: (x[0], -x[1]))
    for a, b in intervals:
        result += b > right
        right = max(right, b)
        
    return result

# # main()
# Given a list of intervals, remove all intervals that are covered by another interval in the list.
# Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
# After doing so, return the number of remaining intervals.

# Example:
# Input: intervals = [[1,4],[3,6],[2,8]]
# Output: 2
# Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.