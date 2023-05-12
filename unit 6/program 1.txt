# Implement a dynamic programming algorithm for the Longest Common Subsequence Problem (LCS) 

def lcs(s1, s2):
    m = len(s1)
    n = len(s2)
    dp = [[0] * (n+1) for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, n+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    # Backtrack to find LCS
    lcs_str = ""
    i = m
    j = n
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            lcs_str = s1[i-1] + lcs_str
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1

    return lcs_str

""" 
Analyze its time and space complexity using Big-O notation.
The time complexity of this implementation is O(mn),
where m and n are the lengths of the two input strings. 
This is because we fill in a two-dimensional array of size (m+1) x (n+1) in a nested loop. 
The space complexity is also O(mn) because we use this two-dimensional array to store the subproblem solutions.
In comparison, a brute-force approach to this problem would involve trying all possible 
subsequences of both input strings and checking if they match. 
This approach would have a time complexity of O(2^(m+n)) and a space complexity of O(m+n), 
which is much less efficient than the dynamic programming approach.
"""