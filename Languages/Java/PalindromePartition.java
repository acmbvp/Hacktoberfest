import java.util.Scanner;

/* 
Palindrome Partitioning

Given a string, a partitioning of the string is a palindrome partitioning if every substring 
of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string. 
For example, minimum 3 cuts are needed for “ababbbabbababa”.
*/

//Time Complexity: O(n^3)
public class PalindromePartitioning {
    public static int minPartition(String str) {
        int n = str.length();
        int[][] c = new int[n][n];
        boolean[][] p = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            p[i][i] = true;
            c[i][i] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (len == 2) {
                    p[i][j] = (str.charAt(i) == str.charAt(j));
                } else {
                    p[i][j] = (str.charAt(i) == str.charAt(j)) && p[i + 1][j - 1];
                }
                if (p[i][j]) {
                    c[i][j] = 0;
                } else {
                    c[i][j] = Integer.MAX_VALUE;
                    for (int k = i; k <= j - 1; k++) {
                        c[i][j] = Math.min(c[i][j], c[i][k] + c[k + 1][j] + 1);
                    }
                }
            }
        }
        return c[0][n - 1];
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String str = s.nextLine();
        System.out.println("The minimum number of partitions is: " + minPartition(str));
    }
}