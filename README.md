# AOC-2025
This years advent of code solutions, done in C++ 

[Advent of Code](https://adventofcode.com/2025) is a yearly coding competition where there is one problem per day of december starting december first, this usually lasts ~25 days but this year it's only 12.

## Solutions/Writeups below: 

### Times (it's my first year doing AOC or any competitive stuff so they wont be good but thats ok!):

| Day | Part 1    | Part 2    | Completed? |
|-----|-----------|-----------|------------|
| 9   | 00:06:59  | 00:08:28  | Yes        |
| 8   | 00:09:59  | 00:11:15  | Yes        |
| 7   | 00:31:28  | 00:40:03  | Yes        |
| 6   | 01:43:22  | 02:41:10  | Yes        |
| 5   | 00:18:46  | 00:21:26  | Yes        |
| 4   | 00:19:19  | 00:31:22  | Yes        |
| 3   | 00:21:27  | 00:24:03  | Yes        |
| 2   | 00:37:56  | 00:55:30  | Yes        |
| 1   | 00:24:22  | 00:34:21  | Yes        |

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
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day04/day4.cpp).

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
For more context, view the problem [here](https://adventofcode.com/2025/day/5)
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day05/day5.cpp).

Part 1 was pretty easy, and I also found part 2 relatively easy but it made me think more about whats the best way to do it, I also had to optimize quite a bit because my first output took ~48 seconds which is horrible.

#### Part 1:
The second you look at the [problem](https://adventofcode.com/2025/day/5) you notice that it seems easy, all you have to do is: 

- Parse input and seperate the num-num range into actual ranges (this part varies by language)
- Loop through every value in that range and see if the number is in the range
- Add one to the total counter if it is
- Print total count for answer of which ingredients are fresh

And if that was your approach/what you thought of, you are right! 
One thing that I happend to run into was the variable sizes, I had to change things from ```int``` to ```long long``` (which is a data type in C++ that is as big as 8 bytes) because int couldnt store the big values haha!

#### Part 2:

Part 2 introduced a more challenging twist compared to Part 1. Instead of simply counting how many numbers fall within the given ranges, I had to merge overlapping ranges and calculate the total length of all the merged ranges. This required a more thoughtful approach to optimize the solution.

Approach:

The first step was to sort all the ranges by their starting points. This ensures that overlapping or adjacent ranges are grouped together.
Merge Overlapping Ranges:

I iterated through the sorted ranges and merged any overlapping or adjacent ranges into a single range.
If the current range did not overlap with the previous range, I added the length of the previous range to the total and started a new range.
Calculate the Total Length:

After merging all the ranges, I calculated the total length of the merged ranges by summing up the lengths of each range.
Optimization:

Sorting the ranges upfront and merging them in a single pass ensured that the solution was efficient, with a time complexity of (O(n \log n)) due to the sorting step.

### Day 6
For more context, view the problem [here](https://adventofcode.com/2025/day/6)
Now, I wont be going into exact details of how I went about solving this in the following 2-3 paragraphs, but this is just the general method and thought process I went with. If you want to see the exact solution, refer to [this](day06/day6.py).

#### Problem Overview
The Elves’ kitchen has a **math worksheet** where problems are arranged vertically in columns. Each problem consists of numbers, and the last row gives the operator (`+` or `*`) to apply to the column of numbers above it.

- **Part 1:** Read the numbers **as-is**, column by column.
- **Part 2:** Cephalopod math reads numbers **right-to-left**, with each column of digits forming a number from top to bottom.

The task is to compute the **grand total** of all problems.

I did this problem in Python because I couldn't get it to work in C++ and python reduced the scope for errors, I may transalate this into C++ tommorrow if I have time.
This problem had a rather tricky algorithm, but that's not why I got 3 hours in total.
Advent of Code tracks your time from when it releases and I happend to have done it 1 hour late.

### Day 7

For more context, view the problem [here](https://adventofcode.com/2025/day/7)

This problem involves simulating tachyon beams passing through a manifold with splitters. The twist from Part 1 to Part 2 introduces quantum mechanics—instead of a single beam splitting, we need to count the number of parallel timelines that result.

#### Part 1: Counting Split Events

**Problem:** A tachyon beam enters from position 'S' and moves downward. When it hits a splitter (^), the beam is stopped and two new beams emerge (left-down and right-down). We need to count the total number of split events.

**Approach:**
- Use DFS (depth-first search) to traverse all beam paths
- Track visited cells to avoid infinite loops
- Increment a counter each time we encounter a `^` splitter
- When a beam hits a splitter, it branches into two paths that both continue downward

**Answer: 1598** (this is for me please dont put this into your thing and expect it to work each persons input varies)

#### Part 2: Counting Timelines with Dynamic Programming

**Problem:** With quantum tachyons, a single particle takes both paths at each splitter simultaneously, creating parallel timelines. Count how many distinct timelines exist after the particle completes its journey.

**Key Insight:** Each timeline corresponds to a unique exit column. When paths merge (multiple beams reaching the same cell), their timeline counts combine. This is a dynamic programming problem where we need to count the number of paths reaching each bottom position.

**Approach:**
- Use memoization to cache results for each (row, column) position
- For each position, calculate how many paths lead from that position to the bottom
- At a splitter `^`: paths = left_paths + right_paths
- At empty space or start: paths = straight_down_paths
- Base case: Reaching the bottom counts as 1 successful timeline

**Why Memoization Matters:**
Without memoization, the same (row, col) position gets recalculated exponentially many times, leading to O(2^n) time complexity. With memoization, each position is computed once, reducing to O(rows × cols).

**Answer: 4509723641302** (this is for me please dont put this into your thing and expect it to work each persons input varies)

### Day 8

For more context, view the problem [here](https://adventofcode.com/2025/day/8)

This problem involves connecting junction boxes in 3D space using a graph algorithm approach. The goal is to understand circuit formation by connecting the closest pairs of junction boxes.

#### Part 1: Finding Circuit Sizes After Limited Connections

**Problem:** You have 1000 junction boxes scattered in 3D space. Connect the 1000 closest pairs together (by straight-line distance) and determine the resulting circuit structure.

**Key Concepts:**
- Junction boxes connected by light strings form circuits
- Electricity flows between connected boxes, creating connected components
- After 1000 connections, multiple separate circuits exist

**Approach:**
1. **Parse Input:** Read all junction box coordinates (x, y, z)
2. **Generate All Edges:** Create edges between every pair of boxes with their squared distance
3. **Sort by Distance:** Order edges from shortest to longest
4. **Union-Find (DSU):** Use Disjoint Set Union to track which boxes are connected
5. **Connect 1000 Pairs:** Unite the closest 1000 pairs
6. **Count Components:** Find all separate circuits and their sizes

**Algorithm Details:**
```cpp
// Calculate squared distance (avoids sqrt for efficiency)
long long dist2(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}

// Connect first 1000 pairs
DSU dsu(n);
for (int i = 0; i < 1000; i++) {
    dsu.unite(edges[i].u, edges[i].v);
}

// Collect circuit sizes and multiply top 3
```

**Answer: 50760** (product of the 3 largest circuit sizes: 47 × 36 × 30)

#### Part 2: Connecting Everything Into One Circuit

**Problem:** Continue connecting the closest unconnected pairs until all junction boxes form a single circuit. Find the product of the X coordinates of the last two junction boxes you connect.

**Key Insight:** This is essentially building a Minimum Spanning Tree (MST) until all nodes are connected.

**Approach:**
1. Start fresh with a new DSU
2. Connect pairs in order of distance (same sorted edge list)
3. Skip pairs already in the same component
4. Track the last connection made
5. Stop when `component_size == total_nodes`

**Why Track X Coordinates?**
The problem asks for the product of X coordinates of the last connection because the Elves need to know how far those junction boxes are from the wall to pick the right extension cable.

**Optimization:**
Instead of checking all nodes each iteration, we can check if the root component size equals n:
```cpp
if (dsu.size[dsu.find(0)] == n) {
    // All connected!
    return points[lastU].x * points[lastV].x;
}
```

**Answer: 3206508875**

**Time Complexity:**
- Generating edges: O(n²) where n = 1000
- Sorting edges: O(n² log n)
- Union-Find operations: Nearly O(1) with path compression
- Overall: O(n² log n)

### Day 9

For more context, view the problem [here](https://adventofcode.com/2025/day/9)

A set of red tiles forms an orthogonal loop; green tiles are the straight segments between consecutive red tiles and everything inside the loop. Rectangles must use two red tiles as opposite corners. All other tiles in the rectangle must be red or green.

#### Part 1: Largest Rectangle on Grid

- Read all red points (496) and brute force all pairs as opposite corners.
- Use inclusive area `(dx+1)*(dy+1)` because grid cells include both corner tiles.
- Track the maximum area.

#### Part 2: Largest Rectangle Inside Red/Green Region

- Build polygon edges from the red path (wraparound) - edges are axis-aligned.
- Point-in-polygon with boundary using ray casting; boundary counts as inside.
- A rectangle is valid if all four corners are inside/on the polygon and no polygon edge crosses the rectangle’s interior (checked per vertical/horizontal edge against rectangle span).
- Enumerate all red point pairs with different x and y (opposite corners), validate the rectangle, compute inclusive area `(dx+1)*(dy+1)`, and keep the max.