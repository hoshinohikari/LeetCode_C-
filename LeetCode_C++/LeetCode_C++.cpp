#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <map>
using namespace std;

//1. Two Sum
/*std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> res;
	for (decltype(nums.size()) i = 0; i < nums.size(); i++)
	{
		for (decltype(nums.size()) j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
			}
		}
	}
	return res;
}*/

//2. Add Two Numbers
/*struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr)
	{
	}

	ListNode(int x) : val(x), next(nullptr)
	{
	}

	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* p = new ListNode(-1);
	ListNode* q = p;
	int carry = 0;
	while (l1 || l2)
	{
		int val1 = l1 ? l1->val : 0; //为空时做加法的位数为0
		int val2 = l2 ? l2->val : 0;

		int val3 = val1 + val2 + carry;
		if (val3 >= 10)
		{
			val3 = val3 - 10;
			carry = 1;
		}
		else
			carry = 0;
		q->next = new ListNode(val3); //创建新节点
		q = q->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2; //当l1和l2为null时不取其next指针，一直让其保持空的状态
	}
	if (carry == 1) //考虑最高位进位的情况
		q->next = new ListNode(1);
	return p->next;
}*/

//3. Longest Substring Without Repeating Characters
/*int lengthOfLongestSubstring(string s)
{
	if (s == "")
		return 0;
	std::string t = "";
	int cs = 0, mx = 1;
	decltype(s.length()) j;
	t = t + s[0];
	for (decltype(s.length()) i = 0; i < s.length() - 1; i++)
	{
		for (j = 0; j < t.length(); j++)
		{
			if (s[i + 1] == t[j])
			{
				cs = 1;
				break;
			}
		}
		if (cs)
		{
			mx = std::max(mx, int(t.length()));
			t.erase(0, j + 1);
			t = t + s[i + 1];
			cs = 0;
		}
		else
		{
			t = t + s[i + 1];
		}
	}

	return std::max(mx, int(t.length()));
}*/

//5. Longest Palindromic Substring(Time Limit Exceeded)
/*string longestPalindrome(string s)
{
	if (s.length() <= 1)
		return s;
	string a, r;
	for (decltype(s.length()) i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			r = s.substr(i, 2);
			for (int j = 1; i - j >= 0 && i + 1 + j < s.length(); j++)
			{
				if (s[i - j] != s[i + 1 + j])
					break;
				r = s.substr(i - j, 2 * j + 2);
			}
			if (a.length() < r.length())
				a = r;
		}
		if (i > 0)
		{
			r = s.substr(i, 1);
			for (int j = 0; i - j - 1 >= 0 && i + 1 + j < s.length(); j++)
			{
				if (s[i - j - 1] != s[i + 1 + j])
					break;
				r = s[i - j - 1] + r;
				r = r + s[i + 1 + j];
				r = s.substr(i - j - 1, 2 * j + 3);
			}
			if (a.length() < r.length())
				a = r;
		}
	}
	if (a.length() > r.length())
		r = a;
	if (r == "")
		r = s[0];
	return r;
}*/

//6. ZigZag Conversion
/*string convert(string s, int numRows)
{
	if (s == "" || numRows <= 1)
		return s;
	int m;
	int x = 0, y = 0;
	bool f = false;
	string fin;
	if (numRows == 2)
	{
		vector<vector<char>> array(numRows);
		if (s.length() % 2)
			m = static_cast<int>(s.length()) / 2 + 1;
		else
			m = static_cast<int>(s.length()) / 2;
		for (int i = 0; i < numRows; i++)
		{
			array[i].resize(m);
		}
		for (decltype(array.size()) i = 0; i < array.size(); i++)
		{
			for (decltype(array.size()) j = 0; j < array[0].size(); j++)
			{
				array[i][j] = ' ';
			}
		}
		for (decltype(s.length()) i = 0; i < s.length(); i++)
		{
			if (x >= 2)
			{
				x = 0;
				y = y + 1;
			}
			array[x][y] = s[i];
			x++;
		}
		for (decltype(array.size()) i = 0; i < array.size(); i++)
		{
			for (decltype(array[0].size()) j = 0; j < array[0].size(); j++)
			{
				if (array[i][j] != ' ')
					fin = fin + array[i][j];
			}
		}
		return fin;
	}

	if (s.length() % (2 * static_cast<unsigned long long>(numRows) - 2) == 0)
		m = static_cast<int>(s.length()) / (2 * static_cast<int>(numRows) - 2) * (static_cast<int>(numRows) - 1);
	else if (static_cast<int>(s.length()) % (2 * static_cast<int>(numRows) - 2) <= numRows)
		m = static_cast<int>(s.length()) / (2 * static_cast<int>(numRows) - 2) * (static_cast<int>(numRows) - 1) + 1;
	else
		m = static_cast<int>(s.length()) / (2 * static_cast<int>(numRows) - 2) * (static_cast<int>(numRows) - 1) + (
			static_cast<int>(s.length()) - static_cast<int>(s.length()) / (2 * static_cast<int>(numRows) - 2) * (2 *
				static_cast<int>(numRows) - 2) - numRows) + 1;

	vector<vector<char>> array(numRows);
	for (int i = 0; i < numRows; i++)
	{
		array[i].resize(m);
	}

	for (decltype(array.size()) i = 0; i < array.size(); i++)
	{
		for (decltype(array[0].size()) j = 0; j < array[0].size(); j++)
		{
			array[i][j] = ' ';
		}
	}

	for (decltype(s.length()) i = 0; i < s.length(); i++)
	{
		if (x >= numRows && f == false)
		{
			x = numRows - 2;
			y = y + 1;
			f = true;
		}
		if (f == false)
		{
			array[x][y] = s[i];
			x++;
		}
		if (f == true)
		{
			array[x][y] = s[i];
			x--;
			y++;
		}
		if (f == true && x == 0)
		{
			f = false;
		}
	}

	for (decltype(array.size()) i = 0; i < array.size(); i++)
	{
		for (decltype(array[0].size()) j = 0; j < array[0].size(); j++)
		{
			if (array[i][j] != ' ')
				fin = fin + array[i][j];
		}
	}

	return fin;
}*/

//7. Reverse Integer
/*int reverse(int x)
{
	std::vector<char> y;
	std::stringstream ss;
	long long z = 0;
	long long t;
	ss << x;
	std::string s1 = ss.str();
	for (int i = static_cast<int>(s1.size()) - 1; i >= 0; i--)
	{
		if (s1[i] != '-')
		{
			y.push_back(s1[i]);
		}
	}
	for (decltype(y.size()) i = 0; i < y.size(); i++)
	{
		t = y[i] - '0';
		for (decltype(y.size()) j = 1; j < y.size() - i; j++)
		{
			t = t * 10;
			//std::cout << "测试第" << i << "个t:" << t << std::endl;
		}
		z = z + t;
		//std::cout << "测试z:" << z << std::endl;
		if (z > 2147483647 || z < -2147483648)
		{
			z = 0;
			return int(z);
		}
	}
	if (s1[0] == '-')
	{
		z = 0 - z;
	}
	return int(z);
}*/

//8. String to Integer (atoi)
/*int myAtoi(string str)
{
	string t;
	for (decltype(str.length()) i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && t == "")
			continue;
		if (str[i] == '-' && t == "")
			t = "-";
		else if (str[i] >= '0' && str[i] <= '9')
			t = t + str[i];
		else
			break;
	}
	if (t == "")
		return 0;
	int i = std::stoi(t);
	return i;
}*/

//9. Palindrome Number
/*bool isPalindrome(int x)
{
	bool o = true;
	std::stringstream ss;
	ss << x;
	std::string s1 = ss.str();
	std::cout << s1 << std::endl;
	for (decltype(s1.size()) i = 0; i < s1.size() / 2; i++)
	{
		if (s1[i] == s1[s1.size() - i - 1])
		{
			std::cout << s1[i] << "    " << s1[s1.size() - i];
		}
		else
		{
			o = false;
			return o;
		}
	}
	return o;
}*/

//11. Container With Most Water
/*int maxArea(vector<int>& height)
{
	int l = 0, r = height.size() - 1;
	int ans = 0;
	while (l < r)
	{
		int area = min(height[l], height[r]) * (r - l);
		ans = max(ans, area);
		if (height[l] <= height[r])
			++l;
		else
			--r;
	}
	return ans;
}*/

//13. Roman to Integer
/*int romanToInt(std::string s)
{
	std::map<char, int> cur
	{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	int result = 0;
	int pre = 0;
	for (decltype(s.length()) i = 0; i < s.length(); i++)
	{
		if (cur[s[i]] <= pre)
		{
			result = result + cur[s[i]];
		}
		else
		{
			result = result + cur[s[i]] - 2 * pre;
		}
		pre = cur[s[i]];
	}
	return result;
}*/

//14. Longest Common Prefix
/*string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	char s = strs[0][0];
	int less = strs[0].size();
	vector<char> com;
	string lastdata;
	for (decltype(strs.size()) i = 0; i < strs.size(); i++)
	{
		if (static_cast<int>(strs[i].size()) < less)
		{
			less = strs[i].size();
		}
	}
	for (int i = 0; i < less; i++)
	{
		for (decltype(strs.size()) j = 0; j < strs.size(); j++)
		{
			if (strs[j][i] != s)
			{
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

//19. Remove Nth Node From End of List
/*struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr)
	{
	}

	ListNode(int x) : val(x), next(nullptr)
	{
	}

	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};

struct ListNode_shared
{
	int val;
	shared_ptr<ListNode_shared> next;

	ListNode_shared() : val(0), next(nullptr)
	{
	}

	ListNode_shared(int x) : val(x), next(nullptr)
	{
	}

	ListNode_shared(int x, shared_ptr<ListNode_shared> next) : val(x), next(next)
	{
	}
};

int getLength(ListNode* head)
{
	int length = 0;
	while (head)
	{
		++length;
		head = head->next;
	}
	return length;
}

int getLength_shared(shared_ptr<ListNode_shared> head)
{
	int length = 0;
	while (head)
	{
		++length;
		head = head->next;
	}
	return length;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* dummy = new ListNode(0, head);
	int length = getLength(head);
	ListNode* cur = dummy;
	for (int i = 1; i < length - n + 1; ++i)
	{
		cur = cur->next;
	}
	cur->next = cur->next->next;
	ListNode* ans = dummy->next;
	delete dummy;
	return ans;
}

shared_ptr<ListNode_shared> removeNthFromEnd_shared(shared_ptr<ListNode_shared> head, int n)
{
	shared_ptr<ListNode_shared> dummy(new ListNode_shared(0, head));
	int length = getLength_shared(head);
	shared_ptr<ListNode_shared> cur = dummy;
	for (int i = 2; i < length - n + 1; ++i)
	{
		cur = cur->next;
	}
	cur->next = cur->next->next;
	shared_ptr<ListNode_shared> ans = dummy->next;
	return ans;
}*/

//20. Valid Parentheses
/*bool isValid(string s)
{
	if (s.empty())
		return true;
	vector<char> tamp;
	for (decltype(s.size()) i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			tamp.push_back(s[i]);
		else
		{
			if (tamp.empty())
				return false;
			if (s[i] - 1 == tamp[tamp.size() - 1] || s[i] - 2 == tamp[tamp.size() - 1])
				tamp.pop_back();
			else
				return false;
		}
	}
	if (tamp.empty())
		return true;
	return false;
}*/

//21. Merge Two Sorted Lists
/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *head = new ListNode(0), *first = head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			head->next = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}
	if (l1 == nullptr)
		head->next = l2;
	else if (l2 == nullptr)
		head->next = l1;
	return first->next;
}*/

//26. Remove Duplicates from Sorted Array
/*int removeDuplicates(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	decltype(nums.size()) i = 0;
	while (i < nums.size() - 1)
	{
		if (nums[i] == nums[i + 1])
		{
			nums.erase(nums.begin() + 1 + i);
		}
		else
			i++;
	}
	return nums.size();
}*/

//27. Remove Element
/*int removeElement(vector<int>& nums, int val)
{
	decltype(nums.size()) i = 0;
	while (i < nums.size())
	{
		if (nums[i] == val)
			nums.erase(nums.begin() + i);
		else
			i++;
	}
	return nums.size();
}*/

//28. Implement strStr()
/*int strStr(string haystack, string needle)
{
	decltype(needle.size()) j;
	if (needle == "")
		return 0;
	for (decltype(haystack.size()) i = 0; i < haystack.size(); i++)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (j < needle.size())
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
				j++;
			}
			cout << "j=" << j << endl;
			if (j == needle.size())
			{
				return i;
			}
		}
	}
	return -1;
}*/

//35. Search Insert Position
/*int searchInsert(vector<int>& nums, int target)
{
	for (decltype(nums.size()) i = 0; i < nums.size(); i++)
	{
		if (target == nums[i])
			return i;
		if (target < nums[i])
			return i;
	}
	return nums.size();
}*/

//38. Count and Say
/*string countAndSay(int n)
{
	string pre = "1", mix = "1";
	char tap;
	int num, sum = 1;
	for (int i = 1; i < n; i++)
	{
		mix = "";
		for (decltype(pre.size()) j = 0; j < pre.size(); j++)
		{
			if (j == pre.size() - 1)
			{
				num = pre[j] - '0';
				tap = static_cast<char>(sum + '0');
				mix = mix + tap;
				tap = static_cast<char>('0' + num);
				mix = mix + tap;
			}
			else
			{
				if (pre[j] == pre[j + 1])
				{
					sum++;
				}
				else
				{
					num = pre[j] - '0';
					tap = static_cast<char>(sum + '0');
					mix = mix + tap;
					tap = static_cast<char>('0' + num);
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
/*int maxSubArray(vector<int>& nums)
{
	int max = 0, sum = 0;
	for (decltype(nums.size()) i = 0; i < nums.size(); i++)
	{
		for (decltype(nums.size()) j = i; j < nums.size(); j++)
		{
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
/*int lengthOfLastWord(string s)
{
	int sum = 0;
	if (s == "")
		return 0;
	for (decltype(s.size()) i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			sum++;
		else if (i < s.size() - 1)
		{
			if (s[i + 1] != ' ')
				sum = 0;
		}
	}
	return sum;
}*/

//62. Unique Paths
/*int uniquePaths(int m, int n)
{
	//int** dp = (int**)malloc(sizeof(int*) * n);
	//shared_ptr<int*> dp(new int* [n]);
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		//dp[i] = (int*)malloc(sizeof(int) * m);
		//dp.get()[i] = new int[m];
		dp[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[n - 1][m - 1];
}*/

//63. Unique Paths II
/*int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[m];
	}

	dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[n - 1][m - 1];
}*/

//64. Minimum Path Sum
/*int minPathSum(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid.at(0).size();
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
				dp[0][0] = grid[0][0];
			else if (i == 0)
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			else
				dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] + grid[i][j] : dp[i][j - 1] + grid[i][j];
				//dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}

	return dp[n - 1][m - 1];
}*/

//66. Plus One
/*vector<int> plusOne(vector<int>& digits)
{
	vector<int> res = digits;
	for (decltype(res.size()) i = 0; i < res.size(); i++)
	{
		if (res[res.size() - 1 - i] != 9)
		{
			res[res.size() - 1 - i] = res[res.size() - 1 - i] + 1;
			return res;
		}
		res[res.size() - 1 - i] = 0;
		if (i == res.size() - 1)
		{
			res.insert(res.begin(), 1);
			return res;
		}
	}
	return res;
}*/

//67. Add Binary
/*string addBinary(string a, string b)
{
	string c = "";
	int on = 0;
	int min = a.size() > b.size() ? b.size() : a.size();
	for (int i = 0; i < min; i++)
	{
		//std::cout << "a=" << a[a.size() - 1 - i] << " b=" << b[b.size() - 1 - i] << " on=" << on << endl;
		if (on == 0)
		{
			if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '0');
				on = 1;
			}
			else if (a[a.size() - 1 - i] == '1' || b[b.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '1');
				on = 0;
			}
			else
			{
				c.insert(c.begin(), '0');
				on = 0;
			}
		}
		else
		{
			if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '1');
				on = 1;
			}
			else if (a[a.size() - 1 - i] == '1' || b[b.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '0');
				on = 1;
			}
			else
			{
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
	else
	{
		if (on == 0)
			return c;
		c.insert(c.begin(), '1');
		return c;
	}
	//cout << "tam=" << tam << endl;
	for (int i = min; i < max; i++)
	{
		//std::cout << "i=" << i << " tam=" << tam[tam.size() - 1 - i] << " on=" << on << endl;
		if (on == 0)
		{
			if (tam[tam.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '1');
				on = 0;
			}
			else
			{
				c.insert(c.begin(), '0');
				on = 0;
			}
		}
		else
		{
			if (tam[tam.size() - 1 - i] == '1')
			{
				c.insert(c.begin(), '0');
				on = 1;
			}
			else
			{
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
/*int mySqrt(int x)
{
	int i = 1;
	while (true)
	{
		if (i * i > x)
			return i - 1;
		if (i * i == x)
			return i;
		i++;
	}
}*/

int main()
{
	std::vector<vector<int>> a{ {1, 4, 8, 6, 2, 2, 1, 7}, {4, 7, 3, 1, 4, 5, 5, 1}, {8, 8, 2, 1, 1, 8, 0, 1}, {8, 9, 2, 9, 8, 0, 8, 9}, {5, 7, 5, 7, 1, 8, 5, 5}, {7, 0, 9, 4, 5, 6, 5, 6}, {4, 9, 9, 7, 9, 1, 9, 0} };
	std::cout << "" << std::endl;
	return 0;
}
