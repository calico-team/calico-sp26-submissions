import sys
read = sys.stdin.readline

for data in range(int(read())):
    word1 = read().strip()
    word2 = read().strip()
    
    box = set()
    currect_location = len(word2) - 1
    
    for i in range(len(word1) - 1, -1, -1):
        if currect_location >= 0 and word1[i] == word2[currect_location]:
            box.add(i)
            currect_location -= 1
    
    final_output = []
    for i in range(len(word1)):
        if i in box:
            final_output.append(word1[i])
        else:
            final_output.append('#')
    
    print(''.join(final_output))