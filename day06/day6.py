from functools import reduce

raw = [line.rstrip() for line in open("day06/input.txt")]
irawi = raw[-1]
symbols = [s for s in raw[-1].split(" ") if s]
raw = raw[:-1]

ncount = len([i for i in raw[0].split(" ") if i])
rows = [[int(i) for i in line.split(" ") if i] for line in raw]

part1 = 0
for i in range(ncount):
    op = symbols[i]
    part1 += reduce(lambda a, b: a * b if op == "*" else a + b, (row[i] for row in rows))

print("part 1:", part1)

test = """
123 328  51 64
 45 64  387 23
  6 98  215 314
*   +   *   +  """[1:]

raw_test = test.split("\n")
irawi_test = raw_test[-1]
symbols_test = [s for s in raw_test[-1].split(" ") if s]
raw_test = raw_test[:-1]
ncount_test = len([i for i in raw_test[0].split(" ") if i])
rows_test = [[int(i) for i in line.split(" ") if i] for line in raw_test]

symindexes = []
for i, char in enumerate(irawi):
    if char != " ":
        symindexes.append(i)
symindexes.append(len(raw[0]))

newnums = []
for row in raw:
    prev = 0
    newnumsub = []
    for index in symindexes[1:]:
        newnumsub.append(row[prev:index if index == len(raw[0]) else index - 1])
        prev = index
    newnums.append(newnumsub)

part2 = 0
for i in range(ncount):
    numpad = [row[i] for row in newnums]
    longest = max(len(n) for n in numpad)
    nums = []
    for p in range(longest):
        nums.append(int("".join([n[p] for n in numpad if len(n) > p])))
    part2 += reduce(lambda a, b: a * b if symbols[i] == "*" else a + b, nums)

print("part 2:", part2)
