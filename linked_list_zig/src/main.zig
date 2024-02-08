const std = @import("std");

const Node = struct {
    x: i32,
    next: ?*Node = null,
};

pub fn add_last(head: *Node, x: i32) !void {
    const new_node = Node{
        .x = x,
        .next = head.next,
    };

    head.next = ?*const new_node;
}

pub fn display(head: *Node) !void {
    var node = head;
    while (true) {
        std.debug.print("{}\n", .{node.x});
        node = node.next orelse return;
    }
}
pub fn main() !void {
    var head = Node{ .x = 9, .next = null };
    try add_last(&head, 10);
    try add_last(&head, 11);
    try add_last(&head, 12);
    try add_last(&head, 13);

    try display(&head);
}
