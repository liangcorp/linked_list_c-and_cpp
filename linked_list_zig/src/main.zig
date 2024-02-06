const std = @import("std");
const Node = @import("single_linked_list").Node;
const add_last = @import("single_linked_list").add_last;
const display = @import("single_linked_list").display;

pub fn main() !void {
    var head = Node{ .x = 9, .next = null };
    try add_last(&head, 10);
    try add_last(&head, 11);
    try add_last(&head, 12);
    try add_last(&head, 13);

    try display(&head);
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
