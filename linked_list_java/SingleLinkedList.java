/**
 * Author: Chen Liang
 * Description: Implement single linked list in Java
 * Date 4th June 2021
 */

class Node {
    private int data;
    private Node next_node;

    public void setNodeValue(int i) {
        data = i;
    }

    public void setNextNode(Node node) {
        next_node = node;
    }
}

public class SingleLinkedList {
    private Node head;

    public SingleLinkedList() {
        head.setNodeValue(0);
    }

    public static void main() {

    }
}