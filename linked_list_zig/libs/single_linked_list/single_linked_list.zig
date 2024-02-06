const std = @import("std");

const Node = struct {
    x: i32,
    next: ?*Node = null,
};

pub fn add_last(head: *Node, x: i32) !void {
    var new_node = Node{
        .x = x,
        .next = null,
    };

    var node = head;
    while (true) {
        node = node.next orelse break;
    }

    node.next = &new_node;
}

pub fn display(head: *Node) !void {
    var node = head;
    while (true) {
        std.debug.print("{}\n", .{node.x});
        node = node.next orelse break;
    }
}
