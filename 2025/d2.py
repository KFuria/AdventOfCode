def main():
    with open("2025/d2_input.txt", "r") as f:
        pairs = list(f.read().split(","))

    count1 = 0
    count2 = 0
    for pair in pairs:
        left,right = pair.split("-")
        for i in range(int(left),int(right)+1,1):
            # part 1
            count1 += check_repeat(i)
            
            # part 2
            count2 += check_repeat_2(i)

    print(count1,count2)

               
def check_repeat(number):
    s = str(number)
    n = len(s)
    if n == 0 or n % 2 != 0:
        return 0
    half = n // 2
    # check if both halfs are same
    if s[:half] == s[half:]:
        return number
    else:
        return 0
    
def check_repeat_2(number):
    s = str(number)
    n = len(s)
    # repeating sequence length can go from 1 to half
    for repeat_len in range(1,n //2 + 1):
        # for each substring, check if it number is just repeated substring
        seq = s[:repeat_len]
        if seq * (n // repeat_len) == s:
            return number
    return 0
        
if __name__ == "__main__":
    main()