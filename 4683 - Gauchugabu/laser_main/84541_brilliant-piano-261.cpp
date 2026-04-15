// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

int main() {
    int t, k, n, m, p, q, x, y, coord_x, coord_y;
    std::vector<std::vector<int>> coords;
    std::vector<int> start_coords;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        coords = {};
        std::cin >> k >> n >> m >> p >> q;
        for (int j = 0; j < k; j++) {
            std::cin >> x >> y;
            coords.push_back({x, y});
        }

        coord_x = coords[0][0];
        coord_y = coords[0][1];

        coord_x += q;
        coord_y += p;

        start_coords = {coord_x, coord_y};


        while (std::find(coords.begin(), coords.end(), start_coords) == coords.end()) {
            coord_x += q;
            coord_y += p;

            if (coord_x >= n) {
                coord_x -= n;
            }
            if (coord_y >= m) {
                coord_y -= m;
            }

            start_coords = {coord_x, coord_y};
        }
        
        std::cout << std::distance(coords.begin(), std::find(coords.begin(), coords.end(), start_coords)) << "\n";

    }


}
