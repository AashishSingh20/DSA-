#include<iostream>
using namespace std;

bool checkEqual(int a[26], int b[26]){  // This is created to check whether the two arrays are equal or not
    for(int i=0;i<26;i++){
        if(a[i] != b[i]){   // If not equal then return false
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){

    // Character count array
    int count1[26] = {0};  // Initially count1 array mein 0 elements hai yeh s1 ke liye hai
    for(int i=0;i<s1.length();i++){
        int index = s1[i] - 'a';  // If i has a then ->  a - a = 0(index)  yah 0 se 1 kardo
        count1[index]++;   // If any element is fount increase it's index count2(Eg: s1 = ab ) so count1 = [1,1,0,0,.....0]
    }

    int i = 0;    // This is use to traverse s2 string
    int windowSize = s1.length();   // window size matlab kitne elements of ek sath compare karna hai (Eg: s1 = ab,  s2 = eidbaoo  here ab is 2 so 2 2 karke check karo I) 1&2, II) 2&3 and so on

    int count2[26] = {0};  // Initially count2 array mein 0 elements hai yeh s2 ke liye hai
    while(i< windowSize && i<s2.length()){  // if i is small then window size and i is smaller then s2 length then run this loop
        int index =s2[i] - 'a';  // Same work as in s1
        count2[index]++;  // If any element is found increase it's index count2(Eg: s2 = eidbaoo) for 1st 2(ei) => so count2 = [0,0,0,0,1,0,0,0,1.....0]
        i++;  // It keep track of where comparison is going on(Eg: s1 = ab, s2= eidbaoo) at i=0 -> s2[0] = e =>e-a=4, count2[4]++, and so on it will stop at i=2 as i==windowSize
    }

    if(checkEqual(count1, count2)){   // After peforming previous operation it check whether count1 has same frequency as count2,  in above example count1 and count 2 are not equal so move to the next operation
        return true;
    }

    while(i<s2.length()){
        char newChar = s2[i];  // newChar is 'd'
        int index = newChar - 'a';  // 'd' - 'a' = 3 -> Therefore increment by 1 at 'd' (3rd index)
        count2[index]++;    //count2[3]++;

        char oldChar = s2[i-windowSize];  // i=2, windowSize = 2 -> s2[0] ='e'
        index = oldChar - 'a';  // 'e' - 'a' = 4  // Remove e from window  (new window:- 'id')
        count2[index]--;  // count2[4]--;

        i++;   // i becomes 3

        if (checkEqual(count1,count2)){  // check again(Acc to eg: count1 => a:1, b:1  and count2 => d:1, i:1) again loop
            return true;
        }
    }
    return false;   // If every window is false then return false;
}

int main(){
    string s1;
    cout<<"Enter a string 1: ";
    cin>>s1;
    string s2;
    cout<<"Enter string 2: ";
    cin>>s2;

    if(checkInclusion(s1,s2)){
        cout<<"Yes, Permutation Exists!";
    }
    else{
        cout<<"No, Permutation does not exist!";
    }
}