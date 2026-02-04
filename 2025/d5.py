def main():
    with open("2025/d5_sample.txt", "r") as f:
        ranges, ids = [], []
        for line in f:
            nums = line.strip().split("-")
            if len(nums) == 2:
                ranges.append([int(nums[0]), int(nums[1])])
            else:
                try:
                    ids.append(int(nums[0]))
                except ValueError:
                    pass

    sorted_ranges = sorted(ranges, key=lambda x: x[0])
    sorted_id = sorted(ids)
    
    # part 1
    merged_ranges = []
    for start, end in sorted_ranges:
        if not merged_ranges or merged_ranges[-1][1] < start - 1:
            merged_ranges.append([start, end])
        else:
            merged_ranges[-1][1] = max(merged_ranges[-1][1], end)
    
    count = 0
    id_idx = 0
    for start, end in merged_ranges:
        while id_idx < len(sorted_id) and sorted_id[id_idx] <= end:
            if sorted_id[id_idx] >= start:
                count += 1
            id_idx += 1
            
    print("Fresh IDs:", count)
    
    # part 2
    count = 0
    for start, end in merged_ranges:
        count += (end - start + 1)
    
    print("Fresh IDs in range:", count)

if __name__ == "__main__":
    main()