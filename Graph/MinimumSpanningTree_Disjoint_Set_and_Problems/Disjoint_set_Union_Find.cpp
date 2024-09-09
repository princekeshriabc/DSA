// Disjoint set (Union-Find)
// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find

int find(int A[], int X)
{
    // add code here
    if (X == A[X])
        return X;
    return A[X] = find(A, A[X]);
}
void unionSet(int A[], int X, int Z)
{
    // add code here.
    int upx = find(A, X);
    int upz = find(A, Z);
    if (upx == upz)
        return;
    A[upx] = upz;
}