也算是临时抱佛脚了吧，3月之前刷了lintcode100多道题吧，后来发文章什么的就放下了，最近秋招在即在牛客网上想着把剑指offer这本书刷完，尽量早刷完吧，最近也很忙。
### 1. 二维数组中查找数字。
* **题目：**在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
* **思路：**从右上角来入手，如果右上角的数字大于目标，那么最右边一列都不满足，则去掉这一列，如果这个数小于目标，则最上面一行都不满足，删除这一行，如果刚好是目标就可以输出了。(这里的删除也不是真的去删掉，只需要挪动记录右上角的坐标数值就可以了)。

```
bool Find(int target, vector<vector<int> > array) {
        if(array.empty())    return false;
        int rows=array.size();
        int cols=array[0].size();
        int row=0;
        int col=cols-1;
        while(row<rows&&col>=0)
        {
            if(array[row][col]==target)  return true;
            else if(array[row][col]>target)
            {
                col--;
            }
            else  row++;
        }
        return false;
    }
```
### 2.替换空格。
* **题目：**请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
* **思路:**从后向前替换，先遍历一遍统计空格的数目，然后扩张字符串使得可以放下替换后的字符，然后从后向前依次复制，非空格字符直接复制，空格字符用题目要求的替换。
```
 //C风格的字符串最后一个字符是\n，而且是记在字符串长度里的。
	void replaceSpace(char *str,int length) {
        int i=0;
        int cnt=0;
        
        if(length==0||str==nullptr) return ;     //空字符串
        
        for(i=0;i<length;i++)      //统计空格数
        {
            if(str[i]==' ')
                cnt++;
        }
        if(cnt==0)  return;     //如果没有空格自然不用替换
        
        int newlength=length+2*cnt;     //新字符串的长度 
        
        int index_new=newlength-1;
        int index_old=length-1;
        
        while(index_old>=0&&index_new>index_old)   //没有到头或者两个指针追上了
        {
            if(str[index_old]==' ')
            {
                //依次替换三个字符，并且把index_old--
                str[index_new--]='0';
                str[index_new--]='2';
                str[index_new--]='%';    
                index_old--;
            }
            else 
            {
                //如果不是空格直接复制就可以了
                str[index_new--]=str[index_old--];
            }
        }

	}
```
### 3. 从尾到头打印链表。
* **题目：**输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
* **思路：**使用栈。
```
vector<int> printListFromTailToHead(ListNode* head) {
        if(head==nullptr)
            return vector<int>();
        stack<int> tmp_stack;
        vector<int> res;
        ListNode *phead=head;   //如果要求不改变原链表，这里换一下
        while(phead!=nullptr)
        {
            tmp_stack.push(phead->val);
            phead=phead->next;
        }
        while(!tmp_stack.empty())
        {
            res.push_back(tmp_stack.top());
            tmp_stack.pop();   //出栈
        }
        return res;
    }
```
### 4.重建二叉树
* **题目：**输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
* **思路：**
必须注意到前序遍历的第一个节点是根节点，中序遍历的和根节点相同的那个节点（不含重复节点）是根节点且把树分成左右两个子树，左边子树是左子树，右边是右子树，左右两个子树也都是同样的规律，所以可以用递归来做，我递归写的不好，借鉴了别人的思路，自己改进了下。
```
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
必须注意到前序遍历的第一个节点是根节点，中序遍历的和根节点相同的那个节点（不含重复节点）是根节点且
把树分成左右两个子树，左边子树是左子树，右边是右子树，左右两个子树也都是同样的规律，所以可以用递归
来做，我递归写的不好，借鉴了别人的思路，自己改进了下。
*/


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //如果size为0，则返回为空
        if(pre.size()==0||vin.size()==0)
            return NULL;
        
        vector<int> pre_left,pre_right;    //前序遍历的左子树和右子树
        vector<int> vin_left,vin_right;   //中序遍历的左子树和右子树
        //根据前序遍历的首节点为根节点这一个规律，找到中心节点，然后把原来的分成两个子二叉树，
        //准备使用递归来做。
        TreeNode *head=new TreeNode(pre[0]);   //调用构造函数先把第一个放进去。
        
        //找首节点在中序遍历中的位置。
        auto head_position=find(vin.begin(),vin.end(),head->val);
        int position=head_position-vin.begin();   //这里找到是第几个，下面取构建。
        pre_left=vector<int>(pre.begin()+1,pre.begin()+position+1);
        pre_right=vector<int>(pre.begin()+position+1,pre.end());
        //复制到前序遍历的左子树和右子树
        vin_left=vector<int>(vin.begin(),vin.begin()+position);
        vin_right=vector<int>(vin.begin()+position+1,vin.end());
        //复制到中序遍历的左子树和右子树 
        
        //调用递归
        head->left=reConstructBinaryTree(pre_left,vin_left);
        head->right=reConstructBinaryTree(pre_right,vin_right);
        
        //返回树
        return head;

    }
};
```
### 5. 用两个栈实现一个队列。
* **题目：**用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
* **思路：**用一个栈来入栈，元素入栈的时候都从这里来入栈，如果要删除的话，则利用另外一个空栈来另一个的所有元素取出并压入空栈，然后出栈，每次出栈检查那个栈是否是空的，如果不是空的，直接出栈，空的话则从入栈的栈里出来。
语言描述起来有点麻烦，看图：

![](https://upload-images.jianshu.io/upload_images/5252065-a2d1fcc20ff159b8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        //题目要求返回删除的那个元素，C++satck的pop是不返回值得，而只是删除，所以就要自己来做了！
        int tmp;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            tmp=stack2.top();
            stack2.pop();
        }
        else 
        {
            tmp=stack2.top();
            stack2.pop();
        }
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

另外，可用两个队列来做一个栈。
**思路：** 队列的话因为队列都是先进先出，所以如果把一个队列的数字全部复制到另外一个队列的话顺序是没有变的，所以有必要借助两个队列么？ 自然是有必要的，虽然顺序没有变，但是我们可以在转移元素的时候把最后一个删除掉，也就是说入栈的时候挑非空的队列入栈，出栈的时候把非空的队列复制到空的中，复制过程中把最后一个元素删掉。

![](https://upload-images.jianshu.io/upload_images/5252065-7f9068d4ed803932.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
未完待续！！






