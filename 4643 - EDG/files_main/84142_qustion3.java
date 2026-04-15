public static String solve(String original, String target) {
    char[] strArr = original.toCharArray();
    int matchPos = 0;

    for (int i = 0; i < strArr.length && matchPos < target.length(); i++) {
        if (strArr[i] == target.charAt(matchPos)) {
            matchPos++;
        } else {
            strArr[i] = '#';
        }
    }

    for (int i = 0; i < strArr.length; i++) {
        boolean needKeep = false;
        int tempPos = 0;
        for (int j = 0; j <= i && tempPos < target.length(); j++) {
            if (original.charAt(j) == target.charAt(tempPos)) {
                tempPos++;
                if (j == i) {
                    needKeep = true;
                }
            }
        }
        if (!needKeep) {
            strArr[i] = '#';
        }
    }

    return new String(strArr);
}