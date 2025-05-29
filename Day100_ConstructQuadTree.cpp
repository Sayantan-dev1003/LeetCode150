/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
private:
    Node* build(const vector<vector<int>>& grid, int row, int col, int size) {
        bool isAllSame = true;
        int firstVal = grid[row][col];

        for (int i = row; i < row + size; ++i) {
            for (int j = col; j < col + size; ++j) {
                if (grid[i][j] != firstVal) {
                    isAllSame = false;
                    break;
                }
            }
            if (!isAllSame)
                break;
        }

        if (isAllSame) {
            return new Node(firstVal == 1, true);
        }

        int newSize = size / 2;
        Node* topLeft = build(grid, row, col, newSize);
        Node* topRight = build(grid, row, col + newSize, newSize);
        Node* bottomLeft = build(grid, row + newSize, col, newSize);
        Node* bottomRight = build(grid, row + newSize, col + newSize, newSize);

        return new Node(true, false, topLeft, topRight, bottomLeft,
                        bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
