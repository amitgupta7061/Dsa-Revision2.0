1 -> climbing stairs - f(n-1) + f(n-2)
2 -> frog jump - two step (two option take either one or two)
3 -> frog jump with k dist - using for loop call for i to i+k
4 -> house rob - take or not take and return max
5 -> house rib ii - take 0 to (n-2) or 1 to (n-1)

6 -> unique path - (move either down or right)
7 -> unique path ii - (same as above just in case stone return 0)
8 -> minimum path sum - (curr + max(f(bottom), f(right)))
9 -> triangle - start from bottom+1 and fill column top dp[c] = triangle[r][c] + min(dp[c], dp[c + 1]);
10 -> Ninja's training - track prev day and do whatever whihc is not equal to prev day
11 -> Ninja and his Friends - 