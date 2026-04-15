#include <iostream>
using namespace std;

static char S1[1005][1005];
static char S2[1005][1005];
static bool used[1005][1005]; // (x,z)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int Z=0; Z<T; Z++){
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];

        string jugs_cave_image = "ok";

        // ---------- ������ ----------
        long long maxVol = 0;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++)
                if (S1[i][j] == '#') cnt++;
            maxVol += 1LL * cnt * N;
        }

        // ---------- ��С��� ----------

        long long minVol = 0;

        for (int y = 0; y < N; y++) {
            // �ռ� x �� z
            int xs[1005], zs[1005];
            int cx = 0, cz = 0;

            for (int x = 0; x < N; x++)
                if (S1[x][y] == '#') xs[cx++] = x;

            for (int z = 0; z < N; z++)
                if (S2[y][z] == '#') zs[cz++] = z;

            // ������������ (x,z)
            int i = 0, j = 0;

            // ��ƥ��δ�õ�
            for (int xi = 0; xi < cx; xi++) {
                for (int zi = 0; zi < cz; zi++) {
                    int x = xs[xi], z = zs[zi];
                    if (!used[x][z]) {
                        used[x][z] = 1;
                        minVol++;
                        break;
                    }
                }
            }
        }

        cout << maxVol << " " << minVol << "\n";
    }

    return 0;
}
