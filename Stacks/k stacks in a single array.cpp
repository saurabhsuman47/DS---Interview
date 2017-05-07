#include <bits/stdc++.h>
using namespace std;

class kStacks{
	private:
		int *next, *top, *arr;
		int free;
        
	public:
        kStacks(int n = 100, int  k = 50){
            arr = new int[n];
            next = new int[n];
            top = new int[k];
            for(int i = 0; i < n-1; i++){
                next[i] = i + 1;                
            }
            next[n-1] = -1;
            for(int i = 1; i <= k; i++){                
                top[i] = -1;
            }
            free = 0;            
        }
        
		void push(int x, int sn){
			if(!full()){                
                int curr_top = top[sn]; // store current top in a var
                top[sn] = free; //update top of sn stack
                arr[free] = x; //store in the free loc
                int temp = free;
                free = next[free]; //update free to next free loc
                next[temp] = curr_top; // store previous top in next arr
            }
		}
        
        int pop(int sn){            
            if(!empty(sn)){
                int curr_top = top[sn];
                top[sn] = next[curr_top];//update top to previous
                next[curr_top] = free; // update next of the vacant location to free
                free = curr_top; // make the current loc free                
                return arr[curr_top];
            }
            else return -1;
        }
        
        bool empty(int sn){
            if(top[sn] == -1)return true;
            return false;
        }
        
        bool full(){
            if(free == -1)return true;
            return false;
        }
        
};

//driver program for testing
int main(){
    kStacks k_stack(100, 50);
    k_stack.push(11, 1);
    k_stack.push(12, 1);
    cout<<k_stack.pop(1)<<endl;
    k_stack.push(21, 2);
    k_stack.push(13, 1);
    cout<<k_stack.pop(2)<<endl;
    cout<<k_stack.pop(1)<<endl;
}

