#include <bits/stdc++.h>
using namespace std;

// A point P is mycelium iff 7 * L1(P, M) < 2 * L1(P, G)
// L1(P, M) = |px - mx| + |py - my|
// We need to count integer points satisfying this.
//
// Transform to rotated coordinates: u = x+y, v = x-y
// L1(P, Q) = max(|pu-qu|, |pv-qv|) ... no wait
// Actually in rotated coords L1 becomes L_inf:
// |x1-x2| + |y1-y2| = max(|(x1+y1)-(x2+y2)|, |(x1-y1)-(x2-y2)|)
// No that's L_inf. So L1 in original = L_inf in rotated coords.
//
// Let's work directly. Shift so M is origin.
// Let dx = Gx - Mx, dy = Gy - My
// Condition: 7*(|x|+|y|) < 2*(|x-dx|+|y-dy|)
//
// The boundary is 7*(|x|+|y|) = 2*(|x-dx|+|y-dy|)
// This defines a convex polygon in L1 metric.
//
// In each of the 4 quadrants of x,y signs and 4 quadrants of (x-dx),(y-dy) signs,
// the L1 norms linearize and we get a linear inequality.
// The region is an octagon (intersection of halfplanes).
//
// Strategy: In rotated coords u=x+y, v=x-y,
// |x|+|y| = max(|u|,|v|) ... no.
// |x|+|y| in terms of u,v: x=(u+v)/2, y=(u-v)/2
// |x|+|y| = |(u+v)/2| + |(u-v)/2|
// This equals max(|u|,|v|) only sometimes... 
// Actually |(a+b)/2|+|(a-b)/2| = max(|a|,|b|). Yes!
// So |x|+|y| = max(|u|,|v|) where u=x+y, v=x-y
// 
// So in rotated coords:
// 7*max(|u|,|v|) < 2*max(|u-du|,|v-dv|)
// where du = dx+dy, dv = dx-dy
//
// This is L_inf distance! So the problem becomes:
// Count integer (x,y) such that 7*Linf((u,v),(0,0)) < 2*Linf((u,v),(du,dv))
// where u=x+y, v=x-y, du=dx+dy, dv=dx-dy
//
// But (u,v) takes only values with u+v even (since u=x+y,v=x-y => u+v=2x, always even)
// So we count (u,v) with u≡v (mod 2) satisfying the condition, then that's our answer.
//
// The region 7*Linf(P,O) < 2*Linf(P,D) in L_inf metric:
// Let's denote the L_inf "ball" of radius r around center C as the square [Cx-r,Cx+r]x[Cy-r,Cy+r]
// 
// Condition: 7*max(|u|,|v|) < 2*max(|u-du|,|v-dv|)
// Equivalently: Linf distance to origin * 7 < Linf distance to D * 2
// This is an Apollonius set for L_inf metric.
//
// The L_inf Apollonius set {P : Linf(P,A)/Linf(P,B) < k} is a convex region.
// For L_inf it decomposes into cases based on which quadrant of A and B we're in.
//
// Let me just enumerate: the condition in each of the regions defined by
// sign of u, sign of v, sign of u-du, sign of v-dv gives 16 linear regions.
// In each, the condition becomes a linear inequality, giving a convex polygon.
// I'll compute the vertices of this polygon and count interior lattice points.
//
// For large coords, counting lattice points in a convex polygon:
// We can iterate over each row (u value) and count valid v range.
// But u can be up to ~10^9, so need O(vertices) formula.
//
// The polygon has O(1) vertices (at most 8 for an L_inf Apollonius set).
// Count lattice points using Pick's theorem or direct row summation by iterating
// over the O(1) edge segments... but rows can be 10^9.
//
// For a convex polygon with integer vertices, we can count lattice points exactly
// using the formula: sum over each row of (floor(right) - ceil(left) + 1)
// grouped into O(V) linear segments => O(V) total computation.
//
// Let me implement this approach.

typedef long long ll;
typedef __int128 lll;

// Count integers in [lo, hi]
ll countRange(ll lo, ll hi) {
    if (lo > hi) return 0;
    return hi - lo + 1;
}

// For a convex polygon given as vertices in order,
// count lattice points strictly inside or on boundary
// using horizontal scanline over integer y-values.
// The polygon can have large coordinates but O(1) edges.
// We process each edge and for each integer y in its y-range,
// track left/right x bounds.

// But y range can be huge. We need to sum over linear segments.
// Each edge contributes a range of y values with x = ay/b + c (rational).
// Sum of floor(ay/b + c) - ceil(a'y/b' + c') + 1 over y in [y1,y2]
// = sum of floor linear function - ceil linear function
// This can be computed with floor sum formulas.

// floor_sum(a, b, c, n) = sum_{i=0}^{n} floor((a*i + b) / c)
// Using the standard algorithm (similar to Euclidean algorithm)
lll floor_sum(lll a, lll b, lll c, lll n) {
    // sum_{i=0}^{n} floor((a*i + b) / c), c > 0
    if (n < 0) return 0;
    lll res = 0;
    if (a < 0) {
        // floor((a*i+b)/c) = -ceil((-a*i-b)/c) = -(floor((-a*i-b-1)/c)+1) if not divisible
        // Easier: adjust
        // f(i) = floor((a*i+b)/c)
        // Let a' = (-a), b' = (-b)
        // floor((a*i+b)/c) = -floor((a'*i+b')/c) - (((a'*i+b') % c != 0) ? 1 : 0)
        // = -floor((a'*i+b')/c) - 1 + (((a'*i+b') % c == 0) ? 1 : 0)
        // This gets complicated. Let's use: floor(x/c) for negative...
        // Alternative: shift to make a >= 0
        // sum floor((a*i+b)/c) = sum floor(-((-a)*i+(-b))/c)
        //   = sum (-ceil(((-a)*i+(-b))/c))
        //   = -sum ceil(((-a)*i+(-b))/c)
        //   = -sum (floor(((-a)*i+(-b)-1)/c) + 1)   [if c doesn't divide...]
        // Actually ceil(x/c) = floor((x+c-1)/c) = floor((x-1)/c)+1
        // ceil((A*i+B)/c) = floor((A*i+B+c-1)/c)
        // So sum floor((a*i+b)/c) where a<0:
        // = -sum floor(((-a)*i+(-b)+c-1)/c)
        lll A = -a, B = -b + c - 1;
        return -(floor_sum(A, B, c, n) + 0); // wait need to redo
        // Actually let me just do: 
        // = -floor_sum(-a, -b+c-1, c, n)
        // Hmm but -b+c-1 might make b' large. Let me just handle it.
    }
    // a >= 0 now
    res += (a / c) * (n * (n + 1) / 2);
    a %= c;
    res += (b / c) * (n + 1);
    b %= c;
    if (a == 0) return res;
    lll m = (a * n + b) / c;
    res += m * n - floor_sum(c, c - b - 1, a, m - 1);
    return res;
}

// Hmm this is getting complicated. Let me think of a cleaner approach.
// 
// Actually for this problem, let me reconsider the structure.
// 
// After rotation, we need to count (u,v) with u≡v mod 2 where
// 7*max(|u|,|v|) < 2*max(|u-du|,|v-dv|)
//
// The region {(u,v) : 7*max(|u|,|v|) < 2*max(|u-du|,|v-dv|)} 
// is bounded (since as ||(u,v)|| -> inf, left side grows faster unless direction
// exactly toward origin... actually 7 > 2 so left grows faster, meaning 
// far from origin the condition fails. So this is a BOUNDED region. Good.
//
// The region is an intersection of conditions. Let me think about what 
// max(|u-du|, |v-dv|) > (7/2)*max(|u|,|v|) means.
// 
// Let r = max(|u|,|v|) (L_inf distance from origin).
// Let s = max(|u-du|,|v-dv|) (L_inf distance from D=(du,dv)).
// Condition: 7r < 2s, i.e., s > 3.5r.
// 
// For fixed r, s must be large. The point (u,v) must be close to origin 
// but far from D. This makes sense when D is not too close to origin.
//
// The region is a convex polygon. Let me find its vertices by solving the 
// boundary equations in each piece.
//
// The boundary is 7*max(|u|,|v|) = 2*max(|u-du|,|v-dv|)
// Breaking into cases for signs of u, v, u-du, v-dv:
// In each case both max functions linearize.
// 
// The boundary pieces come from:
// 7*|u| = 2*|u-du| and 7*|v| <= 2*|v-dv| => max is u-side
// 7*|v| = 2*|v-dv| and 7*|u| <= 2*|v-dv| => max is v-side  (tricky)
// etc.
// 
// Actually max(A,B)=max(C,D) boundary: either A=C>=B,D or A=D>=B,C or B=C>=A,D or B=D>=A,C
// This has many cases. Let me just compute the polygon vertices numerically.
//
// For the Bonus 3 test set (coords up to 4e8), du,dv up to ~8e8.
// The polygon fits in a bounding box of size O(du+dv) so O(1e9).
// Need O(1) or O(sqrt) counting... 
//
// Actually the key insight for large coords: the polygon has O(1) edges (at most 8).
// For a convex polygon with rational vertices, counting lattice points can be done
// in O(E * log) time where E is number of edges, using the floor_sum trick.
//
// Let me implement this properly.

// I'll represent the convex polygon as a list of edges, each being a line segment
// between two rational points (p/q form), and for each integer y in [ymin, ymax],
// compute the x range and sum up.
// For large y ranges with linear x bounds, use arithmetic series.

// Let me restart with a cleaner implementation.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<ll,ll> pll; // rational: first/second

// We work in (u,v) space where u=x+y, v=x-y (rotated coords)
// Count (u,v) with u≡v (mod 2) satisfying 7*max(|u|,|v|) < 2*max(|u-du|,|v-dv|)

// The condition defines a convex polygon. Find its vertices.
// Boundary: 7*max(|u|,|v|) = 2*max(|u-du|,|v-dv|)
// 
// Let f(u,v) = 7*max(|u|,|v|) - 2*max(|u-du|,|v-dv|) < 0
//
// The polygon is convex. Its edges lie on lines of the form:
// 7*eps1*u = 2*eps2*(u-du), with |u|>=|v| and |u-du|>=|v-dv|, eps1,eps2 in {-1,1}
// => (7*eps1 - 2*eps2)*u = -2*eps2*du => u = -2*eps2*du/(7*eps1-2*eps2)
// 7*eps1*u = 2*eps2*(v-dv), with |u|>=|v| and |v-dv|>=|u-du|
// etc.
// 
// There are 4 choices for (eps1,eps2) and 4 combinations of which max-arg dominates,
// giving at most 8 candidate edge-defining lines.
// The actual polygon vertices are intersections of consecutive such lines within their valid regions.
//
// This is getting complex. For a competition, let me think if there's a simpler characterization.

// SIMPLER APPROACH: Direct simulation for small coords, math for large.
// For Bonus 3, coords up to 4e8, Manhattan distance up to ~8e8.
// Simulation is impossible.
//
// Let me think about the shape of the mycelium region more carefully.
// 
// In original (x,y) coords:
// Mycelium tile at P = (px, py) iff 7*L1(P,M) < 2*L1(P,G)
// where L1 = Manhattan distance.
// 
// Shift: let p = P - M, g = G - M = (dx, dy)
// Condition: 7*L1(p, 0) < 2*L1(p, g)
// 7*(|px|+|py|) < 2*(|px-dx|+|py-dy|)
//
// This defines a convex region in p-space (intersection of halfplanes).
// In each orthant (signs of px, py, px-dx, py-dy fixed), it's a linear inequality.
// 
// The boundary lines are:
// 7*(±px ± py) = 2*(±(px-dx) ± (py-dy))
// Expanding: (7a - 2b)*px + (7c - 2d)*py = 2*(b*dx + d*dy)
// where a,c ∈ {±1} (signs of px,py), b,d ∈ {±1} (signs of px-dx,py-dy)
// 
// For each combination, we get a line. There are 16 combinations but many are redundant.
// The convex polygon is bounded by at most 8 lines (one per octant).
// 
// Let me enumerate:
// For the boundary 7*(|px|+|py|) = 2*(|px-dx|+|py-dy|):
// In octant where px>0,py>0,px>dx,py>dy: 7(px+py) = 2(px-dx+py-dy) => 5(px+py) = -2(dx+dy) -- may not have solutions
// 
// The 8 distinct boundary lines come from the 8 ways to combine signs:
// sign(px) * sign(px-dx) ∈ {++, +-, -+, --} and same for y, giving 4x4=16 but 
// the max|px|,|py| selects one of the two px,py terms and max|px-dx|,|py-dy| selects one,
// giving 2x2=4 "active" pairs, but with 4 quadrant choices for (px,py) signs = 8 cases for px alone vs py... 
// 
// I think the cleanest implementation: compute the convex polygon vertices,
// then count lattice points using the standard algorithm.

// Let me just code the full solution:
// 1. Find all vertices of the convex polygon boundary.
// 2. Count lattice points (with parity constraint) inside.

// For step 2 with large polygons: iterate over integer values of one coordinate,
// use floor/ceil of the other. But range can be 1e9.
// Need arithmetic: for each edge of the polygon (linear in the scan direction),
// the sum is an arithmetic series or uses floor_sum.

// Let me implement floor_sum and the polygon lattice point counter.