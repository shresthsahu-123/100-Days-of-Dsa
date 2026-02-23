public class Solution {
    public void removeLoop(Node head) {
        
        if (head == null || head.next == null)
            return;

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        if (fast == null || fast.next == null)
            return;

        slow = head;

        if (slow == fast) {
            // Loop starts at head
            while (fast.next != slow)
                fast = fast.next;
        }
        else {
            while (slow.next != fast.next) {
                slow = slow.next;
                fast = fast.next;
            }
        }

        fast.next = null;
    }
}
