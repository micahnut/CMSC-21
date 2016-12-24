MPA 8 (The Search for the One or Ones?)

This is similar to MP 7. But instead of reading in numbers, you are to read in words. This means that the item for the node of the binary tree should be a string instead of an integer.  This goes the same for the linked-list. Unlike in MP 7, there is no need to keep track the number of occurrences of the words in the word file. 

The input is composed of a number t, followed by t test cases. Each test case will be a word. This input should be read from a file. The file name is mpa8.in.

The output will display the word followed by two counts. The word and the counts should separated by a colon and the counts by a space. The counts should represent the number of comparisons made until the word is found (or until the search is exhausted without finding the word). The first count is the count for the linked-list implementation. The second count is for the binary tree implementation. Print the output in the console.

Sample Input:

4
hello
quick
social
construct

Sample Output:

hello: 20 4
quick: 90 35
social: 106 40
construct: 10 2

NOTE: The sample above is not based on the words file uploaded 