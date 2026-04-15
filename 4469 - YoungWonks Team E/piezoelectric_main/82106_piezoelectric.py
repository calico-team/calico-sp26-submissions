first_input = int(input())

for a in range(first_input):
    
    the_input = list(map(int,input().split(' ')))
    perimeter = 2*(the_input[0]+the_input[1])
    needed = the_input[2]
    step_efficiency = the_input[3]
    
    print(needed//(perimeter*step_efficiency))