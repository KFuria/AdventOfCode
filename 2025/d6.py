def main():
    with open("2025/d6_input.txt", "r") as f:
        data = [line for line in f]
        
    # part 1
    # parse data
    data1 = [d.strip().split() for d in data]
    nums = [[int(i) for i in d] for d in data1[:-1]]
    cols = list(zip(*nums))
    signs = data1[-1]
    total = 0
    for i, sign in enumerate(signs):
        if sign == "+":
            list_total = sum(cols[i])
            total += list_total
        elif sign == "*":
            list_total = 1
            for num in cols[i]:
                list_total *= num
            total += list_total
    
    print("Part 1 Total sum:", total)
    
    # part 2
    # parse data
    data2 = [[c for c in d.strip('\n')] for d in data]
    signs2 = data2[-1]
    cols = list(zip(*data2[:-1]))
    
    col_idx = len(signs2) - 1
    nums = []
    total2 = 0
    while col_idx >= 0:
        n = ''.join(cols[col_idx]).strip()
        if n is not '':
            nums.append(int(n))
        
        if signs2[col_idx] == '+':
            total2 += sum(nums)
            nums.clear()
        elif signs2[col_idx] == '*':
            list_total = 1
            for num in nums:
                list_total *= num
            total2 += list_total
            nums.clear()
        col_idx -= 1
    
    print("Part 2 total sum: ", total2) 
            
if __name__ == "__main__":
    main()