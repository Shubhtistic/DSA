    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <map>
    using namespace std;
    // in this we have to find valid anagram
    // the given stringgs will be anagram if they all their letters are same independant of suquence
    // and their occurence should also be same

    // an easy way is to sort both strings and then compare directly in a loop
    // the default sort function does sorting lexographically

    // T.C -> O(nlogn) + O(nlogn) + O(n) = O(nlogn) .... we consider the largest
    // T.C -> O(nlogn)
    // S.C -> O(log(n))+O(log(n)) = O(logn)

    bool easy_method(string t, string s)
    {
        // we could taken the strings by ref but the c++ sort function does in place sorting
        // so we pass by value to avoid changing the original strings

        if (t.size() != s.size())
        {
            return false;
            // edge case
            // early exit
        }

        sort(t.begin(), t.end()); // T.C -> O(nlogn)
        sort(s.begin(), s.end()); // T.C -> O(nlogn)

        // by default in ascending order

        // we just simply comapre the strings now
        // T.C -> O(n) .... wost case
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != s[i])
            {
                return false;
            }
        }
        return true;
    }

    // lets try to optimiz theis method
    // why do w even need to sort the strings if we can drectly store their count
    // for example an hash map which store letters and keys and their occurence as values
    // 1st approach store all letters from each string and if they even it means both have same occurence for that letter
    // but this fails when both the words have all distinct elemnets
    // example s=aa and t=bb both counts will be zero and function will return true (WRONG!!)

    // an simple method is we can store the occurences of first string letters and subtract for others so this way the elements which are presnt in both will be
    bool optimal_method(string &temp, string &temp2)
    {
        map<char, int> counter;
        // map each char to int

        if (temp.size() != temp2.size())
        {
            return false;
        }
        for(auto item:temp){
            counter[item]+=1;
        }
         for(auto item:temp2){
            counter[item]-=1;
        }

        for (auto [key, value] : counter)
        {
            if (value != 0)
            {
                return false;
            }
        }

        return true;
    }

    int main()
    {
        string s = "anagram";
        string t = "nagaram";
        if (easy_method(s, t))
        {
            cout << "Valid anagram\n";
        }
        if (optimal_method(s, t))
        {
            cout << "Valid anagram\n";
        }
        return 0;
    }