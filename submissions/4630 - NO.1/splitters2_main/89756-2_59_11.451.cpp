#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void add_continuous_path(vector<string>& grid, int start_r, int start_c, char direction, int length, const string& end_type = "") {
    int rows = grid.size();
    int cols = grid[0].size();
    int dr = 0, dc = 0;

    if (direction == '>') dc = 1;
    else if (direction == '<') dc = -1;
    else if (direction == '^') dr = -1;
    else if (direction == 'v') dr = 1;

    int current_r = start_r;
    int current_c = start_c;

    for (int i = 0; i < length; ++i) {
        if (current_r >= 0 && current_r < rows && current_c >= 0 && current_c < cols) {
            grid[current_r][current_c] = direction;
        }
        current_r += dr;
        current_c += dc;
    }

    if (end_type == "collect") {
        if (direction == '>') {
            while (current_c < cols) {
                grid[current_r][current_c] = '>';
                current_c++;
            }
        }
        else if (direction == '^') {
            while (current_r >= 0) {
                grid[current_r][current_c] = '^';
                current_r--;
            }
        }
    }
    else if (end_type == "destroy") {
        if (current_r >= 0 && current_r < rows && current_c >= 0 && current_c < cols) {
            grid[current_r][current_c] = 'X';
        }
    }
    else if (end_type == "s") {
        if (current_r >= 0 && current_r < rows && current_c >= 0 && current_c < cols) {
            grid[current_r][current_c] = 'S';
        }
    }
}

pair<vector<string>, pair<int, int>> build_factory(int P, int A, int B) {
    long long total = 1LL * pow(2, A) * pow(3, B); 
    
    if (P == 0) return { {"X"}, {1, 1} };
    if (P == total) return { {">"}, {1, 1} };

    vector<vector<int>> split_plan;

    int remaining_P = P;
    long long current_total = total;

    for (int i = 0; i < A; ++i) {
        long long single_part = current_total / 2;
        int branch_flow = 2; 
        int branch_other = (remaining_P >= single_part) ? 1 : 0;
        if (branch_other == 1) remaining_P -= single_part;

        split_plan.push_back({ 0, branch_flow, branch_other, (int)single_part }); 
        current_total = single_part;
    }

    for (int i = 0; i < B; ++i) {
        long long single_part = current_total / 3;
        int branch_flow = 2; 
        int branch1 = (remaining_P >= single_part) ? 1 : 0;
        if (branch1 == 1) remaining_P -= single_part;
        int branch2 = (remaining_P >= single_part) ? 1 : 0;
        if (branch2 == 1) remaining_P -= single_part;

        split_plan.push_back({ 1, branch_flow, branch1, branch2, (int)single_part }); 
        current_total = single_part;
    }

    int split_count = split_plan.size();
    int rows = 5;

    int cols = split_count * 4 + 8;
    vector<string> grid(rows, string(cols, '.'));


    add_continuous_path(grid, 0, 0, '>', 3);
    add_continuous_path(grid, 0, 3, 'v', 2); 
    grid[2][2] = 'v'; 
    grid[3][2] = 'S'; 

    vector<pair<int, int>> split_positions;
    int curr_r = 3;
    int curr_c = 2;

    for (int i = 0; i < split_count; ++i) {
        split_positions.push_back({ curr_r, curr_c });
        grid[curr_r][curr_c] = 'S';
        curr_r--;      
        curr_c += 3;  
    }

    for (int idx = 0; idx < split_count; ++idx) {
        int r = split_positions[idx].first;
        int c = split_positions[idx].second;
        auto& info = split_plan[idx];
        int type = info[0]; 

        if (type == 0) { 
            int branch_flow = info[1];
            int branch_other = info[2];

          
            add_continuous_path(grid, r, c - 1, '<', 2);

           
            if (branch_other == 1) {
               
                add_continuous_path(grid, r, c + 1, '>', 1);
                add_continuous_path(grid, r, c + 2, '>', cols - (c + 2), "collect");
            }
            else {
               
                add_continuous_path(grid, r, c + 1, '>', 3, "destroy");
            }

        }
        else { 
            int branch_flow = info[1];
            int branch1 = info[2]; 
            int branch2 = info[3]; 

            add_continuous_path(grid, r, c - 1, '<', 2);

            if (branch1 == 1) {
                add_continuous_path(grid, r, c + 1, '>', 1);
                add_continuous_path(grid, r, c + 2, '>', cols - (c + 2), "collect");
            }
            else {
                add_continuous_path(grid, r, c + 1, '>', 3, "destroy");
            }

        
            if (branch2 == 1) {
                add_continuous_path(grid, r - 1, c, '^', 2); 
               
                add_continuous_path(grid, r - 3, c + 1, '>', cols - (c + 1), "collect");
            }
            else {
                add_continuous_path(grid, r - 1, c, '^', 2);
                add_continuous_path(grid, r - 3, c + 1, '>', 3, "destroy");
            }
        }
    }
    if (!split_positions.empty()) {
        int final_r = split_positions.back().first;
        int final_c = split_positions.back().second;

        add_continuous_path(grid, final_r, final_c + 1, '>', cols - (final_c + 1), "collect");

      
        add_continuous_path(grid, final_r - 1, final_c, '^', final_r, "destroy");
    }

    int max_used_col = 0;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (grid[i][j] != '.') {
                max_used_col = max(max_used_col, j);
            }
        }
    }

    vector<string> result;
    for (int i = 0; i < rows; ++i) {
        result.push_back(grid[i].substr(0, max_used_col + 1));
    }

    return { result, {rows, max_used_col + 1} };
}

int main() {
    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;

        auto result = build_factory(P, A, B);
        vector<string> grid = result.first;
        int N = result.second.first;
        int M = result.second.second;

        cout << N << " " << M << endl;
        for (const string& row : grid) {
            cout << row << endl;
        }
    }
    return 0;
}