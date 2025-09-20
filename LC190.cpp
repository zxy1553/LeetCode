#include<iostream>
#include <cstdint>

class Solution{

    private:
    void swap_bits(uint32_t *num, int i, int j){
        int bit_i = (*num >> i) & 1; 
        int bit_j = (*num >> j) & 1;

        if(bit_i != bit_j){
            *num ^= (1<<i) | (1<<j);
        }
    }

    uint32_t reverse(uint32_t n){
        int total_bits = sizeof(n)*8;

        for(int i=0; i<total_bits/2; ++i){
            swap_bits(&n, i, total_bits-1-i);
        }
        return n;
    }


    public:
    int reverseBits(int n){
        return reverse(n);
    }
};