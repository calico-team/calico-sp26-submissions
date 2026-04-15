//
//  main.cpp
//  CALICO
//
//  Created by Max Shi on 4/11/26.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int numInputs;
    std::cin >> numInputs;
    for (int i = 0; i < numInputs; i++) {
        double L, W, E, R;
        std::cin >> L >> W >> E >> R;
        
        std::cout << (int) std::ceil(E/((2*L+2*W)*R));
    }

    return EXIT_SUCCESS;
}
