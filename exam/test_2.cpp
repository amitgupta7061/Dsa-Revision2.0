#include <bits/stdc++.h>
using namespace std;

// question -> a
class Library {
public:
    queue<int> q; 
    stack<int> st; 
    void returnBook(int bookId) {
        q.push(bookId);
    }
    
    void process() {
        if (q.size()) {
            st.push(q.front()); q.pop();
        }
    }
    
    void undo() {
        if (st.size()) {
            int book = st.top(); st.pop();
            
            queue<int> temp;
            temp.push(book);
            
            while (!q.empty()) {
                temp.push(q.front()); q.pop();
            }
            
            q = temp;
        }
    }
    
    void next() {
        if (q.size()) {
            cout << q.front() << endl;
        }
    }
};

// question -> b
int f(vector<vector<int>>& checkpoints, int supplies) {
    sort(checkpoints.begin(), checkpoints.end());
    priority_queue<int> pq;
    int  prev = 0, cnt = 0;

    for (auto &it : checkpoints) {
        int height = it[0], supply = it[1];
        supplies -= (height - prev);

        while (supplies < 0 && !pq.empty()) {
            supplies += pq.top(); pq.pop();
        }

        if (supplies < 0) break;

        cnt++;
        pq.push(supply);
        prev = height;
    }

    return cnt;
}

// question -> c
class TreeNode {
public:
    bool hasbroken;
    TreeNode* left;
    TreeNode* right;

    TreeNode(bool b) {
        hasbroken = b;
        left = right = NULL;
    }
};

bool dfs(TreeNode* root, int &cnt, int k) {
    if (!root) return true;
    if (root->hasbroken) {
        cnt++;
        if (cnt > k) return false;
    }
    if (!dfs(root->left, cnt, k)) return false;
    if (!dfs(root->right, cnt, k)) return false;
    return true;
}

bool canTransmit(TreeNode* root, int k) {
    int cnt = 0;
    return dfs(root, cnt, k);
}
int main() {
    
    // a
    Library dd;
    string opr;
    
    while (cin >> opr) {
        if (opr == "RETURN") {
            int bookId;
            cin >> bookId;
            dd.returnBook(bookId);
        }
        else if (opr == "PROCESS") dd.process();
        else if (opr == "UNDO") dd.undo();
        else if (opr == "NEXT") dd.next();
        else break;
    }

    // b
    vector<vector<int>> t1 = {{1,2},{3,1},{5,3},{7,1}};
    int s1 = 3;
    cout<<f(t1, s1)<<endl;

    vector<vector<int>> t2 = {{2,2},{4,1},{6,1},{9,10}};
    int s2 = 4;
    cout<<f(t2, s2)<<endl;

    vector<vector<int>> t3 = {{3,5},{4,1},{8,2},{9,1},{10,3}};
    int s3 = 2;
    cout<<f(t3, s3)<<endl;

    vector<vector<int>> t4 = {{1,1},{2,1},{3,1},{4,1},{5,1}};
    int s4 = 3;
    cout<<f(t4, s4)<<endl;

    vector<vector<int>> t5 = {{1,2},{2,2},{3,3},{4,4},{5,5}};
    int s5 = 1;
    cout<<f(t5, s5)<<endl;


    // c
    TreeNode* a = new TreeNode(false); 
    TreeNode* b = new TreeNode(true);
    TreeNode* c = new TreeNode(false);
    TreeNode* d = new TreeNode(false);

    a->left = b;
    a->right = c;
    b->left = d;

    int k;
    cin >> k;

    cout << canTransmit(a, k);

    return 0;
}