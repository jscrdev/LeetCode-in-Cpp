// #Medium #Top_100_Liked_Questions #Linked_List #Recursion #Data_Structure_II_Day_12_Linked_List
// #Udemy_Linked_List #Big_O_Time_O(n)_Space_O(1)
// #2024_05_24_Time_0_ms_(100.00%)_Space_9.5_MB_(45.59%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        int len = getLength(head);
        return reverse(head, len);
    }

private:
    int getLength(ListNode* curr) {
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    ListNode* reverse(ListNode* head, int len) {
        // base case
        if (len < 2) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for (int i = 0; i < 2; i++) {
            // reverse linked list code
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverse(curr, len - 2);
        return prev;
    }
};
