def main():
        
    # get input
    with open("2025/d4_input.txt", "r") as f:
        grid = []
        for line in f:
            grid.append(list(line.strip()))
        
    rows, cols = len(grid), len(grid[0])
    
    def check_adjacent(r,c):
        # check the adjacent position
        count = 0
        for x in range(-1,2):
            for y in range(-1,2):
                if x == 0 and y == 0: continue
                nr, nc = r + x, c + y
                # check boundary
                if 0 <= nr < rows and 0 <= nc < cols:
                    if grid[nr][nc] == '@':
                        count += 1
        if count < 4:
            return True
        return False

    # part 1
    total = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] != '@': continue
            if check_adjacent(r,c):
                total += 1
    print(f"Part 1: {total}")
    
    ## part 2
    # Repeat checking the grid
    def check_grid(grid_copy):
        count_per_iter = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] != '@': continue
                if check_adjacent(r,c):
                    count_per_iter += 1
                    grid_copy[r][c] = '.'
        return grid_copy, count_per_iter
    
    total = 0
    while(True):
        grid_copy = [_row[:] for _row in grid]
        grid, count_per_iter = check_grid(grid_copy)
        
        if count_per_iter == 0:
            break
        else:
            total += count_per_iter
        
    print(f"Part 2: {total}")


    
        

    
if __name__ == "__main__":
    main()