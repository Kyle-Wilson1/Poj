#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct SegmentTree {
    long long left, right, total, childrenExtra;
    SegmentTree *lson, *rson;
};

long long regionLength(SegmentTree *tree) {
    return tree->right - tree->left + 1;
}

SegmentTree *buildTree(vector<long long> &num, long long l, long long r) {
    if (l > r) {
        return NULL;
    }
    if (l == r) {
        SegmentTree *root = new SegmentTree;
        root->left = l;
        root->right = r;
        root->total = num[l];
        root->childrenExtra = 0;
        root->lson = NULL;
        root->rson = NULL;
        return root;
    }
    SegmentTree *root = new SegmentTree;
    root->left = l;
    root->right = r;
    root->total = num[l];
    root->childrenExtra = 0;
    long long mid = (l + r) >> 1;
    root->lson = buildTree(num, l, mid);
    root->rson = buildTree(num, mid + 1, r);
    root->total = root->lson->total + root->rson->total;
    return root;
}

void addRegion(SegmentTree *root, long long regionLeft, long long regionRight, long long addNum) {
    if (root == NULL || root->right < regionLeft || root->left > regionRight) {
        return;
    }
    if (root->left >= regionLeft && root->right <= regionRight) {
        root->total += addNum * regionLength(root);
        if (root->left < root->right)root->childrenExtra += addNum;
        return;
    }
    if (root->lson != NULL && root->rson != NULL) {
        root->lson->total += root->childrenExtra * regionLength(root->lson);
        root->lson->childrenExtra += root->childrenExtra;
        root->rson->total += root->childrenExtra * regionLength(root->rson);
        root->rson->childrenExtra += root->childrenExtra;
        root->childrenExtra = 0;
    }
    addRegion(root->lson, regionLeft, regionRight, addNum);
    addRegion(root->rson, regionLeft, regionRight, addNum);
    root->total = root->lson->total + root->rson->total;
}

void queryRegion(SegmentTree *root, long long regionLeft, long long regionRight, long long &sum) {
    if (root == NULL || root->right < regionLeft || root->left > regionRight) {
        return;
    }
    if (root->left >= regionLeft && root->right <= regionRight) {
        sum += root->total;
        return;
    }
    if (root->lson != NULL && root->rson != NULL && root->childrenExtra != 0) {
        root->lson->total += root->childrenExtra * regionLength(root->lson);
        root->lson->childrenExtra += root->childrenExtra;
        root->rson->total += root->childrenExtra * regionLength(root->rson);
        root->rson->childrenExtra += root->childrenExtra;
        root->childrenExtra = 0;
    }
    queryRegion(root->lson, regionLeft, regionRight, sum);
    queryRegion(root->rson, regionLeft, regionRight, sum);
}

void deleteMem(SegmentTree *root) {
    if (root == NULL)
        return;
    deleteMem(root->lson);
    deleteMem(root->rson);
    delete root;
};

void printTree(ofstream &fout, SegmentTree *root) {
    if (root == NULL)return;
    fout << "left=" << root->left << "right=" << root->right
         << "total=" << root->total << "extra=" << root->childrenExtra << endl;
    printTree(fout, root->lson);
    printTree(fout, root->rson);
}

int main() {

    long long n, q, i, a, b, c;
    char type[2];
    SegmentTree *root;

    scanf("%lld%lld", &n, &q);

    vector<long long> num(n, 0);

    for (i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }

    n--;
    root = buildTree(num, 0, n);

    for (i = 0; i < q; i++) {
        scanf("%s", type);
        if (type[0] == 'C') {
            scanf("%lld%lld%lld", &a, &b, &c);
            addRegion(root, a - 1, b - 1, c);
        } else {
            scanf("%lld%lld", &a, &b);
            long long sum = 0;
            queryRegion(root, a - 1, b - 1, sum);
            printf("%lld\n", sum);
        }
    }

    return 0;
}