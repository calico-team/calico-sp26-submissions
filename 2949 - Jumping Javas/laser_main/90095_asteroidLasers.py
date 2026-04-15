def parseSpacedInts(inputLine):
    spacedStrings = inputLine.split()
    spacedInts = map(int, spacedStrings)
    return list(spacedInts)

def limit(num, minimum, maximum):
    difference = maximum-minimum
    while num>=maximum:
        num -= difference
    while num<minimum:
        num+=difference
    return num


#main code
for _ in range(int(input())):
    lineOne = parseSpacedInts(input())
    
    #input processing 
    numAsteroids = lineOne[0]
    gridXSize = lineOne[1]
    gridYSize = lineOne[2]
    yStep = lineOne[3]
    xStep = lineOne[4]
    
    asteroidCoords = []
    for _ in range(numAsteroids):
        asteroidCoords.append(  parseSpacedInts(input())  )
    
    #the actual algorithm
    currentLaserX = asteroidCoords[0][0]
    currentLaserY = asteroidCoords[0][1]
    
    while True:
        currentLaserX += xStep
        currentLaserY += yStep
        
        currentLaserX = limit(currentLaserX, 0, gridXSize)
        currentLaserY = limit(currentLaserY, 0, gridYSize)
        
        currentLaserCoords = [currentLaserX, currentLaserY]
        
        if currentLaserCoords in asteroidCoords:
            print(asteroidCoords.index( currentLaserCoords ))
            break
    
    
    
    
    
    
    
    
    
    
    
    