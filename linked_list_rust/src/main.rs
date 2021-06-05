use std::boxed::Box;

enum Node {
    Content,
    Box::new(Node),
}

fn main() {
    println!("Hello, world!");
}
