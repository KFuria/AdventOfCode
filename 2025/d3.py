def main():
    with open("2025/d3_input.txt", "r") as f:
        batts = list(f.read().split())
    
    # part 1
    count = 0
    for batt in batts:
        n = len(batt)
        nums = list(map(int,batt))
        num1 = max(nums[:-1])
        num2 = max(nums[nums.index(num1)+1:])
        count += (num1*10 + num2)
    
    print(count)
        
    # part 2
    count = 0
    for batt in batts:
        n = len(batt)
        nums = list(map(int,batt))
        start = 0
        jolt = 0
        for i in range(1,12+1):
            sub = nums[start:n-(12-i)]
            max_num = max(sub)
            jolt = jolt * 10 + max_num
            start += sub.index(max_num)+1
        count += jolt
    print(count)
        
if __name__ == "__main__":
    main()