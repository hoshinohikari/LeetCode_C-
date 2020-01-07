﻿// LeetCode_C++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <numeric>
#include <bitset>
using namespace std;

//1. Two Sum
/*std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}*/

//2. Add Two Numbers
/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return l1;
}*/

//7. Reverse Integer
/*int reverse(int x) {
    std::vector<char> y;
    std::stringstream ss;
    long long z = 0;
    long long t;
    ss << x;
    std::string s1 = ss.str();
    for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1[i] != '-') {
            y.push_back(s1[i]);
        }
    }
    for (int i = 0; i < y.size(); i++) {
        t = y[i] - '0';
        for (int j = 1; j < y.size() - i; j++) {
            t = t * 10;
            //std::cout << "测试第" << i << "个t:" << t << std::endl;
        }
        z = z + t;
        //std::cout << "测试z:" << z << std::endl;
        if (z > 2147483647 || z < -2147483648) {
            z = 0;
            return int(z);
        }
    }
    if (s1[0] == '-') {
        z = 0 - z;
    }
    return int(z);
}*/

//9. Palindrome Number
/*bool isPalindrome(int x) {
    bool o = true;
    std::stringstream ss;
    ss << x;
    std::string s1 = ss.str();
    std::cout << s1 << std::endl;
    for (int i = 0; i < s1.size() / 2; i++) {
        if (s1[i] == s1[s1.size() - i - 1]) {
            std::cout << s1[i] << "    " << s1[s1.size() - i];
        }
        else {
            o = false;
            return o;
        }
    }
    return o;
}*/

//13. Roman to Integer
/*int romanToInt(std::string s) {
    int result = 0;
    int pre = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case 'I': cur = 1; break;
        case 'V': cur = 5; break;
        case 'X': cur = 10; break;
        case 'L': cur = 50; break;
        case 'C': cur = 100; break;
        case 'D': cur = 500; break;
        case 'M': cur = 1000; break;
        }
        if (cur <= pre) {
            result = result + cur;
        }
        else {
            result = result + cur - 2 * pre;
        }
        pre = cur;
    }
    return result;
}*/

//14. Longest Common Prefix
/*string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
        return "";
    }
    char s = strs[0][0];
    int less = strs[0].size();
    vector<char> com;
    string lastdata;
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() < less) {
            less = strs[i].size();
        }
    }
    for (int i = 0; i < less; i++) {
        for (int j = 0; j < strs.size(); j++) {
            if (strs[j][i] != s) {
                lastdata = accumulate(com.begin(), com.end(), lastdata);
                return lastdata;
            }
        }
        com.push_back(s);
        s = strs[0][i + 1];
    }
    lastdata = accumulate(com.begin(), com.end(), lastdata);
    return lastdata;
}*/

//20. Valid Parentheses
/*bool isValid(string s) {
    if (s.empty())
        return true;
    vector<char> tamp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            tamp.push_back(s[i]);
        else {
            if (tamp.empty())
                return false;
            else if (s[i] - 1 == tamp[tamp.size() - 1] || s[i] - 2 == tamp[tamp.size() - 1])
                tamp.pop_back();
            else
                return false;
        }
    }
    if (tamp.empty())
        return true;
    else
        return false;
}*/

//21. Merge Two Sorted Lists
/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0), * first = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    if (l1 == NULL)
        head->next = l2;
    else if (l2 == NULL)
        head->next = l1;
    return first->next;
}*/

//26. Remove Duplicates from Sorted Array
/*int removeDuplicates(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int i = 0;
    while (i < nums.size() - 1) {
        if (nums[i] == nums[i + 1]) {
            nums.erase(nums.begin() + 1 + i);
        }
        else
            i++;
    }
    return nums.size();
}*/

//27. Remove Element
/*int removeElement(vector<int>& nums, int val) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] == val)
            nums.erase(nums.begin() + i);
        else
            i++;
    }
    return nums.size();
}*/

//28. Implement strStr()
/*int strStr(string haystack, string needle) {
    int j;
    if (needle == "")
        return 0;
    else {
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                j = 0;
                while (j < needle.size()) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                    j++;
                }
                cout << "j=" << j << endl;
                if (j == needle.size()){
                    return i;
                }
            }
        }
    }
    return -1;
}*/

//35. Search Insert Position
/*int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i])
            return i;
        else if (target < nums[i])
            return i;
    }
    return nums.size();
}*/

//38. Count and Say
/*string countAndSay(int n) {
    string pre = "1", mix = "1";
    char tap;
    int num = 1, sum = 1;
    for (int i = 1; i < n; i++) {
        mix = "";
        for (int j = 0; j < pre.size(); j++) {
            if (j == pre.size() - 1) {
                num = pre[j] - '0';
                tap = sum + '0';
                mix = mix + tap;
                tap = '0' + num;
                mix = mix + tap;
            }
            else {
                if (pre[j] == pre[j + 1]) {
                    num = pre[j] - '0';
                    sum++;
                }
                else {
                    num = pre[j] - '0';
                    tap = sum + '0';
                    mix = mix + tap;
                    tap = '0' + num;
                    mix = mix + tap;
                    sum = 1;
                }
            }
        }
        pre = mix;
        sum = 1;
    }
    return mix;
}*/

//53. Maximum Subarray
/*int maxSubArray(vector<int>& nums) {
    int max, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            if (i == 0 && j == 0)
                max = nums[j];
            sum = sum + nums[j];
            if (sum > max) 
                max = sum;
        }
        sum = 0;
    }
    return max;
}*/

//58. Length of Last Word
/*int lengthOfLastWord(string s) {
    int sum = 0;
    if (s == "")
        return 0;
    else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                sum++;
            else if (i < s.size() - 1) {
                if (s[i + 1] != ' ')
                    sum = 0;
            }
        }
    }
    return sum;
}*/

//66. Plus One
/*vector<int> plusOne(vector<int>& digits) {
    vector<int> res = digits;
    for (int i = 0; i < res.size(); i++) {
        if (res[res.size() - 1 - i] != 9) {
            res[res.size() - 1 - i] = res[res.size() - 1 - i] + 1;
            return res;
        }
        else {
            res[res.size() - 1 - i] = 0;
            if (i == res.size() - 1) {
                res.insert(res.begin(), 1);
                return res;
            }
        }
    }
    return res;
}*/

//67. Add Binary
/*string addBinary(string a, string b) {
    string c = "";
    int on = 0;
    int min = a.size() > b.size() ? b.size() : a.size();
    for (int i = 0; i < min; i++) {
        //std::cout << "a=" << a[a.size() - 1 - i] << " b=" << b[b.size() - 1 - i] << " on=" << on << endl;
        if (on == 0) {
            if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1') {
                c.insert(c.begin(), '0');
                on = 1;
            }
            else if (a[a.size() - 1 - i] == '1' || b[b.size() - 1 - i] == '1') {
                c.insert(c.begin(), '1');
                on = 0;
            }
            else {
                c.insert(c.begin(), '0');
                on = 0;
            }
        }
        else {
            if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1') {
                c.insert(c.begin(), '1');
                on = 1;
            }
            else if (a[a.size() - 1 - i] == '1' || b[b.size() - 1 - i] == '1') {
                c.insert(c.begin(), '0');
                on = 1;
            }
            else {
                c.insert(c.begin(), '1');
                on = 0;
            }
        }
        //cout << "c=" << c << endl;
    }
    int max = a.size() > b.size() ? a.size() : b.size();
    string tam;
    if (a.size() > b.size())
        tam = a;
    else if (a.size() < b.size())
        tam = b;
    else {
        if (on == 0)
            return c;
        else {
            c.insert(c.begin(), '1');
            return c;
        }
    }
    //cout << "tam=" << tam << endl;
    for (int i = min; i < max; i++) {
        //std::cout << "i=" << i << " tam=" << tam[tam.size() - 1 - i] << " on=" << on << endl;
        if (on == 0) {
            if (tam[tam.size() - 1 - i] == '1') {
                c.insert(c.begin(), '1');
                on = 0;
            }
            else {
                c.insert(c.begin(), '0');
                on = 0;
            }
        }
        else {
            if (tam[tam.size() - 1 - i] == '1') {
                c.insert(c.begin(), '0');
                on = 1;
            }
            else {
                c.insert(c.begin(), '1');
                on = 0;
            }
        }
        //cout << "c=" << c << endl;
    }
    if (on == 1)
        c.insert(c.begin(), '1');
    return c;
}*/

//69. Sqrt(x)
/*int mySqrt(int x) {
    int i = 1;
    while (true) {
        if (i * i > x)
            return i - 1;
        else if (i * i == x)
            return i;
        else
            i++;
    }
}*/

//70. Climbing Stairs
int climbStairs(int n) {
    for (int i = 0; i < n / 2 + 1; i++) {

    }
}

//

int main()
{
    int tap = 0;
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    /*for (int i = 0; i < plusOne(nums).size(); i++) {
        std::cout << plusOne(nums)[i];
    }*/
    //std::cout << mySqrt(4);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件