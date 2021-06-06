enum Node {
    Content (i32),
    Next (Box<Node>),
}

impl Node {
    fn new(content: i32) -> Node {
        Node::Content = content;
    }

    Node
}

fn main() {
    let head = Node::new(1);
}
