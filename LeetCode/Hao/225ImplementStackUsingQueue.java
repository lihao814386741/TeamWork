class MyStack {
    Queue<Integer> queue1 = new LinkedList<Integer>();
    Queue<Integer> queue2 = new LinkedList<Integer>();
    // Push element x onto stack.
    public void push(int x) {
        Queue<Integer> tmp;
        
        queue2.add(x);
        while (queue1.peek() != null) {
            queue2.offer(queue1.peek());
            queue1.poll();
        }
        tmp = queue1;
        queue1 = queue2;
        queue2 = tmp;
    }

    // Removes the element on top of the stack.
    public void pop() {
        queue1.poll();
    }

    // Get the top element.
    public int top() {
        return queue1.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return queue1.peek() == null;
    }
}
