#include <iostream>
#include <deque>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        // current array stored in deque
        deque<int> dq;
        // flag: false means dq is in the same order as the logical array,
        // true means the logical order is the reverse of dq.
        bool reversed = false;
 
        // Maintained values: sum (∑ b_i) and R (rizziness = ∑ b_i * i)
        long long sum = 0;
        long long R = 0;
 
        // Process each operation.
        while(q--){
            int s;
            cin >> s;
            if(s == 3){
                // Append operation; next input is k.
                int k;
                cin >> k;
                // New length after appending:
                int m = dq.size();
                // The appended element will take index m+1.
                // Thus, new rizziness R' = R + k*(m+1).
                R += (long long)k * (m + 1);
                sum += k;
                // Append in the logical order.
                if(!reversed){
                    dq.push_back(k);
                } else {
                    // If reversed, logical order is reverse(dq),
                    // so the logical end corresponds to the front of dq.
                    dq.push_front(k);
                }
                cout << R << "\n";
            }
            else if(s == 1){
                // Cyclic shift: move last element to front.
                int m = dq.size();
                if(m == 0){
                    cout << 0 << "\n";
                    continue;
                }
                int x; // the element to be moved from end to front.
                if(!reversed){
                    // Logical order is same as dq, so last = dq.back().
                    x = dq.back();
                    dq.pop_back();
                    dq.push_front(x);
                } else {
                    // Logical order is reverse of dq, so last = dq.front().
                    x = dq.front();
                    dq.pop_front();
                    dq.push_back(x);
                }
                // Update rizziness.
                // The formula: new_R = R + sum - m*x.
                R = R + sum - (long long)m * x;
                // sum remains unchanged.
                cout << R << "\n";
            }
            else if(s == 2){
                // Reverse the array.
                int m = dq.size();
                // new_R = (m+1)*sum - R.
                R = (long long)(m + 1)*sum - R;
                // Toggle the reversed flag.
                reversed = !reversed;
                cout << R << "\n";
            }
        }
    }
    return 0;
}