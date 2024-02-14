const std = @import("std");

const Node = struct {
    x: i32,
    next: ?*Node = null,

};

pub fn new(x: i32) *Node {
    var node = Node {
        .x = x,
        .next = null,
    };

    return &node;
}

pub fn add_last(node: *Node, x: i32) void {
    var new_node = Node{
        .x = x,
        .next = null,
    };

    var c_node = node;

    while (c_node.next) |next| {
        c_node = next;
        std.debug.print("{d}", .{c_node.x});
    }
    c_node.next = &new_node;
}

pub fn display(node: *Node) void {
    var c_node = node;

    while (c_node.next) |next| {
        std.debug.print("{}\n", .{c_node.x});
        c_node = next;
    }
    std.debug.print("{}\n", .{c_node.x});
}

pub fn main() !void {
    var node = new(9);
    add_last(node, 10);
    add_last(node, 11);
    add_last(node, 12);
    add_last(node, 13);

    display(node);
}
