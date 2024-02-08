const std = @import("std");

const Node = struct {
    x: i32,
    next: ?*Node = null,
};

pub fn add_last(head: *Node, x: i32) void {
    const new_node = Node{
        .x = x,
        .next = null,
    };

    // while (true) {
    //     head = head.next orelse return;
    // }
    head.next = &new_node;
}

pub fn display(head: *Node) void {
    var node = head;
    while (true) {
        std.debug.print("{}\n", .{node.x});
        node = node.next orelse return;
    }
}
pub fn main() !void {
    var head = Node{ .x = 9, .next = null };
    add_last(&head, 10);
    add_last(&head, 11);
    add_last(&head, 12);
    add_last(&head, 13);

    display(&head);
}
