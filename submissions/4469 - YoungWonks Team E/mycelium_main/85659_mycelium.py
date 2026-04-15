first_input = int(input())

for a in range(first_input):
    second_input = list(map(int,input().split(' ')))

    grass = [[second_input[0],second_input[1]]]
    mycelium = [[second_input[2],second_input[3]]]

    counter = 1
    grass_border_index = 0
    mycelium_border_index = 0

    total_mycelium = 1

    while True:

        counter += 1

        if counter%2 == 0:

            new_grass_border_index = len(grass)

            for grass_block in grass[grass_border_index::]:

                if [ grass_block[0]+1,grass_block[1] ] not in grass+mycelium:
                    grass.append([ grass_block[0]+1,grass_block[1] ])

                if [ grass_block[0]-1,grass_block[1] ] not in grass+mycelium:
                    grass.append([ grass_block[0]-1,grass_block[1] ])

                if [ grass_block[0],grass_block[1]+1 ] not in grass+mycelium:
                    grass.append([ grass_block[0],grass_block[1]+1 ])

                if [ grass_block[0],grass_block[1]-1 ] not in grass+mycelium:
                    grass.append([ grass_block[0],grass_block[1]-1 ])
            
            grass_border_index = new_grass_border_index

            # print('grass:',grass[grass_border_index::])


        if counter%7 == 0:
            added = False

            new_mycelium_border_index = len(mycelium)

            for mycelium_block in mycelium[mycelium_border_index::]:

                if [ mycelium_block[0]+1,mycelium_block[1] ] not in mycelium+grass:
                    added = True
                    mycelium.append([ mycelium_block[0]+1,mycelium_block[1] ])
                    total_mycelium += 1

                if [ mycelium_block[0]-1,mycelium_block[1] ] not in mycelium+grass:
                    added = True
                    mycelium.append([ mycelium_block[0]-1,mycelium_block[1] ])
                    total_mycelium += 1

                if [ mycelium_block[0],mycelium_block[1]+1 ] not in mycelium+grass:
                    added = True
                    mycelium.append([ mycelium_block[0],mycelium_block[1]+1 ])
                    total_mycelium += 1

                if [ mycelium_block[0],mycelium_block[1]-1 ] not in mycelium+grass:
                    added = True
                    mycelium.append([ mycelium_block[0],mycelium_block[1]-1 ])
                    total_mycelium += 1
            
            mycelium_border_index = new_mycelium_border_index
        
            if added == False:
                break

            # print('mycelium:',mycelium[mycelium_border_index::])
    
    print(total_mycelium)