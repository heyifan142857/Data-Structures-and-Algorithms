#include <iostream>
#include <functional>
#include <vector>
#include <math.h>

struct Node{
    int value;
    Node* next;

    Node(int value):value(value),next(nullptr){};
};

class Hashset{
    int capacity;
    std::vector<int> set;

    public:
    Hashset(int capacity):capacity(capacity){set.resize(capacity,-1);};
    
    const float A = (std::sqrt(5) - 1) / 2;

    int hash(int value) {
        float x = value * A;
        return static_cast<int>(capacity * (x - std::floor(x))); 
    }

    void insert(int value){
        int index = hash(value);
        int i = 1;
        while(set[index]!=-1){
            if(set[index] == value){
                return;
            }
            index = (index + i * i) % capacity;
            i++;
        }
        set[index] = value;
        printf("%d ", value);
    };
};

int main(){
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {   
        int n;
        std::cin>>n;
        Hashset hashset(100591);
        for (int j = 0; j < n; j++)
        {
            int val;
            std::scanf("%d", &val);
            hashset.insert(val);
        }
        std::printf("\n");
    }
    

    return 0;
}