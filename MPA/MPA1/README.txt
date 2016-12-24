MPA 1 (Ang Pagbanhaw ni MPA) Assignment

Prompt the user with the following menu:

Sieve of Eratosthenes
Big Number
Coin Changing
Exit

For item number 1, it is supposed to generate the nth (input from user) prime number using the Sieve of Eratosthenes. 
The limit of n is 10,000. You may check this link for the first 10,000 prime numbers: https://primes.utm.edu/lists/small/10000.txt

For item number 2, it is supposed to be able to perform addition or subtraction between 2 big numbers. 
The numbers can be as long as 100 digits. This means that the use of int or even unsigned int is not possible. 
You should be able to represent a big number using a string (an array of characters) or an array of numbers.
When the user chooses item 2, ask the user to enter 2 big numbers, then prompt the user with another menu asking him/her to choose
between addition or subtraction. Then perform the desired operation between the 2 numbers and display the result.
Notice that the result may be less than 0.

For item number 3, assume that there are 20, 10, 5, and 1-peso coins available. 
Given an amount (no floating point, unsigned int), you should be able to give the total number of possible combinations of coins that 
add up to the given amount. For instance, if the amount is 13 pesos, it can be represented using 13 1-peso coins or 8 1-peso coins
and 1 5-peso coin or 3 1-peso coins and 2 5-peso coins or 3 1-peso coins and a 10-peso coin. 
This is a total of 4 combinations. The amount may go as large as 100,000.

All the items should be implemented as functions. All inputs should be asked from the main and should be passed to the functions 
accordingly. All outputs should be displayed in the main except for item number 2 where the output may be displayed in the function.