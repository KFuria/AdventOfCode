def main():
    with open("2025/d1_input.txt","r") as f:
        dial = list(map(int,f.read().replace('R','').replace('L','-').split()))
    
    # part 1
    count = 0
    x = 50
    for turn in dial:
        x += turn
        if x % 100 == 0:
            count += 1
    print(f'part 1: {count}')
    
    # part 2
    count = 0
    x = 50
    for turn in dial:
        count += abs(turn) // 100
        s = -1 if turn < 0 else 1
        rem = s * (abs(turn) % 100)
        x += rem
        if x >= 100 or (x <= 0 and x != rem):
            count += 1
        x %= 100
    print(f'part 2: {count}')

    print(count)
if __name__ == "__main__":
    main()
                