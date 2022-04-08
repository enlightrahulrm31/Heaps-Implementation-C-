#include<bits/stdc++.h>
using namespace std;
// Heap is complete binary tree 
// In deletion we always remove the top most element from the heap 
// 0 1 2 3 4 5 6 7 .. 
// Algorithm : 
// we will always add at the rightmost point and check with its parent
// ie child/2 if nums[child/2]<nums[child] then we will swap ..keep this process until we reach the 1st index
// Removing:
// while removing we will replace nums[1] with the last element 
// then check its left_par and right_par ..if they are maximum then we will swap accordingly
class MinHeap{
    public :
    static const int lim = 1e6;
    int nums[lim];
    int pointer = 0;
    MinHeap(){   // constructor 
        for(int i=0;i<=lim;i++){
            nums[i] = 0;
        }
        pointer = 1;
    }
    void add(int val){  // addding value to the heap 
        nums[pointer] = val;
        int child = pointer;
        while(child>1){
            int par = child/2;
            if(nums[par]>nums[child]){
                swap(nums[par],nums[child]);
            }
            else{
                break;
            }
            child = par;
        }
        pointer++;
    }
    int top(){
        return nums[1];
    }
    void remove(){
        pointer--;
        nums[1] = nums[pointer];
        int par = 1;
        while(par<=pointer){
            int left_child = par*2;
            int right_child = par*2+1;
            if(left_child<=pointer && right_child<=pointer){
                if(nums[left_child]<=nums[right_child]){
                    swap(nums[left_child],nums[par]);
                    par = left_child;
                }
                else if(nums[right_child]<=nums[left_child]){
                    swap(nums[right_child],nums[par]);
                    par = right_child;
                }
                else{
                    break;
                }
            }
            else if(left_child<=pointer){
                if(nums[left_child]<=nums[par]){
                    swap(nums[left_child],nums[par]);
                    par = left_child;
                }
                break;
            }
            else{
                break;
            }
        }
        pointer++;
    }
    void show(){
        for(int i=1;i<pointer;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
};
int main(){
    MinHeap heap = MinHeap();
    heap.add(4);
    heap.add(5);
    heap.add(1);
    heap.add(2);
    heap.add(3);
    heap.show();
    heap.remove();
    heap.show();
    return 0;
}




