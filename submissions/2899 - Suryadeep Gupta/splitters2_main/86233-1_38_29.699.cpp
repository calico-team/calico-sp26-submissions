#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void destroy_the_tiles() {
    int T;
    cin >> T;
    
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        
        // We'll build a factory that produces P/(2^A * 3^B)
        // Strategy: Create P parallel paths, each producing 1/(2^A * 3^B)
        
        // First, determine the size needed
        int width = P + 2; // For the splitter network
        int height = A + B + 2;
        
        // But we need to ensure total tiles <= 2000
        // Let's use a more efficient layout
        
        // Better approach: Build a binary/ternary tree
        // Each splitter splits into 2 or 3 branches
        
        vector<string> factory;
        
        // First row: input from top-left
        string first_row(P + 1, '>');
        first_row += 'X'; // Destroy tile to catch excess if any
        factory.push_back(first_row);
        
        // For each of the P copies, create the splitting network
        for (int copy = 0; copy < P; copy++) {
            // Start from position (1, copy)
            // Create A splitters for powers of 2
            for (int a = 0; a < A; a++) {
                string row(P + 1, '.');
                row[copy] = 'S';
                factory.push_back(row);
                // The next row will need to handle the split
                string next_row(P + 1, '.');
                // Split into 2 directions
                if (copy < P - 1) {
                    next_row[copy] = '>';
                    next_row[copy + 1] = '<';
                } else {
                    next_row[copy] = '>';
                    next_row[0] = '<';
                }
                factory.push_back(next_row);
            }
            
            // Create B splitters for powers of 3
            for (int b = 0; b < B; b++) {
                string row(P + 1, '.');
                row[copy] = 'S';
                factory.push_back(row);
                string next_row(P + 1, '.');
                // Split into 3 directions
                if (copy < P - 2) {
                    next_row[copy] = '>';
                    next_row[copy + 1] = '>';
                    next_row[copy + 2] = '<';
                } else if (copy == P - 2) {
                    next_row[copy] = '>';
                    next_row[copy + 1] = '>';
                    next_row[0] = '<';
                } else if (copy == P - 1) {
                    next_row[copy] = '>';
                    next_row[0] = '>';
                    next_row[1] = '<';
                }
                factory.push_back(next_row);
            }
        }
        
        // Add collection row
        string last_row(P + 1, 'X');
        factory.push_back(last_row);
        
        // Output the factory
        int N = factory.size();
        int M = P + 1;
        
        cout << N << " " << M << endl;
        for (const string& row : factory) {
            cout << row << endl;
        }
    }
}

void read_your_input() {
    destroy_the_tiles();
}

int main() {
    read_your_input();
    return 0;
}