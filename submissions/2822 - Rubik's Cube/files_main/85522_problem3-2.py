def main():
    times = int(input())
    for i in range(times):
        # print(program())
        final = program()
        for i in final:
            print(i)
def program():
    strA = input() #input
    strB = input() #target
    final = ""
    finalarray = []
    currentchar = 0
    # for i in range(len(strA)-1): # loop over A
    #     if currentchar > len(strB)-1:
    #         final += "#"
    #     elif strA[i] == strB[currentchar]:
    #         final += strA[i]
    #         currentchar += 1
    #     else:
    #         final += "#"
    for char in list(strA):
        # print("currentchar: " + strB[currentchar])
        if currentchar > len(strB)-1:
            final += "#"
        elif strB[currentchar] == char and currentchar <= len(strB)-1:
            final+= char
            currentchar += 1
            # print("kept")
        else:
            # print("not kept because " + strB[currentchar] + " != " + char + " or " + str(currentchar) + " less than " + str(len(strB)-1))
            final += "#"
        # print("looped over char: " + char)
        # print("--")
    # return final
    finalarray.append(final)
    return finalarray
main()