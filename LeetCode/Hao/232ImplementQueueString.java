class MyQueue {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    // Push element x to the back of queue.
    public void push(int x) {
        stack1.push(x);    
    }

    // Removes the element from in front of queue.
    public void pop() {
        if (stack2.empty() == true) {
            while (stack1.empty() == false) {
                stack2.push(stack1.pop());
            }
        }
        stack2.pop();
        
    }

    // Get the front element.
    public int peek() {
        if (stack2.empty() == true) {
            while (stack1.empty() == false) {
                stack2.push(stack1.pop());
            }
        }
        
        return stack2.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stack1.empty() == true && stack2.empty() == true;
    }
}
