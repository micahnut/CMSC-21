MPA10 (BigNum)

The 101st Fibonacci number has 21 digits. And this cannot be stored in an int since it can only hold up to a maximum of 10 digits.  Your goal is to find a way to represent numbers of up to 1000 digits (one way is via an array of characters - NOT AN ARRAY OF INT, or the use of string of c++).

Create a class called BigNum.  I leave to you as to how you can accomplish the representation for the 1000 digits. The number 145 means that the first 997 digits are all zeroes (if you employed the use of an array). Or it is possible that the first 3 digits are 145 and nothing follows (meaning a '\0' after the 3rd digit).

Provide 3 constructors. These include a default constructor, an overloaded constructor that accepts an int, and another that accepts a string.

Apart from the constructors, include the arithmetic operators addition, subtraction, multiplication, and modulus.

Too, a display function must be implemented.

After implementing your BigNum class, use this to generate and display the nth Fibonacci elements that are you to read from a file named mpa10.in. This file contains a number n representing the number of test cases. n test cases follow.

A sample input file might look like this:

5
101
209
417
311
198

Sample Output:

573147844013817084101
21327100234463183349497947550385773274930109
628580612875886694881648328579603114508131388106874704297602636435532791990880832689122
44225333398004061429732838340729878012027363723832270745251370289
107168651819712326877926895128666735145224