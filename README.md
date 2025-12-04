# AOC-2025
This years advent of code solutions, done in C++ 

## Solutions/Writeups below: 

### Times (it's my first year doing AOC or any competitive stuff so they wont be good but thats ok!):

| Day | Part 1    | Part 2    |
|-----|-----------|-----------|
| 4   | 00:19:19  | 00:31:22  |
| 3   | 00:21:27  | 00:24:03  |
| 2   | 00:37:56  | 00:55:30  |
| 1   | 00:24:22  | 00:34:21  |

### Day #1
View the problem [here](https://adventofcode.com/2025/day/1) for more context.
Day 1 was rather easy, per-say, but I also took a substantial amount of time to derive a solution from what I had conceived in my mind. Sometimes psuedocode to actual C++ code is what gets me stuck up. But nonetheless, here is a simple breakdown of my solution without exactly revealing the small details of how to implement it, if you want to see that then you are more than welcome to go to [day 1](day01/day1.cpp)!

#### Part 1:
```c++
#include <bits/stdc++.h>
using namespace std;
```
If you've used C++ more than once, you know what these are, it's all the standard header files I'm using to solve this.

The first thing I thought when I was solving this problem was, "oh, this must be easy", so I confidently implemented a solution, and I got an answer looking something a bit like this:
```cpp 
3123445567889999 
```
Now obviously, that was not the answer, and the reason why is pretty simple, when the problem asks you to find all instances where it lands on 0 after any given turn, but we (or in this case me, but I know several other people who made similar mistakes) forgot to account for the wraparound, when a number like 134 is turned to the right or left, you want it to wrap around instead of going to a number past 99. So in this case, to solve the problem I ended up using modulo which returns the remainder so that if the number its being turned by happens to be more than 99, it calculates the remainder and turns it to that. 

#### Part 2:
Part 2 had a tiny little twist attatched additional to part 1, the problem asks us to "calculate all times the dial crosses 0 during any given turn", so now, in addition to calculating when the dial lands on 0, we have to see if any turn in between lands on 0. The solution for this is pretty simple, I:

- Got the start (number before its turned) and the end (number after it was turned) into 2 different variables
- Used a for loop to see if any number in between that was landing on 0
- Profit (in this case the solution)

### Day #2
View the problem [here](https://adventofcode.com/2025/day/2) for more context.
Like day 1, I had trouble implementing this, but this one was easier to think about in my mind for some reason compared to having a visual dial to have to picture. 

#### Part 1:
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day02/day2.cpp).

Now that we got a big block of text out of the way from day 1, heres how I first thought of this problem. I saw the problem and immediately thought, "how could I find the most optimal way to do that without ~8 for loops like everything else I do". Then it hit me (after a solid 5 minutes of staring) that I could divide the total number by 2 and check if both sides were equal, if both sides turned out to be equal, that meant that there was a repeating pattern and that it had to be marked as false and added to the total counter.

It also took me a while to take into account the fact that you can immediately call it safe if when you divide it by 2 it is odd, because then there is no chance of having a complete, repeating pattern.

Now, lets see part 2, it's pretty interesting:

#### Part 2:
Part 2 introduced a twist: I had to count a number as invalid only if it had two or more repetitions of the same pattern. This required a slight adjustment to my Part 1 solution:

New Rule:

Instead of marking all numbers with repeating patterns as invalid, I only counted numbers where the pattern repeated at least once.
Approach:

I reused the isRepeated function from Part 1 but ensured that it only returned true if the pattern repeated at least once.
This was achieved by adding a repeatCount variable to track how many times the pattern repeated.
Implementation:

I wrote a second function part2 that iterated through the range of numbers, applied the new rule, and summed up the invalid numbers.
Challenges and Insights:
Challenge: Translating the problem into code was tricky at first, especially when handling edge cases like odd-length numbers or numbers without any repeating patterns.
Insight: I realized that I could optimize the solution by skipping numbers that couldn’t possibly have repeating patterns (e.g., odd-length numbers).

### Day #3
For more context, view the problem [here](https://adventofcode.com/2025/day/3)
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day03/day3.cpp).

I'm going to be very honest here, day 3 had me baffled. This seems like a very easy problem and it is but I had no clue where to start (spoiler alert, I did end up solving it), so here is what I did when I had no clue on what to do, but ended up solving it:

#### Part 1:
For Part 1, the problem required selecting the two largest digits from each line of input and concatenating them to form the largest possible two-digit number. Here’s how I approached it:

Understand the Problem:

Each line of input represents a bank of digits.
The goal is to pick the two largest digits from the line, in the order they appear, and concatenate them to form a number.

So here was my approach:

I used a greedy algorithm to solve this problem.
Starting from the leftmost digit, I iterated through the line to find the largest digit that could still be selected.
Once the largest digit was found, I moved to the next position and repeated the process to find the second-largest digit.
Implementation:

I wrote a helper function pickK that takes a string of digits and a number k (the number of digits to pick).
The function iterates through the string to find the k largest digits in order.
For Part 1, I called pickK with k = 2 to select the two largest digits.
Result:

After processing all lines, I summed up the concatenated two-digit numbers to get the total output.

#### Part 2:

Part 2 introduced a twist: instead of selecting just two digits, I had to select the 12 largest digits from each line. The approach was similar to Part 1 but scaled up to handle more digits.

New Rule:

Instead of selecting two digits, I needed to select the 12 largest digits from each line.
Approach:

I reused the pickK function from Part 1 but called it with k = 12 to select the 12 largest digits.
The function ensures that the digits are selected in the order they appear in the line.
Result:

After processing all lines, I summed up the concatenated 12-digit numbers to get the total output for Part 2.

Heres what __I think...__
I think that the remaining problems are going to get exponentially difficult. Not difficult in a sense where it is leetcode-hard mode problems but rather in a sense that if you know algorithms and specific approaches to common problems, the problem will be exponentially easier for you to solve.

### Day 4
For more context, view the problem [here](https://adventofcode.com/2025/day/4)
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day03/day4.cpp).

This is actually quite funny, todays problem was an outlier and happend to be a lot easier than the otherse, regardless of the fact that I got a similar time to day 1 because my abundance of skill issue. I didn't have to think too much about it and here is why:

#### Part 1:
I spent about 3 minutes reading and understanding the problem. Once I grasped the requirements, I realized that this was a simple grid traversal problem. The grid was represented as a ```std::vector<string>```, where each cell contained either:
- ```@```(an active symbol), or
- ```.```(an empty space).

The goal was to process the grid and count certain patterns based on the problem's rules. While I wont go into exact details:
    Define the Rules:
        For each @ symbol, I checked its neighbors (up, down, left, right, and diagonals).
        Based on the number of neighboring @ symbols, I determined whether the current @ symbol should be counted or ignored.
    Implementation:
        I used a helper function to count the neighbors of each @ symbol.
        The function iterated through all 8 possible directions (using a dirs vector) to check for valid neighbors.

#### Part 2:

Part 2 introduced a slight twist to the problem. Instead of simply counting @ symbols, I had to remove certain @ symbols from the grid based on specific rules. The process was repeated until no more @ symbols could be removed.

Approach:
Iterative Removal,
I used a while loop to repeatedly process the grid until no changes were made. In each iteration, I identified all @ symbols that needed to be removed and stored their coordinates in a toRemove list.
Neighbor Counting: For each @ symbol, I counted its neighbors using the same logic as Part 1.

If the number of neighbors was less than 4, the @ symbol was marked for removal.After identifying all @ symbols to be removed, I updated the grid by replacing them with ..
I also kept track of the total number of @ symbols removed.
Repeat Until Stable:

The process continued until no more @ symbols were removed in a full pass through the grid.

The function returned the total number of @ symbols removed.

Implementation:

I reused the neighbor-checking logic from Part 1 to determine which @ symbols should be removed.
To avoid modifying the grid while iterating through it, I used a toRemove list to store the coordinates of @ symbols to be removed.
After processing the entire grid, I updated the grid and repeated the process until no more changes were made.

### Day 5

#### Part 1:

#### Part 2:

