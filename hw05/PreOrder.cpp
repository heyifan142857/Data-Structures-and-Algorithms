#include <iostream>
#include <vector>

using namespace std;

int last_in_post_order(vector<int>& preOrder, vector<int>& inOrder, vector<int>& postOrder, int first, int last){
    if(first > last) return -1;
    int max_in_in_order_index = -1;
    int max_in_post_order_index = -1;
    for (int j = first; j <= last; j++)
    {
        for (int i = 0; i < postOrder.size(); i++)
        {
            if(postOrder[i] == inOrder[j]){
                if(max_in_post_order_index < i){
                    max_in_post_order_index = i;
                    max_in_in_order_index = j;
                }
                break;
            }
        }
    }

    return max_in_in_order_index;
    
}

void _preOrder(vector<int>& preOrder, vector<int>& inOrder, vector<int>& postOrder, int first, int last) {
    if(first > last) return;
    int last_in_post_order_index = last_in_post_order(preOrder, inOrder, postOrder, first, last);
    preOrder.push_back(inOrder[last_in_post_order_index]);
    _preOrder(preOrder, inOrder, postOrder, first, last_in_post_order_index-1);
    _preOrder(preOrder, inOrder, postOrder, last_in_post_order_index+1, last);
}


int main() {
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;

    vector<int> input;
    int n;
    while(cin >> n){
        input.push_back(n);
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if(i < input.size()/2){
            inOrder.push_back(input[i]);
        }else{
            postOrder.push_back(input[i]);
        }
    }

    _preOrder(preOrder, inOrder, postOrder, 0, inOrder.size()-1);

    for (size_t i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }
    cout << endl;

    return 0;
}