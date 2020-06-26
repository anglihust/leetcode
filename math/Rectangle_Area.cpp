// if overlap, compare x and y coordinate to calculate overlap aera
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (D-B)*(C-A);
        long long area2 = (H-F)*(G-E);
        if(E>=C or F>=D or A>=G or B>=H) return area1+area2;
        int height = min(H,D)-max(B,F);
        int width = min(G,C) - max(A,E);
        return area1+area2-height*width;
    }
};
